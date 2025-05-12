# Write a Python program to count the occurrences of each character in a string using a dictionary.

from pprint import pprint

def countDictChars(str):
    dict={}
    for char in str:
        char=char.lower()
        if char==" ":
            continue
        elif char in dict:
            dict[char] += 1
        else:
            dict[char] = 1
    return dict

print("Week 4 - Experiment 9")
print("Amit Singhal | 11614802722")

str=input("Enter The String : ")
print("The Dictionary Is : ")
pprint(countDictChars(str))
