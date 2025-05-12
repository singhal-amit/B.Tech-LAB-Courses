print("Week 3 - Experiment 8")
print("Amit Singhal | 11614802722")

# Taking a list as input from the user
numbers = list(map(int, input("Enter a list of numbers separated by spaces: ").split()))

# Sorting the list
numbers.sort()

# Finding the second largest element
for i in reversed(range(len(numbers))):
    if numbers[i] != numbers[i - 1]:
        print(f"The second largest number in the list is: {numbers[i - 1]}")
        break
