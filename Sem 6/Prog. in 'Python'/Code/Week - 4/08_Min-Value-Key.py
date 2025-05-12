# Write a Python program to find the key with the maximum value in a dictionary.

dict={
    "pen": 5,
    "pencil": 10,
    "box": 15,
    "book": 20
}

print("Week 4 - Experiment 8")
print("Amit Singhal | 11614802722")

key=""
min=-1

for item in dict:
    if dict[item]>min:
        min=dict[item]
        key=item

print(f"The Key With Max. value Is {key} With Value {dict[key]}")
