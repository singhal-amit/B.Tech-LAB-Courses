# Write a Python program to sort a dictionary by its values in ascending and descending order.

def sort_dict_by_value(d, ascending=True):
    return dict(sorted(d.items(), key=lambda item: item[1], reverse=not ascending))

print("Week 4 - Experiment 11")
print("Amit Singhal | 11614802722")

data = {'a': 3, 'b': 1, 'c': 5, 'd': 2}

# Sorting in ascending order
ascending_sorted = sort_dict_by_value(data, ascending=True)
print("Ascending order:", ascending_sorted)

# Sorting in descending order
descending_sorted = sort_dict_by_value(data, ascending=False)
print("Descending order:", descending_sorted)
