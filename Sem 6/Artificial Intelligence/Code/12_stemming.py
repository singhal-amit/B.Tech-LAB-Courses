import nltk
from nltk.stem import PorterStemmer
from nltk.tokenize import word_tokenize

# Function to perform stemming
def stem_sentence(sentence):
    # Initialize the Porter Stemmer
    porter_stemmer = PorterStemmer()

    # Tokenize the sentence into words
    words = word_tokenize(sentence)

    # Stem each word in the sentence
    stemmed_words = [porter_stemmer.stem(word) for word in words]

    # Join the stemmed words back into a sentence
    return ' '.join(stemmed_words)

# Example usage
sentence = "The cat is jumping and dogs are running fast."
stemmed_sentence = stem_sentence(sentence)

# Print the original and stemmed sentences
print("Original Sentence: ", sentence)
print("Stemmed Sentence: ", stemmed_sentence)
