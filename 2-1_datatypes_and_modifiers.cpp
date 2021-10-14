#include <iostream>

using namespace std;

int main() {
  int a;
  a = 12;

  cout << "size of int" << sizeof(a) << endl;

  float b;
  b = 12.5;

  cout << "size of float" << sizeof(b) << endl;

  char c;
  c = '#';

  cout << "size of char" << sizeof(c) << endl;

  bool d;
  d = 1;

  cout << "size of bool" << sizeof(d) << endl;

  short int si;
  long int li;

  cout << "size of shortint" << sizeof(si) << endl;
  cout << "size of longint" << sizeof(li) << endl;

  return 0;
}