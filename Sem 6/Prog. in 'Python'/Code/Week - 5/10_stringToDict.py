# Implement a function that takes a string as input, stores each unique character as a key in a dictionary
# with its frequency as the value, and pretty-prints the dictionary. Handle TypeError if input is not a string.

print("Week 5 - Experiment 10")
print("Amit Singhal | 11614802722")

import pprint

def char_frequency(text):
    if not isinstance(text, str):
        raise TypeError("Input must be a string.")

    freq_dict = {}
    for char in text:
        freq_dict[char] = freq_dict.get(char, 0) + 1

    pprint.pprint(freq_dict)

char_frequency("hello world")
