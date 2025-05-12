print("Week 7 - Experiment 8")
print("Amit Singhal | 11614802722")

# Writing a Dictionary to a File (Using shelve Module)
# Write a program to save a dictionary using the shelve module and then read it back.

import shelve

filename = "mydata"

with shelve.open(filename) as db:
    db["person"] = {"name": "Alice", "age": 30, "city": "New York"}

with shelve.open(filename) as db:
    print("Stored Data:", db["person"])
