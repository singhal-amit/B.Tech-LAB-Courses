import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

# Function to remove stopwords from text
def remove_stopwords(text):
    stop_words = set(stopwords.words('english'))  # Load NLTK's stop words
    words = word_tokenize(text)  # Tokenize text into words
    filtered_words = [word for word in words if word.lower() not in stop_words]
    return ' '.join(filtered_words)  # Join words back into a sentence

# Read text from file
input_file = "input.txt"
with open(input_file, "r") as file:
    text = file.read()

# Process text to remove stopwords
filtered_text = remove_stopwords(text)

# Write the cleaned text to output file
output_file = "output.txt"
with open(output_file, "w") as file:
    file.write(filtered_text)

# Print result
print("Original Text:\n", text)
print("Filtered Text:\n", filtered_text)
