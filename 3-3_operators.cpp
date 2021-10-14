#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  // [*] Binary operators : +,-,*,/,%

  // [*] Unary operators : ++ and --
  // Pre : ++a and --a
  // Post : a++ and a--
  // Similarly sizeof()

  int a = 10;
  int b = ++a;
  cout << a << " " << b << endl;
  a = 10;
  b = a++;
  cout << a << " " << b << endl;

  // More examples

  int i = 1;
  i = i++ + ++i;
  cout << "i : " << i << endl;

  // Next
  i = 1;
  int j = 2;
  int k;

  k = i + j + i++ + j++ + ++i + ++j;
  cout << "k : " << k << endl;

  // Next
  i = 0;
  i = i++ - --i + ++i - i--;
  cout << "i : " << i << endl;

  // Next

  i = 1, j = 2, k = 3;

  int m = i-- - j-- - k--;
  cout << "i,j,k,m : " << i << " " << j << " " << k << " " << m << endl;

  // Next

  i = 10, j = 20;
  //  10 - 9 + 19 - 20 + 9 - 20 + 10 - 19
  k = i-- - i++ + --j - ++j + --i - j-- + ++i - j++;
  // i 10 , j  20 , k -20

  cout << "i : " << i << " j : " << j << " k : " << k << endl;

  // [*] Relational Operators : Always return True (1) or False(0) :
  //==,!=, >, <, >=, <= Trivial

  // [*] Logical Operators : AND : x && y , OR : x || y , NOT : !x

  // Divisible by 2 or 3 but not by both (XOR)

  int foo = 9;
  ((foo % 3 == 0) && !(foo % 2 == 0)) || (!(foo % 3 == 0) && (foo % 2 == 0))
      ? cout << "Divisible by either but not both" << endl
      : cout << "Divisble by both or neither" << endl;

  // [*] Bitwise operators : &, |, ^, ~, >> ,<<

  int x = -32;
  x = x >> 2;
  cout << x << endl;

  // [*] Assignment operators : =,+=,-=,*=,/=,%=

  // Misc Operators : PUMAS REBL TAC
  // ternery, (datatype), comma operator, &(reference), *(pointer)
  return 0;
}