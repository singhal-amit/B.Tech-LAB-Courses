# Functions: Create a program that defines a function to calculate the area of a circle
# based on the radius entered by the user.

print("Week 6 - Experiment 6")
print("Amit Singhal | 11614802722")

import math

def circle_area(radius):
    return math.pi * radius ** 2

radius = float(input("Enter the radius of the circle: "))
print(f"The area of the circle is {circle_area(radius):.2f}")
