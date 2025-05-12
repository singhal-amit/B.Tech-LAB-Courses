# Regular expressions: Create a program that uses regular expressions
# to find all instances of a specific pattern in a text file.

print("Week 6 - Experiment 9")
print("Amit Singhal | 11614802722")

import re

pattern = input("Enter the pattern to search for: ")
with open("sample.txt", "r") as file:
    content = file.read()

# Find words that contain the pattern
matches = set()
for word in content.split():
    if re.search(pattern, word):
        matches.add(word)

print(f"Found {len(matches)} words containing the pattern: {matches}")
