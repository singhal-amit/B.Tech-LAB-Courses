# Write a Python program to merge two dictionaries into one.

dict1={
    "name": "Amit",
    "age": 21,
    "city": "New Delhi"
}

dict2={
    "CGPA":9.03,
    "Branch": "CSE",
    "University": "MAIT"
}

print("Week 4 - Experiment 6")
print("Amit Singhal | 11614802722")

# Merging two dictionaries into one
for key in dict2:
    if key not in dict1:
        dict1.update({key:dict2[key]})

print(dict1)
