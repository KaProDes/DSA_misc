#include <iostream>
using namespace std;
int main() {
  cout << "This is the way to print out something\n";

  int sum;
  int amt1, amt2;
  cout << "Enter amount 1 : ";
  cin >> amt1;

  cout << "Enter amount 2: ";
  cin >> amt2;

  sum = amt1 + amt2;

  cout << "Total amount : " << sum;
  return 0;
}