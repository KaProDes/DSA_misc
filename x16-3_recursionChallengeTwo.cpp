#include <iostream>

using namespace std;

// [1] reverseStringRec() function

void reverseStringRec(char *str, int n, char *revStr) {
  if (n == 0)
    return;
  reverseStringRec(str + 1, n - 1, revStr);
  printf("%c", str[0]);
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
  return 0;
}