#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to find LCS using iterative DP approach
int lcsIterative(string X, string Y, int64_t &timeTaken)
{
  int m = X.length();
  int n = Y.length();

  // Create a 2D table to store lengths of LCS
  vector<vector<int>> dp(m + 1, vector<int>(n + 1));

  // Measure time start
  auto start = high_resolution_clock::now();

  // Build the dp table in a bottom-up manner
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (X[i - 1] == Y[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  // Measure time end
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);
  timeTaken = duration.count(); // Time in nanoseconds

  // The length of LCS is in dp[m][n]
  return dp[m][n];
}

int main()
{
  cout << "\n5C6 - Amit Singhal (11614802722)\n"
       << endl;

  string X, Y;

  // Input: Two strings
  cout << "Enter first string: ";
  cin >> X;

  cout << "Enter second string: ";
  cin >> Y;

  int64_t totalTime;

  // Find the length of LCS using iterative approach
  int lcsLength = lcsIterative(X, Y, totalTime);

  // Display the length of LCS
  cout << "\nLength of Longest Common Subsequence (Iterative): " << lcsLength << endl;

  // Display time complexity
  cout << "Time taken for iterative LCS: " << totalTime << " nanoseconds\n";

  return 0;
}
