import nltk
from nltk.tokenize import word_tokenize
from nltk import pos_tag

# Function to perform POS tagging
def pos_tagging(sentence):
    # Tokenize the sentence into words
    words = word_tokenize(sentence)

    # Perform POS tagging
    tagged_words = pos_tag(words)

    return tagged_words

# Example usage
sentence = "The cat is jumping and dogs are running fast."
tagged_sentence = pos_tagging(sentence)

# Print the original sentence and its POS tags
print("Original Sentence: ", sentence)
print("POS Tagged Sentence: ", tagged_sentence)
