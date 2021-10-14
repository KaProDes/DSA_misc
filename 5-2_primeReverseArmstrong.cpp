#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

using namespace std;

int main() {

  // Optimized Prime number check
  int n;
  cout << "Enter number to check if prime : ";
  cin >> n;
  int flag = 0;
  for (int i = 2; i < ceil(sqrt(n)); ++i) {
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    cout << "Not Prime" << endl;
  } else {
    cout << "Prime" << endl;
  }

  // Reversing a number

  cout << "Enter a number to be reversed : " << endl;
  cin >> n;
  int reverse = 0;
  while (n) {
    reverse = reverse * 10 + (n % 10);
    n /= 10;
  }
  cout << reverse << endl;

  // Armstrong number printing upto 1000
  for (int i = 1; i <= 1000; i++) {
    int num = i;
    int sum = 0;

    while (num) {
      int r = num % 10;
      sum += (r * r * r);
      num /= 10;
    }
    if (i == sum)
      cout << i << " ";
  }
  return 0;
}