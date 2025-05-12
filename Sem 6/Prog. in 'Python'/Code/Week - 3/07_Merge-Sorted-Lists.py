print("Week 3 - Experiment 7")
print("Amit Singhal | 11614802722")

# Taking two lists as input from the user
list1 = list(map(int, input("Enter the first list of numbers separated by spaces: ").split()))
list2 = list(map(int, input("Enter the second list of numbers separated by spaces: ").split()))

# Merging and sorting the lists
merged_sorted_list = sorted(list1 + list2)

# Displaying the results
print(f"The first list is: {list1}")
print(f"The second list is: {list2}")
print(f"The merged and sorted list is: {merged_sorted_list}")
