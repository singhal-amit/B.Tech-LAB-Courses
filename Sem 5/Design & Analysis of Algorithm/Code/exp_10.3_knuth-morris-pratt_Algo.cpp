#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to compute the Longest Prefix Suffix (LPS) array
void computeLPSArray(string pattern, vector<int> &lps)
{
  int len = 0; // Length of the previous longest prefix suffix
  lps[0] = 0;  // LPS[0] is always 0

  // The loop calculates lps[i] for i = 1 to m-1
  for (int i = 1; i < pattern.length();)
  {
    if (pattern[i] == pattern[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      // This is tricky. Consider the example "AAACAAAA" and i = 7.
      if (len != 0)
      {
        len = lps[len - 1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}

// KMP algorithm implementation
void KMPSearch(string text, string pattern, int64_t &timeTaken)
{
  int m = pattern.length();
  int n = text.length();

  vector<int> lps(m);            // LPS array for the pattern
  computeLPSArray(pattern, lps); // Preprocess the pattern

  // Measure time start
  auto start = high_resolution_clock::now();

  int i = 0; // Index for text
  int j = 0; // Index for pattern
  bool found = false;

  while (i < n)
  {
    if (pattern[j] == text[i])
    {
      i++;
      j++;
    }

    if (j == m)
    {
      cout << "Pattern found at index " << (i - j) << endl;
      found = true;
      j = lps[j - 1]; // Continue to search for next occurrence
    }
    else if (i < n && pattern[j] != text[i]) // mismatch after j matches
    {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
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

  // Call the KMP algorithm function
  KMPSearch(text, pattern, totalTime);

  // Display the time complexity
  cout << "\nTime taken for KMP String Matching: " << totalTime << " nanoseconds" << endl;

  return 0;
}
