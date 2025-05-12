# Compress All Files in a Directory into One ZIP File
# Compress all .txt files in a directory into one .zip archive using the zipfile module.

print("Week 8 - Experiment 7")
print("Amit Singhal | 11614802722")

import os
import zipfile

zipf = zipfile.ZipFile("texts.zip", "w")

for root, _, files in os.walk("."):
    for file in files:
        if file.endswith(".txt"):
            zipf.write(os.path.join(root, file))
zipf.close()
print("All .txt files compressed into texts.zip")
