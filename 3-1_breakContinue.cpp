#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  int min, max;
  cout << "Enter range to explore (min,max) : ";
  cin >> min >> max;
  if (min > max || min < 0) {
    cout << "Invalid Range" << endl;
    return 0;
  }
  int prime = 0;
  for (int i = min; i <= max; i++) {
    if (i == 1)
      continue;
    int currNum = i;
    int j;
    for (j = 2; j < sqrt(currNum); j++) {
      if (currNum % j == 0) {
        cout << "X ";
        break;
      }
    }
    if (j > sqrt(currNum)) {
      cout << currNum << " ";
      prime++;
    }
  }
  cout << "\nTotal Prime : " << prime
       << "\tTotal Non-Prime : " << max - min - prime + 1 << endl;
  return 0;
}