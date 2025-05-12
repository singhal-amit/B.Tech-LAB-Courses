#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool isSafe(const vector<vector<int>> &board, int row, int col, int N)
{
  // Check this row on left side
  for (int i = 0; i < col; i++)
    if (board[row][i])
      return false;

  // Check upper diagonal on left side
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j])
      return false;

  // Check lower diagonal on left side
  for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    if (board[i][j])
      return false;

  return true;
}

bool solveNQueensUtil(vector<vector<int>> &board, int col, int N)
{
  // If all queens are placed, return true
  if (col >= N)
    return true;

  // Try placing queens in all rows of this column
  for (int i = 0; i < N; i++)
  {
    if (isSafe(board, i, col, N))
    {
      // Place the queen
      board[i][col] = 1;

      // Recur to place the rest of the queens
      if (solveNQueensUtil(board, col + 1, N))
        return true;

      // If placing queen in board[i][col] doesn't lead to a solution, remove it
      board[i][col] = 0;
    }
  }

  // If queen can't be placed in any row in this column, return false
  return false;
}

bool solveNQueens(int N, int64_t &timeTaken)
{
  vector<vector<int>> board(N, vector<int>(N, 0));

  // Measure time start
  auto start = high_resolution_clock::now();

  if (!solveNQueensUtil(board, 0, N))
  {
    cout << "Solution does not exist" << endl;
    return false;
  }

  // Measure time end
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);
  timeTaken = duration.count(); // Time in nanoseconds

  // Print the solution
  cout << "Solution for " << N << "-Queens problem:" << endl;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cout << (board[i][j] ? "Q " : ". ");
    cout << endl;
  }

  return true;
}

int main()
{
  cout << "\n5C6 - Amit Singhal (11614802722)\n"
       << endl;

  int N;

  // Input: Size of the chessboard
  cout << "Enter the number of queens (N): ";
  cin >> N;

  int64_t totalTime;

  // Solve the N-Queens problem
  if (solveNQueens(N, totalTime))
  {
    // Display time complexity
    cout << "\nTime taken to solve the " << N << "-Queens problem: " << totalTime << " nanoseconds" << endl;
  }

  return 0;
}
