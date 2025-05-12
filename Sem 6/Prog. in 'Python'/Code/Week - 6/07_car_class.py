# Classes and objects: Create a program that defines a class to represent a car
# and then creates an object of that class with specific attributes.

print("Week 6 - Experiment 7")
print("Amit Singhal | 11614802722")

class Car:
    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year

    def display_info(self):
        print(f"Car: {self.year} {self.make} {self.model}")

car = Car("Toyota", "Camry", 2020)
car.display_info()
