#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  int rows, cols;

  cout << "Enter rows and columns of the rectangle : " << endl;
  cin >> rows >> cols;

  // solid rectangle

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << "*";
    }
    cout << endl;
  }
  cout << endl;
  cout << endl;
  // hollow rectangle

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }

  // inverted half pyramid

  cout << "Enter number of rows for the pyramid : ";
  cin >> rows;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < rows - i; ++j) {
      cout << "*";
    }
    cout << endl;
  }

  cout << endl;
  // half pyramid 180deg rotated

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < rows; ++j) {
      if (j < rows - i - 1) {
        cout << " ";
      } else {
        cout << "*";
      }
    }
    cout << endl;
  }
  cout << endl;
  // Half number pyramid

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j <= i; ++j) {
      cout << i + 1;
    }
    cout << endl;
  }
  cout << endl;
  // floyd's triangle
  /*
    1
    2 3
    4 5 6
    7 8 9 10
    11 12 13 14 15
  */

  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= i; ++j) {
      cout << i * (i - 1) / 2 + (j) << " ";
    }
    cout << endl;
  }
  cout << endl;

  // Butterfly pattern
  rows = 4;

  // Upper part
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= 2 * rows; ++j) {
      if (j > i && j <= 2 * rows - i) {
        cout << " ";
      } else {
        cout << "*";
      }
    }
    cout << endl;
  }
  // Lower Part
  for (int i = 1; i <= rows; ++i) {
    int stars = rows - i + 1;
    for (int j = 1; j <= stars; ++j) {
      cout << "*";
    }

    int spaces = 2 * rows - 2 * stars;
    for (int j = 1; j <= spaces; ++j) {
      cout << " ";
    }

    for (int j = 1; j <= stars; ++j) {
      cout << "*";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
