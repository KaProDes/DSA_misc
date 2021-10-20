#include <iostream>

using namespace std;

// [1] printSieveOfEratosthenes() function

void printSieveOfEratosthenes(int min, int max) {
  printf("Primes in range %d to %d are : \n", min, max);
  bool mask[max + 1];
  int i = min > 2 ? min : 2;
  for (; i <= max; i++) {
    mask[i] = true;
  }
  int marker = min > 2 ? min : 2;
  while (marker < max) {
    printf("%d ", marker);
    int k = marker; // start checking from k^2 (can also start at 2)
    while (k * marker <= max) {
      mask[k * marker] = false;
      k++;
    }
    marker++;
    while (mask[marker] == false)
      marker++;
  }
  cout << endl;
}

// [2] sieveFactorization() function

void sieveFactorization(int n) {
  printf("Prime factors of %d are : ", n);
  int spf[n + 1];
  for (int i = 2; i <= n; i++) {
    spf[i] = i;
  }

  int marker = 2;
  while (marker < n) {
    int k = marker;
    while (k * marker <= n) {
      if (spf[k * marker] > marker) {
        spf[k * marker] = marker;
      }
      k++;
    }
    marker++;
    while (spf[marker] != marker)
      marker++;
  }

  // for (int i = 2; i <= n; i++)
  //   cout << spf[i] << " ";

  while (n != 1) {
    printf("%d ", spf[n]);
    n /= spf[n];
  }
  cout << endl;
}

int main() {
  // [1] Program to print primes in a range
  // using sieve of Eratosthenes
  /*
    Use a boolean array to mask off all non-prime multiples of numbers
  */

  // printSieveOfEratosthenes() handler
  int min = 1, max = 50;
  printSieveOfEratosthenes(min, max);

  // [2] Prime factorization using sieve
  /*
    Approach :
    Step 1  : Memoization
    every unmarked number (prime) will lay a claim over the spf(smallest prime
    fact) cell of non-prime numbers
    if the current prime number laying a claim on the spf is smaller than
    current spf, we will update the spf

    Step 2 : Lookup
    At the end, we will continually divide our currNum by its spf until currNum
    becomes 1
  */

  // sieveFactorization() handler
  int n = 144;
  sieveFactorization(n);

  return 0;
}