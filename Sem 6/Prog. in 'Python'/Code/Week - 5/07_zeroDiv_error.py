# Write a Python program that handles ZeroDivisionError and prompts the user to enter a valid denominator.

print("Week 5 - Experiment 7")
print("Amit Singhal | 11614802722")

def divide_numbers():
    while True:
        try:
            num = float(input("Enter numerator: "))
            denom = float(input("Enter denominator: "))
            result = num / denom
            print(f"Result: {result}")
            break
        except ZeroDivisionError:
            print("Error: Denominator cannot be zero. Please enter a valid denominator.")

divide_numbers()
