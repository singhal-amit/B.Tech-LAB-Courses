# Loops: Create a program that calculates the factorial of a number entered by the user using a loop.

print("Week 6 - Experiment 3")
print("Amit Singhal | 11614802722")

num = int(input("Enter a number: "))
factorial = 1
for i in range(1, num + 1):
    factorial *= i
print(f"The factorial of {num} is {factorial}")
