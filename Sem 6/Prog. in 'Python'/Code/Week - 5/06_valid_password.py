# Implement a function to check whether a given string is a valid password
# (at least 8 characters, contains digits, uppercase, lowercase, and a special character).

print("Week 5 - Experiment 6")
print("Amit Singhal | 11614802722")

import re

def is_valid_password(password):
    if (len(password) >= 8 and
        re.search(r'[A-Z]', password) and
        re.search(r'[a-z]', password) and
        re.search(r'\d', password) and
        re.search(r'[!@#$%^&*(),.?":{}|<>]', password)):
        return True
    return False

password = "Strong@123"
print(f"Is '{password}' a valid password? {is_valid_password(password)}")
