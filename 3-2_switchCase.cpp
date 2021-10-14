#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  char switchButton;
  cout << "Enter a button character : ";
  cin >> switchButton;

  // Uppercase detection and conversion to Lowercase
  if (switchButton >= 65 && switchButton <= 97)
    switchButton += 32;

  switch (switchButton) {
  case 'a':
    cout << "Hi" << endl;
    break;
  case 'b':
    cout << "Hola" << endl;
    break;
  case 'c':
    cout << "Salut" << endl;
    break;
  case 'd':
    cout << "Bonjour" << endl;
    break;
  case 'e':
    cout << "Hallo" << endl;
    break;

  default:
    cout << "I'm still learning! I still don't have a programming for : "
         << switchButton << endl;
    break;
  }

  return 0;
}