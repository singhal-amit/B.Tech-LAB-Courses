print("Week 7 - Experiment 13")
print("Amit Singhal | 11614802722")

# Appending Data to a File Using os.path
# Write a program that appends data to a file and checks if the file exists using os.path.

import os

filename = "sample.txt"
data = "\nAppended text."

if os.path.exists(filename):
    with open(filename, "a") as file:
        file.write(data)
    print(f"Data appended to {filename}")
else:
    print(f"{filename} does not exist.")
