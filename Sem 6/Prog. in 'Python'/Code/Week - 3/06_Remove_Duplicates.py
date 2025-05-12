print("Week 3 - Experiment 6")
print("Amit Singhal | 11614802722")

numbers = list(map(int, input("Enter numbers separated by spaces: ").split()))

unique_numbers = []
for num in numbers:
    if num not in unique_numbers:
        unique_numbers.append(num)

print(f"The list with unique elements is: {unique_numbers}")
