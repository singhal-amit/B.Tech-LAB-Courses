print("Week 2 - Experiment 11")
print("Amit Singhal | 11614802722")

num = int(input("Enter a number to check if it's prime: "))

if num > 1:
    for i in range(2, int(num ** 0.5) + 1):  # Loop until the square root of the number
        if num % i == 0:
            print(f"{num} is not a prime number.")
            break
    else:
        print(f"{num} is a prime number.")
else:
    print(f"{num} is not a prime number.")
