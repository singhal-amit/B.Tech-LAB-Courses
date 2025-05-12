print("Week 7 - Experiment 14")
print("Amit Singhal | 11614802722")

# Serialization and Deserialization with shelve
# Write a program to serialize and deserialize objects using the shelve module.

import shelve

filename = "data_shelve"

with shelve.open(filename) as db:
    db["fruits"] = ["apple", "banana", "cherry"]

with shelve.open(filename) as db:
    print("Stored Fruits:", db["fruits"])
