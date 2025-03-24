import os
from collections import Counter
from PIL import Image

def get_image_resolutions(directory):
    resolution_counts = Counter()
    
    for filename in os.listdir(directory):
        file_path = os.path.join(directory, filename)
        
        try:
            with Image.open(file_path) as img:
                resolution = img.size  # (width, height)
                resolution_counts[resolution] += 1
        except Exception as e:
            print(f"Skipping {filename}: {e}")
    
    return resolution_counts

def main():
    directory = input("Enter the directory containing images: ")
    if not os.path.isdir(directory):
        print("Invalid directory.")
        return
    
    resolutions = get_image_resolutions(directory)
    
    print("\nImage Resolution Statistics:")
    for resolution in sorted(resolutions.keys()):
        print(f"{resolution}: {resolutions[resolution]} images")

if __name__ == "__main__":
    main()
