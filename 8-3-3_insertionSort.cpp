#include <iostream>

using namespace std;

// insertion sort function

void insertionSort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  // unsorted array
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;

  // insertion sort handler
  insertionSort(arr, n);

  // sorted array
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}