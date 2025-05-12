print("Week 7 - Experiment 4")
print("Amit Singhal | 11614802722")

# Saving a List to a File (Using pprint)
# Write a program to save a list to a file using the pprint module.

import pprint

filename = "output.txt"
my_list = ["apple", "banana", "cherry", "date"]

with open(filename, "w") as file:
    pprint.pprint(my_list, file)

print(f"List saved to {filename}")
