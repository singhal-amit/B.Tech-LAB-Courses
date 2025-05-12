print("Week 7 - Experiment 2")
print("Amit Singhal | 11614802722")

# Writing to a File
# Write a program to write content to a file.

filename = "output.txt"
content = "Hello, this is a test file content."

with open(filename, "w") as file:
    file.write(content)

print(f"Content written to {filename}")
