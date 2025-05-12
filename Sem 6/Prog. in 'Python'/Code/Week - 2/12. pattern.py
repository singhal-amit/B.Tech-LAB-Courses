print("Week 2 - Experiment 12")
print("Amit Singhal | 11614802722")

rows = int(input("Enter the number of rows: "))

for line in range(1, rows + 1):  # Start from 1 to avoid an empty first row
    # Print spaces
    for i in range(rows - line):
        print(" ", end=" ")

    # Print increasing numbers
    for j in range(1, line + 1):
        print(j, end=" ")

    # Print decreasing numbers
    for k in reversed(range(1, line)):
        print(k, end=" ")

    # Move to the next line after each row
    print()
