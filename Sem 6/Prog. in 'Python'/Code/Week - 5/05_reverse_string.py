# Write a Python program to reverse each word in a given string while maintaining the word order.

print("Week 5 - Experiment 5")
print("Amit Singhal | 11614802722")

def reverse_words(sentence):
    return " ".join(word[::-1] for word in sentence.split())

text = "Hello World Python"
print(reverse_words(text))
