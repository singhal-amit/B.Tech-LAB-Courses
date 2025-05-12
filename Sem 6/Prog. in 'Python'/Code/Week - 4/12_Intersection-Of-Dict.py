# Write a Python program to find the intersection of two dictionaries (common keys with the same values).

dict1={
    "a": 5,
    "b": 7,
    "c": 10,
    "d": 116
}

dict2={
    "a": 1,
    "b": 7,
    "c": 12,
    "d": 116
}

ans={}

print("Week 4 - Experiment 12")
print("Amit Singhal | 11614802722")

for item in dict1:
    if item in dict2 and dict1[item] == dict2[item]:
        ans[item] = dict1[item]

print(ans)
