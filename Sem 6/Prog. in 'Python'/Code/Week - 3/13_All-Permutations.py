print("Week 3 - Experiment 13")
print("Amit Singhal | 11614802722")

def generate_permutations(lst, start=0):
    if start == len(lst) - 1:
        print(lst)
        return

    for i in range(start, len(lst)):
        lst[start], lst[i] = lst[i], lst[start]  # Swap
        generate_permutations(lst, start + 1)
        lst[start], lst[i] = lst[i], lst[start]  # Swap back to original

# Taking list input from the user
numbers = list(map(int, input("Enter a list of numbers separated by spaces: ").split()))

# Generating and displaying all permutations
print("All permutations of the given list are:")
generate_permutations(numbers)
