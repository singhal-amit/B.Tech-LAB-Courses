print("Week 2 - Experiment 3")
print("Amit Singhal | 11614802722")

num = int(input("Enter the number: "))

if num % 3 == 0 and num % 5 == 0:
    print(f"The number {num} is divisible by both 3 and 5.")
elif num % 3 == 0:
    print(f"The number {num} is divisible by 3.")
elif num % 5 == 0:
    print(f"The number {num} is divisible by 5.")
else:
    print(f"The number {num} is not divisible by 3 or 5.")
