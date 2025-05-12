#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to multiply two matrices using normal algorithm
vector<vector<int>> multiplyNormal(const vector<vector<int>> &A, const vector<vector<int>> &B, int N, int64_t &timeTaken)
{
  vector<vector<int>> C(N, vector<int>(N, 0));

  // Measure time start
  auto start = high_resolution_clock::now();

  // Perform matrix multiplication
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < N; k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  // Measure time end
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);
  timeTaken = duration.count(); // Time in nanoseconds

  return C;
}

int main()
{
  cout << "\n5C6 - Amit Singhal (11614802722)\n"
       << endl;

  int N;

  // Input: Matrix size (NxN)
  cout << "Enter the size of the matrix (N x N): ";
  cin >> N;

  vector<vector<int>> A(N, vector<int>(N));
  vector<vector<int>> B(N, vector<int>(N));

  // Input: Matrix A
  cout << "\nEnter matrix A values:\n";
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];

  // Input: Matrix B
  cout << "\nEnter matrix B values:\n";
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> B[i][j];

  int64_t totalTime;

  // Multiply matrices using normal algorithm
  vector<vector<int>> C = multiplyNormal(A, B, N, totalTime);

  // Display result matrix
  cout << "\nResultant matrix after normal multiplication:\n";
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cout << C[i][j] << " ";
    cout << endl;
  }

  // Display time complexity
  cout << "\nTime taken for normal matrix multiplication: " << totalTime << " nanoseconds\n";

  return 0;
}
