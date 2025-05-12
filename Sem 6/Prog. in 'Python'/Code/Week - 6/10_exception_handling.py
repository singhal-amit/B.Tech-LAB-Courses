# Exception handling: Create a program that prompts the user for two numbers
# and then divides them, handling any exceptions that may arise.

print("Week 6 - Experiment 10")
print("Amit Singhal | 11614802722")

try:
    num1 = float(input("Enter first number: "))
    num2 = float(input("Enter second number: "))
    result = num1 / num2
    print(f"Result: {result}")
except ZeroDivisionError:
    print("Error: Cannot divide by zero.")
except ValueError:
    print("Error: Invalid input. Please enter numerical values.")
