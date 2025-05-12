# File input/output: Create a program that reads data from a file
# and writes it to another file in a different format.

print("Week 6 - Experiment 8")
print("Amit Singhal | 11614802722")

input_file = "input.txt"
output_file = "output.txt"

with open(input_file, "r") as infile:
    data = infile.read()

with open(output_file, "w") as outfile:
    outfile.write(data.upper())

print(f"Data has been read from {input_file} and written to {output_file} in uppercase.")
