#include <iostream>

using namespace std;

// [1] sumRec() function

int sumRec(int n) {
  if (n == 0)
    return 0;
  else
    return n + sumRec(n - 1);
}

// [2] powerByRec() function

int powerByRec(int n, int p) {
  if (p == 0) {
    return 1;
  }
  return n * powerByRec(n, p - 1);
}

// [3] factByRec() function

int factByRec(int n) { return (n == 0 || n == 1) ? 1 : n * factByRec(n - 1); }

// [4] fibonacciByRec() function

int fibonacciByRec(int n) {
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;
  else
    return fibonacciByRec(n - 1) + fibonacciByRec(n - 2);
}

int main() {
  // [1] sum of n natural numbers using recursion

  // sumRec() handler
  int n = 20;
  printf("The recursive natural numbers sum upto %d is %d\n", n, sumRec(n));

  // [2] power by recursion
  /*
    given n and p return n raised to p by recursion
  */
  n = 2;
  int p = 7;
  printf("%d raised to %d is %d\n", n, p, powerByRec(n, p));

  // [3] factorial of a number by recursion

  // factByRec() handler
  n = 7;
  printf("The factorial of %d is %d\n", n, factByRec(n));

  // [4] nth fibonacci number by recursion
  // 0,1,1,2,3,5,8,13,21,34 (1 based counting)

  // fibonacciByRec() handler
  n = 8;
  printf("The no %d fibonacci number is %d\n", n, fibonacciByRec(n));
  return 0;
}