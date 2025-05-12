import random

# List of words to choose from
words = ['python', 'java', 'hangman', 'computer', 'programming', 'developer']

# Function to choose a random word from the list
def choose_word():
    return random.choice(words)

# Function to display the current state of the word
def display_word(word, guessed_letters):
    display = ""
    for letter in word:
        if letter in guessed_letters:
            display += letter
        else:
            display += "_"
    return display

# Main hangman game function
def hangman():
    word = choose_word()
    guessed_letters = []
    attempts = 6  # Number of incorrect attempts before the game is over
    print("Welcome to Hangman!")
    print("Try to guess the word, you have", attempts, "attempts.")

    while attempts > 0:
        print("\nWord: ", display_word(word, guessed_letters))
        print(f"Guessed letters: {', '.join(guessed_letters)}")
        print(f"Attempts left: {attempts}")

        guess = input("Enter a letter: ").lower()

        # Validate the input
        if len(guess) != 1 or not guess.isalpha():
            print("Please enter a single valid letter.")
            continue

        # Check if the letter has already been guessed
        if guess in guessed_letters:
            print("You've already guessed that letter!")
            continue

        # Add the guessed letter to the guessed_letters list
        guessed_letters.append(guess)

        # Check if the guessed letter is in the word
        if guess not in word:
            attempts -= 1
            print(f"Wrong guess! {guess} is not in the word.")

        # Check if the user has guessed the word
        if all(letter in guessed_letters for letter in word):
            print(f"Congratulations! You've guessed the word: {word}")
            break
    else:
        print(f"Game Over! The word was: {word}")

# Run the hangman game
if __name__ == "__main__":
    hangman()
