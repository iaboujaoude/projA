import os
import cv2
import albumentations as A
import numpy as np
from tqdm import tqdm

# Ask user for dataset directory
dataset_dir = input("Enter the dataset directory name: ").strip()

# Check if the dataset directory exists
if not os.path.exists(dataset_dir):
    print(f"❌ Error: The dataset directory '{dataset_dir}' does not exist.")
    exit()

# Define output directory
output_dir = dataset_dir + "_augmented"
os.makedirs(output_dir, exist_ok=True)

# Albumentations Augmentation Pipeline
augmentation = A.Compose([
    A.HorizontalFlip(p=0.5),
    A.Rotate(limit=30, p=0.5),
    A.RandomBrightnessContrast(p=0.3),
    A.GaussianBlur(blur_limit=(3, 7), p=0.2),
    A.HueSaturationValue(hue_shift_limit=15, sat_shift_limit=20, val_shift_limit=15, p=0.3),
    A.RandomResizedCrop(size=(416, 416), scale=(0.8, 1.0), ratio=(0.75, 1.33), p=0.3)
])

# Load images directly from the dataset folder
images = [img for img in os.listdir(dataset_dir) if img.lower().endswith((".jpg", ".png", ".jpeg"))]

if len(images) == 0:
    print(f"⚠️ No images found in {dataset_dir}, exiting...")
    exit()

print(f"📂 Processing dataset '{dataset_dir}': Found {len(images)} images.")

for img_name in tqdm(images):
    img_path = os.path.join(dataset_dir, img_name)
    image = cv2.imread(img_path)

    if image is None:
        print(f"❌ Skipping corrupted or unreadable image: {img_path}")
        continue

    # Print image shape to confirm it was read correctly
    print(f"🔹 Original Image Loaded: {img_path}, Shape: {image.shape}")

    # Save original image to output directory
    cv2.imwrite(os.path.join(output_dir, img_name), image)

    # Generate 2 augmented versions per image
    for i in range(2):
        augmented = augmentation(image=image)["image"]

        if isinstance(augmented, np.ndarray) and augmented.shape == (416, 416, 3):
            aug_img_name = f"{os.path.splitext(img_name)[0]}_aug{i+1}.jpg"
            aug_img_path = os.path.join(output_dir, aug_img_name)

            # Save augmented image
            cv2.imwrite(aug_img_path, augmented)
            print(f"✅ Augmented image saved: {aug_img_path}")
        else:
            print(f"❌ Augmentation failed for {img_path}. Output shape: {augmented.shape if isinstance(augmented, np.ndarray) else 'None'}")

print(f"\n✅ Dataset augmentation completed. New dataset saved in: {output_dir}")
