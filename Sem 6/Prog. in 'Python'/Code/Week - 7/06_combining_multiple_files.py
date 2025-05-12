print("Week 7 - Experiment 6")
print("Amit Singhal | 11614802722")

# Combining Multiple Files
# Write a program to combine the contents of two text files into one.

file1 = "sample.txt"
file2 = "output.txt"
output_file = "combined.txt"

with open(output_file, "w") as outfile:
    for fname in [file1, file2]:
        with open(fname, "r") as infile:
            outfile.write(infile.read() + "\n")

print(f"Contents of {file1} and {file2} combined into {output_file}")
