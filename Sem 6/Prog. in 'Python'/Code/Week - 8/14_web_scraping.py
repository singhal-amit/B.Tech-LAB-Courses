# Web Scraping with Pagination
# Write a program to scrape data from a website with multiple pages and save all the scraped data to a file.

print("Week 8 - Experiment 14")
print("Amit Singhal | 11614802722")

import requests
from bs4 import BeautifulSoup

base_url = "https://en.wikipedia.org/wiki/Python_(programming_language)"
output = ""

for i in range(1, 4):  # Simulate 3 pages
    response = requests.get(base_url + str(i))
    soup = BeautifulSoup(response.text, "html.parser")
    output += soup.get_text()

with open("paged_data.txt", "w") as f:
    f.write(output)

print("Scraped paginated data saved to paged_data.txt")
