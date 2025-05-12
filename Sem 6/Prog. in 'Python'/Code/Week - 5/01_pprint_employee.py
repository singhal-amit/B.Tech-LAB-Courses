# Write a Python program to pretty-print a list of dictionaries containing employee details (name, age, department).

print("Week 5 - Experiment 1")
print("Amit Singhal | 11614802722")

import pprint

employees = [
    {"name": "Alice", "age": 30, "department": "HR"},
    {"name": "Bob", "age": 25, "department": "IT"},
    {"name": "Charlie", "age": 28, "department": "Finance"}
]

pprint.pprint(employees)
