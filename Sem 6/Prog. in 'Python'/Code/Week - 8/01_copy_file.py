# Copy Files Using shutil
# Write a Python program that copies a file from one directory to another using the shutil module.

print("Week 8 - Experiment 1")
print("Amit Singhal | 11614802722")

import shutil

source = "example.txt"
destination = "backup/example_copy.txt"

shutil.copy(source, destination)
print(f"Copied {source} to {destination}")
