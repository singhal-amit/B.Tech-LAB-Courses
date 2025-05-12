print("Week 7 - Experiment 3")
print("Amit Singhal | 11614802722")

# Checking if a File Exists
# Write a program to check if a file exists.

import os

filename = "sample.txt"
if os.path.exists(filename):
    print(f"{filename} exists.")
else:
    print(f"{filename} does not exist.")
