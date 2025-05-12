# Write a Python program to convert two lists into a dictionary (one as keys, the other as values).

list1=["name","age","city"]
list2=["amit","21","hello_world"]

print("Week 4 - Experiment 13")
print("Amit Singhal | 11614802722")

ans={}
for i in range(len(list1)):
    ans.update({list1[i]:list2[i]})

print(ans)
