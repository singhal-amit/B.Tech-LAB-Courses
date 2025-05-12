# Create a Car class with attributes brand, model, and year. Implement a method to display car details.

print("Week 5 - Experiment 3")
print("Amit Singhal | 11614802722")

class Car:
    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year

    def display_details(self):
        print(f"Car: {self.brand} {self.model}, Year: {self.year}")

car1 = Car("Toyota", "Corolla", 2020)
car1.display_details()
