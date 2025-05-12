#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int linearSearch(const vector<int> &arr, int x)
{
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] == x)
    {
      return i;
    }
  }
  return -1; // Element not found
}

int main()
{
  cout << "5C6 - Amit Singhal (11614802722)" << endl;

  vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
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
  int index = linearSearch(arr, x);
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
