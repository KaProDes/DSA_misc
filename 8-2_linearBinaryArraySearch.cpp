#include <cmath>
#include <iostream>

using namespace std;

// linear search function

int linearSearch(int arr[], int key, int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key)
      return i;
  }
  return -1;
}

// binary search function

int binarySearch(int arr[], int key, int n) {
  int l = 0, u = n - 1;
  int mid = (l + u) / 2;
  while (l <= u) {
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      l = mid + 1;
      mid = (l + u) / 2;
    } else if (arr[mid] > key) {
      u = mid - 1;
      mid = (l + u) / 2;
    }
  }
  return -1;
}

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  // Array input
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  int key;
  cin >> key;

  // linear search handler
  int index = linearSearch(arr, key, n);
  if (index == -1)
    cout << "Not found : " << key << endl;
  else
    cout << "Element : " << key << "  found at : " << index << endl;

  // binary search handler
  cin >> n;
  int brr[n];
  // make sure the array is sorted
  for (int i = 0; i < n; ++i)
    cin >> brr[i];

  cin >> key;

  index = binarySearch(brr, key, n);
  if (index == -1)
    cout << "Not found : " << key << endl;
  else
    cout << "Element : " << key << "  found at : " << index << endl;

  return 0;
}