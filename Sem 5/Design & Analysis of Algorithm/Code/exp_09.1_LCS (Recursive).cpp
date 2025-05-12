#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to find LCS using recursive approach with memoization
int lcsRecursive(string X, string Y, int m, int n, vector<vector<int>> &memo)
{
    // Base case: if either string is empty
    if (m == 0 || n == 0)
        return 0;

    // Check if the result is already computed
    if (memo[m][n] != -1)
        return memo[m][n];

    // If characters match, store the result in memo
    if (X[m - 1] == Y[n - 1])
        memo[m][n] = 1 + lcsRecursive(X, Y, m - 1, n - 1, memo);
    else
        // If characters don't match, take the max of two options
        memo[m][n] = max(lcsRecursive(X, Y, m - 1, n, memo), lcsRecursive(X, Y, m, n - 1, memo));

    return memo[m][n];
}

int main()
{
    cout << "\n5C6 - Amit Singhal (11614802722)\n" << endl;

    string X, Y;

    // Input: Two strings
    cout << "Enter first string: ";
    cin >> X;

    cout << "Enter second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    // Initialize memoization table with -1
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    // Measure time start
    auto start = high_resolution_clock::now();

    // Find the length of LCS using recursive approach
    int lcsLength = lcsRecursive(X, Y, m, n, memo);

    // Measure time end
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    int64_t totalTime = duration.count(); // Time in nanoseconds

    // Display the length of LCS
    cout << "\nLength of Longest Common Subsequence (Recursive): " << lcsLength << endl;

    // Display time complexity
    cout << "Time taken for recursive LCS: " << totalTime << " nanoseconds\n";

    return 0;
}
