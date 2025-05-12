print("Week 2 - Experiment 2")
print("Amit Singhal | 11614802722")

def setGrade(marks):
    if marks >= 90:
        return "A"
    elif marks >= 80:
        return "B"
    elif marks >= 60:
        return "C"
    elif marks >= 45:
        return "D"
    elif marks >= 30:
        return "E"
    else:
        return "F - FAIL"

marks = float(input("Enter student's marks (0-100): "))

if 0 <= marks <= 100:
    grade = setGrade(marks)
    print(f"Assigned Grade: {grade}")
else:
    print("Error: Marks should be between 0 and 100.")
