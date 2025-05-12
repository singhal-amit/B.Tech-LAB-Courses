# Implement a function that opens a file and handles FileNotFoundError if the file does not exist.

print("Week 5 - Experiment 8")
print("Amit Singhal | 11614802722")

def read_file(filename):
    try:
        with open(filename, 'r') as file:
            content = file.read()
            print(content)
    except FileNotFoundError:
        print(f"Error: The file '{filename}' was not found.")

read_file("sample.txt")
