print("Week 3 - Experiment 15")
print("Amit Singhal | 11614802722")

def partition_list(lst, size):
    return [lst[i:i + size] for i in range(0, len(lst), size)]

# Taking list input from the user
numbers = list(map(int, input("Enter a list of numbers separated by spaces: ").split()))

# Taking the partition size input
partition_size = int(input("Enter the size of each sublist: "))

# Partitioning the list
partitioned_list = partition_list(numbers, partition_size)

# Displaying the result
print(f"The partitioned list is: {partitioned_list}")
