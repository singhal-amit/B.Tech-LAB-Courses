# Display Directory Tree Using os.walk()
# Write a program to display the directory structure using os.walk().

print("Week 8 - Experiment 3")
print("Amit Singhal | 11614802722")

import os

for root, dirs, files in os.walk("."):
    print("Directory:", root)
    for file in files:
        print("  File:", file)
