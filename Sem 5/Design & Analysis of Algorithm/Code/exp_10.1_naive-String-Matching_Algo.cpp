#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function for Naive String Matching Algorithm
void naiveStringMatching(string text, string pattern, int64_t &timeTaken)
{
  int n = text.length();
  int m = pattern.length();

  bool found = false;

  // Measure time start
  auto start = high_resolution_clock::now();

  // Slide pattern over text one by one
  for (int i = 0; i <= n - m; i++)
  {
    int j;
    // Check for match at this position
    for (j = 0; j < m; j++)
    {
      if (text[i + j] != pattern[j])
        break;
    }

    // If pattern[0...m-1] matches text[i...i+m-1], a match is found
    if (j == m)
    {
      cout << "Pattern found at index " << i << endl;
      found = true;
    }
  }

  // Measure time end
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);
  timeTaken = duration.count(); // Time in nanoseconds

  if (!found)
  {
    cout << "Pattern not found in the text." << endl;
  }
}

int main()
{
  cout << "\n5C6 - Amit Singhal (11614802722)\n"
       << endl;

  string text, pattern;

  // Input: Text and Pattern
  cout << "Enter the text: ";
  cin >> text;

  cout << "Enter the pattern: ";
  cin >> pattern;

  int64_t totalTime;

  // Call the naive string matching function
  naiveStringMatching(text, pattern, totalTime);

  // Display the time complexity
  cout << "\nTime taken for Naive String Matching: " << totalTime << " nanoseconds" << endl;

  return 0;
}
