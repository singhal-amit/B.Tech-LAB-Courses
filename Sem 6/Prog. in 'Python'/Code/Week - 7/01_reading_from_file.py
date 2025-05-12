print("Week 7 - Experiment 1")
print("Amit Singhal | 11614802722")

# Reading a File and Displaying Content
# Write a program to read a file and display its content.

filename = "sample.txt"
with open(filename, "r") as file:
    content = file.read()
print("File Content:\n", content)
