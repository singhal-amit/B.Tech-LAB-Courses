# Scraping Data from a Website and Save it to a File
# Use requests and BeautifulSoup to scrape data from a webpage and save the content to a file.

print("Week 8 - Experiment 9")
print("Amit Singhal | 11614802722")

import requests
from bs4 import BeautifulSoup

url = "https://www.example.com"
response = requests.get(url)
soup = BeautifulSoup(response.text, "html.parser")

with open("scraped.txt", "w") as f:
    f.write(soup.prettify())
print("Webpage content saved to scraped.txt")
