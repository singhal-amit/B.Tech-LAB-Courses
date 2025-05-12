#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void insertionSort(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
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
  insertionSort(arr);
  clock_t end = clock();

  cout << "Insertion Sort:" << endl;
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
