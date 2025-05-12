print("Week 2 - Experiment 4")
print("Amit Singhal | 11614802722")

print("Enter the sides of the triangle:")
a = int(input("Side 'a': "))
b = int(input("Side 'b': "))
c = int(input("Side 'c': "))

if a == b == c:
    print("The triangle is Equilateral.")
elif a == b or b == c or a == c:
    print("The triangle is Isosceles.")
else:
    print("The triangle is Scalene.")
