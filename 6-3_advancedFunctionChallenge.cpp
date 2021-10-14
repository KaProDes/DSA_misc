#include <iostream>

using namespace std;

// Natural number sum function
int sumOfNatural(int n) { return n * (n + 1) / 2; }

// Pythagorian triplet

bool pythTriplet(int a, int b, int c) {
  int hypo, s1, s2;
  (a >= b) ? (a >= c ? (hypo = a, s1 = b, s2 = c) : (hypo = c, s1 = b, s2 = a))
           : (b >= c ? (hypo = b, s1 = a, s2 = c) : (hypo = c, s1 = a, s2 = b));
  if (hypo * hypo == s1 * s1 + s2 * s2)
    return true;
  return false;
}

// binary to decimal function

int bin2dec(int binNum) {
  int decNum = 0;
  int multiplier = 1;
  int base = 2;

  while (binNum) {
    decNum += (binNum % 10) * multiplier;
    binNum /= 10;
    multiplier *= base;
  }
  return decNum;
}

// octal to decimal function

int oct2dec(int octNum) {
  int decNum = 0, base = 8, multiplier = 1;

  while (octNum) {
    decNum += (octNum % 10) * multiplier;
    octNum /= 10;
    multiplier *= base;
  }
  return decNum;
}

// String length calculator

int lenstring(char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

// hexadecimal to decimal function

int hex2dec(char hexNum[]) {
  int decNum = 0, base = 16, multiplier = 1;
  int n = lenstring(hexNum);
  for (int i = n - 1; i >= 0; --i) {
    if (hexNum[i] >= 65 && hexNum[i] <= 70) {
      decNum += multiplier * (hexNum[i] - 55);
      multiplier *= base;
    } else {
      decNum += multiplier * (hexNum[i] - 48);
      multiplier *= base;
    }
  }
  return decNum;
}

// [*] decimal to binary function (there is another method in 5-1)

int dec2bin(int decNum) {
  int multiplier = 1;
  while (multiplier <= decNum) {
    multiplier *= 2;
  }
  multiplier /= 2;

  int binNum = 0;
  while (multiplier) {
    int bit = decNum / multiplier;
    decNum -= bit * multiplier;
    multiplier /= 2;
    binNum = binNum * 10 + bit;
  }
  return binNum;
}

// [*] decimal to octal function

int dec2oct(int decNum) {
  int multiplier = 1;
  while (multiplier <= decNum) {
    multiplier *= 8;
  }
  multiplier /= 8;

  int octNum = 0;

  while (multiplier) {
    int digit = decNum / multiplier;
    decNum -= digit * multiplier;
    multiplier /= 8;
    octNum = octNum * 10 + digit;
  }
  return octNum;
}

//[*]Decimal to Hexadecimal function

string dec2hex(int decNum) {
  int multiplier = 1;
  while (multiplier <= decNum) {
    multiplier *= 16;
  }
  multiplier /= 16;

  int i = multiplier;
  string hexNum = "";
  while (multiplier) {
    int digit = decNum / multiplier;
    if (digit >= 10 && digit <= 15) {
      hexNum += (char)(digit + 55);
    } else {
      hexNum += (char)(digit + 48);
    }
    decNum -= digit * multiplier;
    multiplier /= 16;
  }
  return hexNum;
}

// reversing a string

string revString(string str) {
  int n = 0;
  while (str[n] != '\0') {
    n++;
  }
  for (int i = 0; i < n / 2; ++i) {
    swap(str[i], str[n - i - 1]);
  }
  return str;
}

//[*] adding two binary numbers

string addBinary(int a, int b) {
  string res = "";
  int prevCarry = 0;
  while (a != 0 && b != 0) {
    if (a % 2 == 0 && b % 2 == 0) {
      res = res + to_string(prevCarry);
    }
    if ((a % 2 == 0 && b % 2 == 1) || (b % 2 == 0 && a % 2 == 1)) {
      if (prevCarry == 1) {
        res = res + to_string(0);
        prevCarry = 1;
      } else {
        res = res + to_string(1);
        prevCarry = 0;
      }
    }
    if (a % 2 == 1 && b % 2 == 1) {
      res = res + to_string(prevCarry);
      prevCarry = 1;
    }
    a /= 10;
    b /= 10;
  }
  while (a > 0) {
    if (prevCarry == 1) {
      if (a % 2 == 1) {
        res = res + to_string(0);
        prevCarry = 1;
      } else {
        res = res + to_string(1);
        prevCarry = 0;
      }
    } else {
      res = res + to_string(a % 2);
    }
    a /= 10;
  }

  while (b > 0) {
    if (prevCarry == 1) {
      if (b % 2 == 1) {
        res = res + to_string(0);
        prevCarry = 1;
      } else {
        res = res + to_string(1);
        prevCarry = 0;
      }
    } else {
      res = res + to_string(b % 2);
    }
    b /= 10;
  }

  if (prevCarry == 1) {
    res = res + to_string(1);
  }
  return revString(res);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  // Sum of n natural numbers

  int n;
  cout << "Enter n upto which you want to sum up natural numbers : ";
  cin >> n;
  cout << sumOfNatural(n) << endl;

  // Check pythagorian triplet
  int a, b, c;
  cout << "Enter a triplet : ";
  cin >> a >> b >> c;
  if (pythTriplet(a, b, c))
    printf("Given numbers %d, %d and %d form a pythagorian triplet", a, b, c);
  else
    printf("Numbers %d, %d and %d do not form a pythagorian triplet", a, b, c);

  cout << endl;

  // Conversions

  // Binary to Decimal handler
  int binNum;
  cout << "Enter Binary Number : ";
  cin >> binNum;

  cout << "Decimal Form of the above Binary : " << bin2dec(binNum) << endl;

  // Octal to Decimal handler

  int octNum;
  cout << "Enter Octal Number : ";
  cin >> octNum;

  cout << "Decimal Form of the above Octal : " << oct2dec(octNum) << endl;

  // Hexadecimal to Decimal Handler

  char hexNum[10];
  cout << "Enter Hexadecimal Number : ";
  scanf("%s", hexNum);
  cout << "Decimal Form of the above Hexadecimal : " << hex2dec(hexNum) << endl;

  // Decimal to Binary Handler

  int decNum;
  cout << "Enter a Decimal Number : ";
  cin >> decNum;

  cout << "The binary equivalent of " << decNum << " is " << dec2bin(decNum)
       << endl;

  // Decimal to Octal Handler

  cout << "Enter a decimal Number : ";
  cin >> decNum;

  cout << "The octal equivalent of " << decNum << " is " << dec2oct(decNum)
       << endl;

  // Decimal to Hexadecimal Handler

  cout << "Enter a decimal Number : ";
  cin >> decNum;
  cout << "The octal equivalent of " << decNum << " is " << dec2hex(decNum)
       << endl;

  // Adding binary numbers

  cout << "Enter two binary numbers : ";
  cin >> a >> b;
  cout << addBinary(a, b) << endl;

  return 0;
}