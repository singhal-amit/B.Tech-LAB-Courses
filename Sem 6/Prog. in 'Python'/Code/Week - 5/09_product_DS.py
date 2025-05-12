# Create a Product class with attributes name, price, and quantity.
# Handle exceptions when setting price (must be positive) and use pretty printing to display multiple products.

print("Week 5 - Experiment 9")
print("Amit Singhal | 11614802722")

import pprint

class Product:
    def __init__(self, name, price, quantity):
        if price <= 0:
            raise ValueError("Price must be positive.")
        self.name = name
        self.price = price
        self.quantity = quantity

    def display(self):
        return {"Name": self.name, "Price": self.price, "Quantity": self.quantity}

products = [
    Product("Laptop", 50000, 2),
    Product("Mouse", 1500, 5),
    Product("Keyboard", 2500, 3)
]

pprint.pprint([p.display() for p in products])
