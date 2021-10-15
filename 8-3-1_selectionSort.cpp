#include <iostream>

using namespace std;

// selection sort function

void selectionSort(int *arr, int n) {
  for (int i = 0; i < n - 1; ++i) {
    int minInd = i; // [*]init with i not i+1
    for (int j = i + 1; j <= n - 1; ++j) {
      if (arr[j] < arr[minInd]) {
        minInd = j;
      }
    }
    swap(arr[i], arr[minInd]);
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

  // selection sort handler
  selectionSort(arr, n);

  // sorted array
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}