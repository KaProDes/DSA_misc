#include <cmath>
#include <iostream>
using namespace std;

// minimum integer in array function

int get_min(int arr[], int n) {
  // int_max
  int minNum = pow(2, sizeof(int) * 8 - 1) - 1;

  for (int i = 0; i < n; ++i) {
    if (arr[i] < minNum)
      minNum = arr[i];
  }
  return minNum;
}

// maximum integer in array function

int get_max(int arr[], int n) {
  // int_min
  int maxNum = -pow(2, sizeof(int) * 8 - 1);
  for (int i = 0; i < n; ++i) {
    if (arr[i] > maxNum)
      maxNum = arr[i];
  }
  return maxNum;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  // Statically hardcoded arrays
  int arr[5] = {13, 12, 4, 15, -1};
  for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // User input arrays

  int n;
  cout << "Enter number of elements in the array : ";
  cin >> n;
  int brr[n];
  // input
  for (int i = 0; i < n; ++i)
    cin >> brr[i];
  // output
  for (int i = 0; i < n; ++i) {
    cout << brr[i] << " ";
  }
  cout << endl;

  // Printing minimum and maximum element from the above entered array (brr)

  int minNum = get_min(brr, n);
  int maxNum = get_max(brr, n);

  cout << "Minimum : " << minNum << " Maximum : " << maxNum << endl;
  return 0;
}