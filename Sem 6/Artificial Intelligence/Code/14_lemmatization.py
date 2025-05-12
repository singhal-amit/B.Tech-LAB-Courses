import nltk
from nltk.tokenize import word_tokenize
from nltk.stem import WordNetLemmatizer

# Initialize the WordNet Lemmatizer
lemmatizer = WordNetLemmatizer()

# Function to perform Lemmatization
def lemmatize_sentence(sentence):
    # Tokenize the sentence into words
    words = word_tokenize(sentence)

    # Lemmatize each word
    lemmatized_words = [lemmatizer.lemmatize(word, pos='v') for word in words]  # 'v' for verb, you can change it depending on the word
    return ' '.join(lemmatized_words)

# Example usage
sentence = "The cats are running and they are better than others."
lemmatized_sentence = lemmatize_sentence(sentence)

# Print the original and lemmatized sentences
print("Original Sentence: ", sentence)
print("Lemmatized Sentence: ", lemmatized_sentence)
