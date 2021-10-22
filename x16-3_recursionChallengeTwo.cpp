#include <iostream>

using namespace std;

// [1] reverseStringRec() function

void reverseStringRec(char *str, int n, char *revStr) {
  if (n == 0) {
    return;
  }
  reverseStringRec(str + 1, n - 1, revStr);
  printf("%c", str[0]);
}

// [2] replacePIRecursively() function

void replacePIRecursively(string s) {
  if (s.length() == 0)
    return;
  if (s[0] == 'p' && s[1] == 'i') {
    printf("3.14");
    replacePIRecursively(s.substr(2));
  } else {
    printf("%c", s[0]);
    replacePIRecursively(s.substr(1));
  }
}

int main() {
  // [1] reverse a string using recursion

  // reverseStringRec() handler
  char str[] = "shrek";
  int n = 0;
  while (str[n++] != '\0')
    ;
  n--;
  char revStr[n];

  printf("The reverse of %s is ", str);
  reverseStringRec(str, n, revStr);
  printf("\n");
  // [2] replace 'pi' with 3.14
  /*
    xpixipxipxpixxpipx
    Replace pi with 3.14 in the string recursively
  */

  // replacePIRecursively() handler
  string s = "xpixipxipxpixxpipx";
  replacePIRecursively(s);

  return 0;
}