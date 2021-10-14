#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  // for loop factorials

  int n;
  cout << "Enter a number to calculate factorial of : ";
  cin >> n;

  int res = 1;
  if (n == 0 || n == 1)
    ;
  else {
    for (int i = 2; i <= n; i++)
      res *= i;
  }
  cout << res << endl;

  // while loop
  cout << "Enter a number to reverse : ";
  cin >> n;

  while (n) {
    cout << n % 10;
    n /= 10;
  }
  cout << endl;

  // do while loop
  srand(time(0));
  int userInput, random;

  do {
    random = rand() % 10;
    cout << "Guess the number (0-9) : ";
    cin >> userInput;
    cout << "Your guess : " << userInput << "\tActual Number : " << random
         << endl;
  } while (userInput != random);

  return 0;
}