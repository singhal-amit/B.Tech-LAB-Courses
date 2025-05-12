# Write a Python program to implement a nested dictionary where each key
# contains another dictionary, and retrieve specific values dynamically.

def create_nested_dict():
    return {
        'amit': {'age': 21, 'city': 'roorkee'},
        'shaswat': {'age': 25, 'city': 'bihari'},
        'yash': {'age': 19, 'city': 'delhite'}
    }

def get_value(nested_dict, key, sub_key):
    return nested_dict.get(key, {}).get(sub_key, 'Key not found')

print("Week 4 - Experiment 15")
print("Amit Singhal | 11614802722")

nested_dict = create_nested_dict()

print("amit's age:", get_value(nested_dict, 'amit', 'age'))
print("shaswat's city:", get_value(nested_dict, 'shaswat', 'city'))
print("yash's city:", get_value(nested_dict, 'yash', 'city'))
