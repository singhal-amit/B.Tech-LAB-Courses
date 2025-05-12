print("Week 7 - Experiment 11")
print("Amit Singhal | 11614802722")

# Recursive File Search
# Write a program to search for a file in a directory and all its subdirectories using recursion.

import os

def search_file(directory, filename):
    for root, _, files in os.walk(directory):
        if filename in files:
            return os.path.join(root, filename)
    return "File not found"

directory = "."
filename = "target.txt"
print(search_file(directory, filename))
