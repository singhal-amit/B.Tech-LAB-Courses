# Develop a Student class with attributes name and marks (list).
# Implement methods to calculate the average marks and format the output using pretty printing.
# Handle ValueError if marks contain invalid data.

print("Week 5 - Experiment 11")
print("Amit Singhal | 11614802722")

import pprint

class Student:
    def __init__(self, name, marks):
        if not all(isinstance(mark, (int, float)) and 0 <= mark <= 100 for mark in marks):
            raise ValueError("Marks should be numbers between 0 and 100.")
        self.name = name
        self.marks = marks

    def average_marks(self):
        return sum(self.marks) / len(self.marks)

    def display(self):
        return {"Name": self.name, "Marks": self.marks, "Average": self.average_marks()}

students = [
    Student("Alice", [85, 90, 88]),
    Student("Bob", [78, 80, 82]),
    Student("Charlie", [92, 95, 98])
]

pprint.pprint([s.display() for s in students])
