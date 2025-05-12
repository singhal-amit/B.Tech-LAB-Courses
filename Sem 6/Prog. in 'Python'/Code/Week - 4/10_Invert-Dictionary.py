# Write a Python program to invert a dictionary (swap keys and values).

dict={
    "country": "India",
    "state": "Uttar Pradesh",
    "city": "Lucknow"
}
ans={}

print("Week 4 - Experiment 10")
print("Amit Singhal | 11614802722")

for item in dict:
    value=dict.get(item)
    ans.update({value:item})

print(ans)
