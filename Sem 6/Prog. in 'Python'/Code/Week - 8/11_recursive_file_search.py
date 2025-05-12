# Recursive File Search Using os.walk()
# Write a program to recursively search for a file in a directory and all its subdirectories using recursion.

print("Week 8 - Experiment 11")
print("Amit Singhal | 11614802722")

import os

def find_file(target, path="."):
    for root, dirs, files in os.walk(path):
        if target in files:
            return os.path.join(root, target)
    return "File not found."

print(find_file("target.txt"))
