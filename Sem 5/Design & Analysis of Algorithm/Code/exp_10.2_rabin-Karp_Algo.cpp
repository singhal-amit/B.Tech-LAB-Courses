#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define d 256 // Number of characters in the input alphabet

// Rabin-Karp function
void rabinKarp(string text, string pattern, int q, int64_t &timeTaken)
{
  int n = text.length();
  int m = pattern.length();
  int i, j;
  int p = 0; // Hash value for pattern
  int t = 0; // Hash value for text
  int h = 1;
  bool found = false;

  // Measure time start
  auto start = high_resolution_clock::now();

  // The value of h would be "pow(d, m-1)%q"
  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;

  // Calculate the hash value of pattern and first window of text
  for (i = 0; i < m; i++)
  {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }

  // Slide the pattern over text one by one
  for (i = 0; i <= n - m; i++)
  {

    // Check the hash values of the current window of text and pattern
    if (p == t)
    {
      // If hash values match, check characters one by one
      for (j = 0; j < m; j++)
      {
        if (text[i + j] != pattern[j])
          break;
      }

      // If the pattern is found
      if (j == m)
      {
        cout << "Pattern found at index " << i << endl;
        found = true;
      }
    }

    // Calculate hash value for next window of text
    if (i < n - m)
    {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      // We might get a negative value of t, convert it to positive
      if (t < 0)
        t = (t + q);
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
  int q = 101; // A prime number

  // Input: Text and Pattern
  cout << "Enter the text: ";
  cin >> text;

  cout << "Enter the pattern: ";
  cin >> pattern;

  int64_t totalTime;

  // Call the Rabin-Karp algorithm function
  rabinKarp(text, pattern, q, totalTime);

  // Display the time complexity
  cout << "\nTime taken for Rabin-Karp String Matching: " << totalTime << " nanoseconds" << endl;

  return 0;
}
