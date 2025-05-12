#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
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
  quickSort(arr, 0, arr.size() - 1);
  clock_t end = clock();

  cout << "Quick Sort:" << endl;
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
