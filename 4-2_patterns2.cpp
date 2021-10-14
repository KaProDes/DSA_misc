#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

  // Inverted Number pattern
  /*
  1 2 3 4 5 6
  1 2 3 4 5
  1 2 3 4
  1 2 3
  1 2
  1
  */
  int rows;
  cout << "Enter no of rows : ";
  cin >> rows;

  for (int i = rows; i >= 1; --i) {
    for (int j = 1; j <= i; ++j) {
      cout << j << " ";
    }
    cout << endl;
  }
  cout << endl;
  // 01 pattern
  /*
  1
  0 1
  1 0 1
  0 1 0 1
  1 0 1 0 1
  0 1 0 1 0 1
  */

  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= i; ++j) {
      if ((i + j) % 2 == 0) {
        cout << "1 ";
      } else {
        cout << "0 ";
      }
    }
    cout << endl;
  }
  cout << endl;

  // Rhombous Pattern
  /*
          # # # # # #
         # # # # # #
        # # # # # #
       # # # # # #
      # # # # # #
     # # # # # #
   */

  for (int i = rows; i >= 1; --i) {
    int spaces = i - 1;
    for (int j = 1; j <= spaces; ++j) {
      cout << " ";
    }

    for (int j = 1; j <= rows; ++j) {
      cout << "# ";
    }
    cout << endl;
  }

  cout << endl;

  // Number pyramid (full)
  /*
            1
           1 2
          1 2 3
         1 2 3 4
        1 2 3 4 5
       1 2 3 4 5 6
  */

  for (int i = 1; i <= rows; ++i) {
    int spaces = rows - i;
    for (int j = 1; j <= spaces; ++j) {
      cout << " ";
    }

    for (int j = 1; j <= i; ++j) {
      cout << j << " ";
    }
    cout << endl;
  }
  cout << endl;

  // Pallindromic Pattern
  /*
              1
            2 1 2
          3 2 1 2 3
        4 3 2 1 2 3 4
      5 4 3 2 1 2 3 4 5
  */

  for (int i = 1; i <= rows; ++i) {
    int spaces = 2 * (rows - i);
    for (int j = 1; j <= spaces; ++j) {
      cout << " ";
    }

    for (int j = i; j > 1; --j) {
      cout << j << " ";
    }

    for (int j = 1; j <= i; ++j) {
      cout << j << " ";
    }
    cout << endl;
  }
  cout << endl;

  // Double Pyramid Pattern

  /*
        #
      # # #
    # # # # #
  # # # # # # #
# # # # # # # # #
  # # # # # # #
    # # # # #
      # # #
        #
  */

  // Upper half
  for (int i = 1; i <= rows; ++i) {
    int spaces = 2 * (rows - i);
    for (int j = 1; j <= spaces; ++j) {
      cout << " ";
    }
    int hashes = 2 * i - 1;
    for (int j = 1; j <= hashes; ++j) {
      cout << "# ";
    }
    cout << endl;
  }
  // Lower half
  for (int i = rows - 1; i >= 1; --i) {
    int spaces = 2 * (rows - i);
    for (int j = 1; j <= spaces; ++j) {
      cout << " ";
    }
    int hashes = 2 * i - 1;
    for (int j = 1; j <= hashes; ++j) {
      cout << "# ";
    }
    cout << endl;
  }

  cout << endl;

  //[*] Zig zag pattern
  // Done by tracing the coordinates

  /*
          #       #
        #   #   #   #
      #       #       #
  */

  int noOfStars = 15;

  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= noOfStars; ++j) {
      if ((i + j) % 4 == 0) {
        cout << "# ";
      } else if ((i == 2) && (j % 4) == 0) {
        cout << "# ";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }

  cout << endl;

  return 0;
}
