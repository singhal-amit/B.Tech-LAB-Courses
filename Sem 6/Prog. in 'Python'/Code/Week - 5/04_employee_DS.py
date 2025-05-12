# Design an Employee class with attributes name, ID, and salary, and a method to give a percentage-based salary increment.

print("Week 5 - Experiment 4")
print("Amit Singhal | 11614802722")

class Employee:
    def __init__(self, name, emp_id, salary):
        self.name = name
        self.emp_id = emp_id
        self.salary = salary

    def give_increment(self, percentage):
        self.salary += self.salary * (percentage / 100)

    def display_employee(self):
        print(f"Employee: {self.name}, ID: {self.emp_id}, Salary: {self.salary}")

emp1 = Employee("Alice", "E123", 50000)
emp1.give_increment(10)
emp1.display_employee()
