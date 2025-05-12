import random

print("Week 2 - Experiment 6")
print("Amit Singhal | 11614802722")

print("Choose one of the following:")
print("1 - Rock")
print("2 - Paper")
print("3 - Scissors")

user_choice = int(input("Enter your choice (1, 2, 3): "))
computer_choice = random.randint(1, 3)

choices = {1: "Rock", 2: "Paper", 3: "Scissors"}

print(f"You chose: {choices[user_choice]}")
print(f"Opponent chose: {choices[computer_choice]}")

if user_choice == computer_choice:
    print("It's a Draw!")
elif (user_choice == 1 and computer_choice == 3) or \
     (user_choice == 2 and computer_choice == 1) or \
     (user_choice == 3 and computer_choice == 2):
    print("You Win!")
else:
    print("Opponent Wins!")
