#include <iostream>

using namespace std;

void TOH(int n, char s, char d, char h) {
  static int count = 0;

  if (n == 1) {
    printf("Move %d : Move %d from %c to %c\n", ++count, 1, s, d);
    return;
  }
  TOH(n - 1, s, h, d);
  printf("Move %d : Move %d from %c to %c\n", ++count, n, s, d);
  TOH(n - 1, h, d, s);
}

int main() {
  int n = 3;
  TOH(n, 'S', 'D', 'H');
  return 0;
}