print("Week 7 - Experiment 15")
print("Amit Singhal | 11614802722")

# File Size Calculation
# Write a program that calculates and prints the size of a file using os.path and os module.

import os

filename = "sample.txt"

if os.path.exists(filename):
    size = os.path.getsize(filename)
    print(f"Size of {filename}: {size} bytes")
else:
    print(f"{filename} does not exist.")
