# Compress Files into a ZIP Archive
# Write a Python script that compresses multiple files into a .zip archive using the zipfile module.

print("Week 8 - Experiment 2")
print("Amit Singhal | 11614802722")

import zipfile

files = ["file1.txt", "file2.txt"]
zip_name = "archive.zip"

with zipfile.ZipFile(zip_name, "w") as zipf:
    for file in files:
        zipf.write(file)
print(f"Files compressed into {zip_name}")
