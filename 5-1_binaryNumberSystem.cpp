#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void revString(string &s) {
  int n = s.length();

  for (int i = 0; i < n / 2; ++i)
    swap(s[i], s[n - i - 1]);
}

int main() {
  int binNum;
  cout << "Enter a binary number : ";
  cin >> binNum;

  int base = 1;
  int decNum = 0;
  while (binNum) {
    int r = binNum % 10;
    decNum += r * base;
    binNum /= 10;
    base *= 2;
  }
  cout << "Decimal Equivalent : " << decNum << endl;

  cout << "Enter a decimal number : ";
  cin >> decNum;
  binNum = 0;
  base = 1;
  int r;
  string binString;
  while (decNum >= 2) {
    r = decNum % 2;
    decNum /= 2;
    binString += to_string(r);
    base *= 10;
  }
  binString += to_string(decNum);
  revString(binString);
  cout << binString;
  return 0;
}