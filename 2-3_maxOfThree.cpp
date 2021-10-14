#include <iostream>

using namespace std;

int main() {
  int a, b, c, max;
  cout << "Enter three numbers : ";
  cin >> a >> b >> c;
  cout << "The maximum of the three is : ";
  (a >= b) ? (a >= c ? max = a : max = c) : (b >= c ? max = b : max = c);
  cout << max << endl;
  return 0;
}