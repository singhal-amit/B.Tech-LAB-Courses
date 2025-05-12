print("Week 7 - Experiment 12")
print("Amit Singhal | 11614802722")

# Copying Files and Directories
# Write a program that copies a file from one location to another, including directories.

import shutil

source = "sample.txt"
destination = "demo/copy.txt"

shutil.copy(source, destination)
print(f"Copied {source} to {destination}")
