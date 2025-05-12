# Copy Files and Directories Using shutil
# Write a Python program to copy an entire directory along with its files to another location using shutil.

print("Week 8 - Experiment 12")
print("Amit Singhal | 11614802722")

import shutil

src = "Project"
dst = "Project_Backup"

shutil.copytree(src, dst, dirs_exist_ok=True)
print(f"Copied entire directory {src} to {dst}")
