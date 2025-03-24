import requests
import time
from pynput import keyboard

# Airtable API credentials
AIRTABLE_API_KEY = "patBbpDlEyRz6x61D.808a9bc80a3049deb00565ac16ce50052b1ddea7eb97f5e60ba91ac5ea9f2722"
AIRTABLE_BASE_ID = "appoPPSGGY0Bgjwle"
AIRTABLE_TABLE_NAME = "Bot"
AIRTABLE_URL = f"https://api.airtable.com/v0/{AIRTABLE_BASE_ID}/{AIRTABLE_TABLE_NAME}"
HEADERS = {"Authorization": f"Bearer {AIRTABLE_API_KEY}", "Content-Type": "application/json"}

# Key mapping for movement
KEY_TO_MODE = {
    "w": "W",  # Move Forward
    "s": "S",  # Move Backward
    "a": "A",  # Rotate Left
    "d": "D"   # Rotate Right
}

current_mode = None

def fetch_airtable_record():
    """Fetch the first record ID from Airtable for updating Mode."""
    try:
        response = requests.get(AIRTABLE_URL, headers=HEADERS)
        if response.status_code == 200:
            data = response.json()
            if "records" in data and data["records"]:
                return data["records"][0]["id"]
        print("[ERROR] No records found in Airtable!")
    except Exception as e:
        print(f"[ERROR] Failed to fetch Airtable record: {e}")
    return None

def update_airtable_mode(mode):
    """Send an update to Airtable to set the Mode column to the given mode."""
    global current_mode
    if mode == current_mode:
        return  # Avoid duplicate updates

    record_id = fetch_airtable_record()
    if not record_id:
        return

    try:
        update_payload = {"fields": {"Mode": mode}}
        response = requests.patch(f"{AIRTABLE_URL}/{record_id}", headers=HEADERS, json=update_payload)
        if response.status_code == 200:
            print(f"[INFO] Updated Airtable Mode to: {mode}")
            current_mode = mode
        else:
            print(f"[ERROR] Failed to update Airtable Mode. Status Code: {response.status_code}")
    except Exception as e:
        print(f"[ERROR] Failed to update Airtable: {e}")

def on_press(key):
    """Detect key presses and update Airtable."""
    try:
        key_char = key.char.lower()
        if key_char in KEY_TO_MODE:
            update_airtable_mode(KEY_TO_MODE[key_char])
    except AttributeError:
        pass  # Ignore special keys

def on_release(key):
    """Detect key release and stop the robot."""
    update_airtable_mode("Stop")

def main():
    """Start listening for keyboard events."""
    print("[START] Keyboard control started. Press W/A/S/D to move. Release key to stop.")
    with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
        listener.join()

if __name__ == "__main__":
    main()
