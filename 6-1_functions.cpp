#include <iostream>

using namespace std;

// Function for factorial

int factorial(int n) {
  if (n == 1 || n == 0)
    return 1;

  int fact = 1;

  for (int i = 2; i <= n; ++i)
    fact *= i;
  return fact;
}

// Main

int main() {
  int n;
  while (1) {
    cout << "Enter a number to compute factorial (-1 for exiting) : ";
    cin >> n;
    if (n < 0)
      break;
    int fact = factorial(n);
    cout << "The factorial of " << n << " is " << fact << endl;
  }
  return 0;
}