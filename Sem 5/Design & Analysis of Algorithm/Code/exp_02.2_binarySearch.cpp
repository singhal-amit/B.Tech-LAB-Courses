#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int binarySearch(const vector<int> &arr, int x)
{
  int left = 0, right = arr.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == x)
    {
      return mid;
    }
    if (arr[mid] < x)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return -1; // Element not found
}

int main()
{
  cout << "5C6 - Amit Singhal (11614802722)" << endl;

  vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  sort(arr.begin(), arr.end()); // Binary search requires a sorted array

  cout << "Array: ";
  for (int num : arr)
  {
    cout << num << " ";
  }
  cout << endl;

  int x;
  cout << "Enter the element to search: ";
  cin >> x;

  clock_t start = clock();
  int index = binarySearch(arr, x);
  clock_t end = clock();

  if (index != -1)
  {
    cout << "Element found at index: " << index << endl;
  }
  else
  {
    cout << "Element not found" << endl;
  }

  double time_taken_ms = double(end - start) * 1000.0 / CLOCKS_PER_SEC; // Convert to milliseconds
  cout << "Time taken: " << time_taken_ms << " milliseconds" << endl;

  return 0;
}
