print("Week 7 - Experiment 7")
print("Amit Singhal | 11614802722")

# Finding the File Path
# Write a program that finds the absolute file path using os.path.

import os

filename = "sample.txt"
abs_path = os.path.abspath(filename)
print(f"Absolute path of {filename}: {abs_path}")
