# Appends Data to an Existing ZIP File
# Write a Python script to append new files to an existing .zip archive using the zipfile module.

print("Week 8 - Experiment 13")
print("Amit Singhal | 11614802722")

import zipfile

with zipfile.ZipFile("texts.zip", "a") as zipf:
    zipf.write("new_file.txt")
print("Appended new_file.txt to texts.zip")
