print("Week 2 - Experiment 8")
print("Amit Singhal | 11614802722")

num = int(input("Enter a natural number: "))
print(f"Even numbers up to {num}:")
for i in range(0, num + 1, 2):  # Step by 2 for even numbers
    print(i, end=" ")
