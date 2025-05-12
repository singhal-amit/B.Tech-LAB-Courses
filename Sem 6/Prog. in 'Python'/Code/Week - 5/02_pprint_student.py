# Format and pretty-print a table displaying student names and marks using string formatting.

print("Week 5 - Experiment 2")
print("Amit Singhal | 11614802722")

students = [
    {"name": "Alice", "marks": 85},
    {"name": "Bob", "marks": 78},
    {"name": "Charlie", "marks": 92}
]

print(f"{'Name':<10}{'Marks':<10}")
print("-" * 20)

for student in students:
    print(f"{student['name']:<10}{student['marks']:<10}")
