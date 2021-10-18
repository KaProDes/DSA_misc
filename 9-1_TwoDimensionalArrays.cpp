#include <iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif

  // Taking input of a 2D array
  int m, n;
  cin >> m >> n;
  int arr[m][n];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }
  // Printing out a 2D array
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  // Searching a matrix for a key
  bool found = false;
  int key;
  cin >> key;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (arr[i][j] == key) {
        found = true;
        printf("Key %d found at arr[%d,%d]\n\n", key, i, j);
      }
    }
  }
  if (!found)
    cout << "Key " << key << " not found!" << endl << endl;

  // Spiral order traversal for square matrices
  int row_start = 0, row_end = m - 1, col_start = 0, col_end = n - 1;
  int i, j;
  while (row_start <= row_end && col_start <= col_end) {
    i = row_start;
    for (j = col_start; j <= col_end; j++) {
      cout << arr[i][j] << " ";
    }
    j--;
    for (i = row_start + 1; i <= row_end; i++) {
      cout << arr[i][j] << " ";
    }
    i--;
    for (j = col_end - 1; j >= col_start; j--) {
      cout << arr[i][j] << " ";
    }
    j++;
    for (i = row_end - 1; i >= row_start + 1; i--) {
      cout << arr[i][j] << " ";
    }
    row_start++;
    row_end--;
    col_start++;
    col_end--;
  }

  return 0;
}

/*
  input.txt dump
5 5

89 17 10 15 26
6 81 8 98 12
17 89 35 14 45
18 38 29 67 8
17 93 22 76 2

29
*/