#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to add two matrices
vector<vector<int>> addMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B, int N)
{
  vector<vector<int>> C(N, vector<int>(N));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      C[i][j] = A[i][j] + B[i][j];
  return C;
}

// Function to subtract two matrices
vector<vector<int>> subtractMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B, int N)
{
  vector<vector<int>> C(N, vector<int>(N));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      C[i][j] = A[i][j] - B[i][j];
  return C;
}

// Function to perform Strassen's matrix multiplication
vector<vector<int>> strassenMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B, int N, int64_t &timeTaken)
{
  vector<vector<int>> C(N, vector<int>(N, 0));

  // Base case for recursion
  if (N == 1)
  {
    C[0][0] = A[0][0] * B[0][0];
    return C;
  }

  // Measure time start
  auto start = high_resolution_clock::now();

  int newSize = N / 2;
  vector<int> z(newSize, 0);

  vector<vector<int>> a11(newSize, z), a12(newSize, z), a21(newSize, z), a22(newSize, z);
  vector<vector<int>> b11(newSize, z), b12(newSize, z), b21(newSize, z), b22(newSize, z);
  vector<vector<int>> c11(newSize, z), c12(newSize, z), c21(newSize, z), c22(newSize, z);
  vector<vector<int>> p1(newSize, z), p2(newSize, z), p3(newSize, z), p4(newSize, z), p5(newSize, z), p6(newSize, z), p7(newSize, z);

  // Dividing the matrices into quadrants
  for (int i = 0; i < newSize; i++)
  {
    for (int j = 0; j < newSize; j++)
    {
      a11[i][j] = A[i][j];
      a12[i][j] = A[i][j + newSize];
      a21[i][j] = A[i + newSize][j];
      a22[i][j] = A[i + newSize][j + newSize];

      b11[i][j] = B[i][j];
      b12[i][j] = B[i][j + newSize];
      b21[i][j] = B[i + newSize][j];
      b22[i][j] = B[i + newSize][j + newSize];
    }
  }

  // Calculating p1 to p7
  p1 = strassenMultiply(addMatrix(a11, a22, newSize), addMatrix(b11, b22, newSize), newSize, timeTaken);
  p2 = strassenMultiply(addMatrix(a21, a22, newSize), b11, newSize, timeTaken);
  p3 = strassenMultiply(a11, subtractMatrix(b12, b22, newSize), newSize, timeTaken);
  p4 = strassenMultiply(a22, subtractMatrix(b21, b11, newSize), newSize, timeTaken);
  p5 = strassenMultiply(addMatrix(a11, a12, newSize), b22, newSize, timeTaken);
  p6 = strassenMultiply(subtractMatrix(a21, a11, newSize), addMatrix(b11, b12, newSize), newSize, timeTaken);
  p7 = strassenMultiply(subtractMatrix(a12, a22, newSize), addMatrix(b21, b22, newSize), newSize, timeTaken);

  // Calculating c11, c12, c21, c22
  c11 = addMatrix(subtractMatrix(addMatrix(p1, p4, newSize), p5, newSize), p7, newSize);
  c12 = addMatrix(p3, p5, newSize);
  c21 = addMatrix(p2, p4, newSize);
  c22 = addMatrix(subtractMatrix(addMatrix(p1, p3, newSize), p2, newSize), p6, newSize);

  // Combining the results into matrix C
  for (int i = 0; i < newSize; i++)
  {
    for (int j = 0; j < newSize; j++)
    {
      C[i][j] = c11[i][j];
      C[i][j + newSize] = c12[i][j];
      C[i + newSize][j] = c21[i][j];
      C[i + newSize][j + newSize] = c22[i][j];
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
  cout << "Enter the size of the matrix (N x N, must be a power of 2): ";
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

  // Multiply matrices using Strassen's algorithm
  vector<vector<int>> C = strassenMultiply(A, B, N, totalTime);

  // Display result matrix
  cout << "\nResultant matrix after Strassen's multiplication:\n";
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cout << C[i][j] << " ";
    cout << endl;
  }

  // Display time complexity
  cout << "\nTime taken for Strassen's matrix multiplication: " << totalTime << " nanoseconds\n";

  return 0;
}
