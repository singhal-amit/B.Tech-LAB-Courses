import nltk
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.classify import NaiveBayesClassifier
from nltk.classify.util import accuracy

# Sample labeled data for training the classifier
training_data = [
    ("I love programming", "positive"),
    ("I hate bugs", "negative"),
    ("This is so great", "positive"),
    ("I am so angry at this error", "negative"),
    ("Coding is awesome", "positive"),
    ("This is terrible", "negative")
]

# Preprocess the data: tokenization and removing stopwords
stop_words = set(stopwords.words("english"))

def preprocess(text):
    tokens = word_tokenize(text.lower())  # Tokenize and convert to lowercase
    return {word: True for word in tokens if word not in stop_words and word.isalpha()}

# Feature extraction
train_set = [(preprocess(text), label) for text, label in training_data]

# Train the Naive Bayes classifier
classifier = NaiveBayesClassifier.train(train_set)

# Test the classifier with a new sentence
def classify_sentence(sentence):
    features = preprocess(sentence)
    return classifier.classify(features)

# Example usage
test_sentence = "I love coding but debugging is hard."
print(f"Sentence: {test_sentence}")
print(f"Classification: {classify_sentence(test_sentence)}")

# Print classifier accuracy on training data
print(f"Classifier accuracy: {accuracy(classifier, train_set) * 100}%")
