import cv2
import os
import numpy as np

def resize_with_padding(image, output_size=(416, 416), padding_color=(0, 0, 0)):
    """
    Resize an image to the desired output size with padding to maintain aspect ratio.

    Parameters:
    - image: np.ndarray, the input image.
    - output_size: tuple, desired output size (width, height).
    - padding_color: tuple, color for padding (B, G, R).

    Returns:
    - padded_image: np.ndarray, the resized image with padding.
    """
    original_height, original_width = image.shape[:2]
    target_width, target_height = output_size

    # Calculate the scaling factor to maintain aspect ratio
    scaling_factor = min(target_width / original_width, target_height / original_height)
    new_width = int(original_width * scaling_factor)
    new_height = int(original_height * scaling_factor)

    # Resize the image
    resized_image = cv2.resize(image, (new_width, new_height), interpolation=cv2.INTER_LINEAR)

    # Calculate padding
    pad_width = target_width - new_width
    pad_height = target_height - new_height
    top = pad_height // 2
    bottom = pad_height - top
    left = pad_width // 2
    right = pad_width - left

    # Add padding
    padded_image = cv2.copyMakeBorder(
        resized_image,
        top,
        bottom,
        left,
        right,
        borderType=cv2.BORDER_CONSTANT,
        value=padding_color
    )

    return padded_image

def process_folder(input_folder, output_folder, output_size=(416, 416), padding_color=(0, 0, 0)):
    """
    Process all images in a folder, resizing them to a fixed size with padding.

    Parameters:
    - input_folder: str, path to the input folder containing images.
    - output_folder: str, path to save processed images.
    - output_size: tuple, target size for resized images.
    - padding_color: tuple, color for padding (B, G, R).
    """
    if not os.path.exists(input_folder):
        print("❌ Input folder does not exist. Please check the path.")
        return
    
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    image_extensions = (".jpg", ".jpeg", ".png", ".bmp", ".tiff")

    images_found = False

    for filename in os.listdir(input_folder):
        if filename.lower().endswith(image_extensions):
            images_found = True
            image_path = os.path.join(input_folder, filename)
            image = cv2.imread(image_path)

            if image is None:
                print(f"Skipping {filename}, unable to read.")
                continue

            resized_image = resize_with_padding(image, output_size, padding_color)

            # Save the processed image
            output_path = os.path.join(output_folder, filename)
            cv2.imwrite(output_path, resized_image)
            print(f"✅ Processed and saved: {output_path}")

    if not images_found:
        print("⚠️ No valid images found in the input folder.")

# Main function to run the script with user input
if __name__ == "__main__":
    print("📂 Image Resizing Script (YOLO Format)")
    
    # Get user input for folder paths
    input_folder = input("Enter the full path of the input folder: ").strip()
    output_folder = input("Enter the full path of the output folder: ").strip()

    # Run the processing function
    process_folder(input_folder, output_folder)

    print("🎉 All images processed successfully!")
