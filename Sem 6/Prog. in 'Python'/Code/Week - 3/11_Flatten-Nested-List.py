print("Week 3 - Experiment 11")
print("Amit Singhal | 11614802722")

def flatten_list(nested_list):
    flattened = []
    for item in nested_list:
        if isinstance(item, list):
            flattened.extend(flatten_list(item))
        else:
            flattened.append(item)
    return flattened

# Taking nested list input from the user
import ast
nested_list = ast.literal_eval(input("Enter a nested list: "))

# Flattening the list
flattened_list = flatten_list(nested_list)

# Displaying the flattened list
print(f"The flattened list is: {flattened_list}")
