print("Week 7 - Experiment 9")
print("Amit Singhal | 11614802722")

# Renaming a File
# Write a program that renames a file using the os module.

import os

old_name = "sample.txt"
new_name = "input.txt"

if os.path.exists(old_name):
    os.rename(old_name, new_name)
    print(f"Renamed {old_name} to {new_name}")
else:
    print(f"{old_name} does not exist.")
