from collections import defaultdict
from pprint import pprint

def group_by_key(data, key):
    grouped_data = defaultdict(list)
    for item in data:
        grouped_data[item[key]].append(item)
    return dict(grouped_data)

print("Week 4 - Experiment 14")
print("Amit Singhal | 11614802722\n")

data = [
    {'name': 'amit', 'age': 21},
    {'name': 'shaswat', 'age': 18},
    {'name': 'amit', 'age': 25},
    {'name': 'lakshya', 'age': 21}
]

# Grouping by 'name'
grouped_by_name = group_by_key(data, 'name')
print("Grouped by name:")
pprint(grouped_by_name)

# Grouping by 'age'
grouped_by_age = group_by_key(data, 'age')
print("\nGrouped by age:")
pprint(grouped_by_age)
