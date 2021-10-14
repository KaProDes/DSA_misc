#include <cmath>
#include <iostream>

using namespace std;

// Function for prime range
bool isPrime(int num) {
  if (num == 1)
    return false;
  if (num == 2)
    return true;
  for (int i = 2; i <= sqrt(num); ++i) {
    if (num % i == 0)
      return false;
  }
  return true;
}

// Fibonacci Printing function

void fib(int n) {
  int a = 0;
  int b = 1;
  if (n == 1) {
    cout << a;
    return;
  }
  cout << a << " " << b << " ";
  for (int i = 1; i <= n - 2; i++) {
    int c = a + b;
    a = b;
    b = c;
    cout << c << " ";
  }
}

// Factorial function

int fact(int n) {
  if (n == 0 || n == 1)
    return 1;

  int total = 1;
  for (int i = 1; i <= n; ++i) {
    total *= i;
  }

  return total;
}

// Binary coefficient

int binCoef(int n, int r) { return fact(n) / fact(n - r) / fact(r); }

// Pascal Triangle

int pascalTriangle(int n) {
  cout << endl;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      cout << binCoef(i, j) << " ";
    }
    cout << endl;
  }
}

// Main

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif

  // Prime Numbers function handler
  int l, u;
  cout << "Enter upper and lower bound of the range : ";
  cin >> l >> u;
  if (l > u || l <= 0 || u <= 0) {
    cout << "Sorry, invalid range!" << endl;
    return 0;
  }

  for (int i = l; i <= u; ++i) {
    if (isPrime(i))
      cout << i << " ";
  }

  cout << endl;

  // Fibonacci handler
  int n;
  cout << "Enter the number of fibonacci numbers to print : ";
  cin >> n;
  fib(n);

  cout << endl;

  // Factorial of a number
  cout << "Enter number to calculate factorial for : ";
  cin >> n;
  cout << fact(n) << endl;

  // Binary coefficient handler
  int r;

  cout << "Enter n and r of the binary coefficient : ";
  cin >> n >> r;
  cout << binCoef(n, r) << endl;

  // Pascal Triangle

  /*
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
  */

  cout << "Enter height of the pascal triangle : ";
  cin >> n;

  pascalTriangle(n);

  return 0;
}