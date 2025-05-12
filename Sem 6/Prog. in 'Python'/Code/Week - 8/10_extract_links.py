# Extract Links from a Web Page and Save to a Text File
# Write a Python script to extract all hyperlinks from a webpage and save them to a text file.

print("Week 8 - Experiment 10")
print("Amit Singhal | 11614802722")

import requests
from bs4 import BeautifulSoup

url = "https://www.example.com"
response = requests.get(url)
soup = BeautifulSoup(response.text, "html.parser")

with open("links.txt", "w") as file:
    for link in soup.find_all("a", href=True):
        file.write(link["href"] + "\n")
print("Hyperlinks saved to links.txt")
