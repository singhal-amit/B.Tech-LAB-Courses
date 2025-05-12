# Find and List All .txt Files in a Directory
# Walk through a directory and list all .txt files using os.walk().

print("Week 8 - Experiment 5")
print("Amit Singhal | 11614802722")

import os

for root, dirs, files in os.walk("."):
    for file in files:
        if file.endswith(".txt"):
            print("Text file found:", os.path.join(root, file))
