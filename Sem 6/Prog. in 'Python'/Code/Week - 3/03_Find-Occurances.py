print("Week 3 - Experiment 3")
print("Amit Singhal | 11614802722")

import numpy as np

numbers = [12, 15, 22, 18, 25, 30, 15, 40, 50, 15, 60, 15, 75, 80, 90]
print(f"The list of numbers is: {numbers}")

element = int(input("Enter the number to count: "))
occurrences = numbers.count(element)

print(f"The number {element} appears {occurrences} times in the list.")
