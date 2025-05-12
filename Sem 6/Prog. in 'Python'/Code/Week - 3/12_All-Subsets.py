print("Week 3 - Experiment 12")
print("Amit Singhal | 11614802722")

def find_subsets(lst, index=0, current_subset=None, all_subsets=None):
    if current_subset is None:
        current_subset = []
    if all_subsets is None:
        all_subsets = []

    if index == len(lst):
        all_subsets.append(current_subset[:])
        return all_subsets

    # Include the current element
    current_subset.append(lst[index])
    find_subsets(lst, index + 1, current_subset, all_subsets)

    # Exclude the current element
    current_subset.pop()
    find_subsets(lst, index + 1, current_subset, all_subsets)

    return all_subsets

# Taking list input from the user
numbers = list(map(int, input("Enter a list of numbers separated by spaces: ").split()))

# Finding all subsets
subsets = find_subsets(numbers)

# Displaying the subsets
print(f"All subsets of the given list are: {subsets}")
