print("Week 7 - Experiment 5")
print("Amit Singhal | 11614802722")

# Reading a File Line by Line
# Write a program to read a file line by line and print each line.

filename = "sample.txt"
with open(filename, "r") as file:
    for line in file:
        print(line.strip())
