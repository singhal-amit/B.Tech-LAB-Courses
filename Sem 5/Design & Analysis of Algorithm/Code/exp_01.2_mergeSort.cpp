#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[m + 1 + i];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &arr, int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
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
  mergeSort(arr, 0, arr.size() - 1);
  clock_t end = clock();

  cout << "Merge Sort:" << endl;
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
