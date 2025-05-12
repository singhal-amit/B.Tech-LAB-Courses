# Lists and arrays: Create a program that prompts the user for a list of numbers
# and then sorts them in ascending order.

print("Week 6 - Experiment 4")
print("Amit Singhal | 11614802722")

numbers = list(map(int, input("Enter numbers separated by spaces: ").split()))
numbers.sort()
print("Sorted numbers:", numbers)
