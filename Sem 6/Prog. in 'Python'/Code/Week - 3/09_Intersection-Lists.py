print("Week 3 - Experiment 9")
print("Amit Singhal | 11614802722")

# Taking two lists as input from the user
list1 = list(map(int, input("Enter the first list of numbers separated by spaces: ").split()))
list2 = list(map(int, input("Enter the second list of numbers separated by spaces: ").split()))

# Finding common elements
common_elements = [num for num in list1 if num in list2]

print(f"The common elements between both lists are: {common_elements}")
