# Batch Compression of Files in Multiple Directories
# Write a Python program to compress all .txt files from multiple directories into separate .zip archives.

print("Week 8 - Experiment 15")
print("Amit Singhal | 11614802722")

import os
import zipfile

for root, dirs, files in os.walk("."):
    txt_files = [f for f in files if f.endswith(".txt")]
    if txt_files:
        zip_name = os.path.basename(root) + "_archive.zip"
        with zipfile.ZipFile(zip_name, "w") as zipf:
            for f in txt_files:
                zipf.write(os.path.join(root, f))
        print(f"Created archive: {zip_name}")
