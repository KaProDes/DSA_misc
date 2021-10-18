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

  // [1] Transposing the given array
  for (int i = 0; i < m; i++) {
    for (int j = i; j < m; j++) {
      swap(arr[i][j], arr[j][i]);
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // [2] Multiplying 2 matrices
  int p, q;
  cin >> m >> n;
  cin >> p >> q;
  if (n != p) {
    cout << "Matrices cannot be multiplied" << endl;
    ;
    exit;
  }
  int a[m][n];
  int b[p][q];
  // Reading first matrix
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  // Reading second matrix
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < q; ++j) {
      cin >> b[i][j];
    }
  }

  // multiplying

  int res[m][q];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < q; j++) {
      int sum = 0;
      int k;
      for (k = 0; k < n; k++) {
        sum += a[i][k] * b[k][j];
      }
      res[i][j] = sum;
    }
  }

  // print result array
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < q; ++j) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  // 2D matrix search
  // All rows and all columns are sorted
  /*
    Eg :
    1 4 7 11
    2 5 8 12
    3 6 9 16
    10 13 14 17
  */
  // Approach : Start from Top right (bottom left)
  // if element < current key move down
  // if element > key move left
  // if element == key cout

  cin >> m >> n;
  int sortedMatrix[m][n];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> sortedMatrix[i][j];
    }
  }
  int key;
  cin >> key;
  int row = 0, col = n - 1;
  while (1) {
    if (sortedMatrix[row][col] == key) {
      printf("Element %d found at a[%d,%d]\n", key, row, col);
      break;
    } else if (sortedMatrix[row][col] < key)
      row++;
    else if (sortedMatrix[row][col] > key)
      col--;
    if (row >= n || col <= -1) {
      printf("Element %d not found\n", key);
      break;
    }
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

3 4
4 3

2 4 1 2
8 4 3 6
1 7 9 5

1 2 3
4 5 6
7 8 9
4 5 6

4 4

1 4 7 11
2 5 8 12
3 6 9 16
10 13 14 17

13
*/