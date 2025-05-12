print("Week 7 - Experiment 10")
print("Amit Singhal | 11614802722")

# Reading and Writing CSV Files
# Write a program to read from and write to a CSV file using Python's csv module.

import csv

filename = "data.csv"

# Writing to CSV
data = [["Name", "Age", "City"], ["Alice", 30, "New York"], ["Bob", 25, "Los Angeles"]]

with open(filename, "w", newline="") as file:
    writer = csv.writer(file)
    writer.writerows(data)

# Reading from CSV
with open(filename, "r") as file:
    reader = csv.reader(file)
    for row in reader:
        print(row)
