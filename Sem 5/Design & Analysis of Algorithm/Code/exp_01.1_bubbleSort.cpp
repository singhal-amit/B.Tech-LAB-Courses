#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void bubbleSort(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main()
{
  cout << "5C6 - Amit Singhal (11614802722)" << endl;
  vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  cout << "Unsorted Array: ";
  for (int num : arr)
  {
    cout << num << " ";
  }
  cout << endl;

  clock_t start = clock();
  bubbleSort(arr);
  clock_t end = clock();

  cout << "Bubble Sort:" << endl;
  cout << "Sorted Array: ";
  for (int num : arr)
  {
    cout << num << " ";
  }
  cout << endl;

  double time_taken_ms = double(end - start) * 1000.0 / CLOCKS_PER_SEC; // Convert to milliseconds
  cout << "Time taken: " << time_taken_ms << " milliseconds" << endl;

  return 0;
}

