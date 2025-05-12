# Create a Directory Tree and Write Files Using os and shutil
# Write a Python program that creates a directory structure and writes a few files into the directories using os and shutil.

print("Week 8 - Experiment 8")
print("Amit Singhal | 11614802722")

import os

os.makedirs("Project/Data", exist_ok=True)
with open("Project/Data/info.txt", "w") as f:
    f.write("This is some sample text.")
print("Directory structure and file created.")
