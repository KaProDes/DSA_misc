#include <iostream>

using namespace std;

// [1] countOfDivisible() function

int countOfDivisible(int n, int a, int b) {
  int c1 = n / a;
  int c2 = n / b;

  int c3 = n / (a * b);
  return c1 + c2 - c3;
}

// [2] euclidGCD() function

int euclidGCD(int m, int n) {
  if (n <= 0)
    return -1;
  while (m % n != 0) {
    int max = m > n ? m : n;
    int min = m + n - max;
    n = max % min;
    m = min;
  }
  return n;
}

int main() {
  // [1] finding count of numbers divisible by 2 numbers a or b in a range
  /*
    Approach :
    c1 -> divisible by a, c2-> divisible by b
    c3 -> divisible by both
    then total count by either = c1+c2-c3 // inclusion-exclusion
  */

  // countOfDivisible() handler
  int n = 100;
  int a = 5, b = 7;

  printf("Count of numbers divisible by %d or %d upto %d is %d\n", a, b, n,
         countOfDivisible(n, a, b));

  // [2] Euclid's GCD algo for two numbers a,b
  /*
    for two numbers a,b,
    GCD(a,b) = GCD(b,a-b) = GCD(a-b,b-(a-b)) and so on...
    Eg : 42,24 - m,n
        42 % 24 = 18
        24,18 - m,n
        24 % 18 = 6
        18,6 - m,n
        18 % 6 = 0 ---> stop, smaller number is the GCD
        i.e GCD(42,24) = 6
  */

  // euclidGCD() handler
  a = 42, b = 24;
  printf("The GCD of %d and %d is %d", a, b, euclidGCD(a, b));

  // Additional Notes : Try to find GCD by prime factorization

  return 0;
}