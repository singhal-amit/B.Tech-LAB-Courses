print("Week 3 - Experiment 10")
print("Amit Singhal | 11614802722")

# Taking a list as input from the user
numbers = list(map(int, input("Enter a list of numbers separated by spaces: ").split()))

# Taking the number of positions to rotate
rotate_by = int(input("Enter the number of positions to rotate by: "))

# Rotating the list
rotated_list = numbers[rotate_by:] + numbers[:rotate_by]

# Displaying the rotated list
print(f"The rotated list is: {rotated_list}")
