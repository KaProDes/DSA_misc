#include <iostream>

using namespace std;

// bubble sort function

void bubbleSort(int *arr, int n) {
  int pass = 1;

  while (pass < n) {
    bool swapped = false;
    for (int i = 0; i < n - pass; ++i) {
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        swapped = true;
      }
    }
    if (swapped == false) {
      // print the number of iterations (passes) required to
      // ensure the array is sorted
      cout << pass << endl;
      break;
    }
    pass++;
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

  // bubble sort handler
  bubbleSort(arr, n);

  // sorted array
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}