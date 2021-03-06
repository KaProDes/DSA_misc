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

// [3] TOH() handler

void TOH(int n, char s, char d, char h) {
  static int count = 0;
  if (n == 1) {
    printf("Step[%d] : Move disk %d from %c to %c\n", ++count, n, s, d);
    return;
  }

  TOH(n - 1, s, h, d);
  printf("Step[%d] : Move disk %d from %c to %c\n", ++count, n, s, d);
  TOH(n - 1, h, d, s);
}

// [4] removeRepeatingRec() function

string removeRepeatingRec(string s) {
  if (s.length() == 1)
    return s;
  if (s[0] == s[1]) {
    s = removeRepeatingRec(s.substr(1));
  } else {
    s = s[0] + removeRepeatingRec(s.substr(1));
  }
  // cout << s << endl;
  return s;
}

// [5] moveAllXToEnd() function

string moveAllXToEnd(string s) {
  if (s == "")
    return "";

  if (s[0] == 'x')
    return moveAllXToEnd(s.substr(1)) + 'x';
  else
    return s[0] + moveAllXToEnd(s.substr(1));
}

// [6] printAllSubstring() function

void printAllSubseq(string s, string ans) {
  if (s.length() == 0) {
    cout << ans << " ";
    return;
  }
  char ch = s[0];
  string restString = s.substr(1);

  printAllSubseq(restString, ans);
  printAllSubseq(restString, ans + ch);
}

// [8] keypadTranslate() function

void keypadTranslate(string s, string ans, string keypadArr[]) {
  if (s.length() == 0) {
    cout << ans << " ";
    return;
  }
  char ch = s[0];
  string code = keypadArr[ch - '0'];
  string restOfString = s.substr(1);

  for (int i = 0; i < code.length(); i++) {
    keypadTranslate(restOfString, ans + code[i], keypadArr);
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
  printf("\n");

  // [3] Tower of hanoi
  /*
    Good source
    https://www.youtube.com/watch?v=l45md3RYX7c&ab_channel=AdityaVerma
  */

  // TOH() handler
  n = 4;
  TOH(n, 'S', 'D', 'H');

  // [4] remove the repeating consecutive characters from a string recursively

  // removeRepeatingRec() handler
  string s1 = "aaaabbbeeecdddd";
  string revs1 = removeRepeatingRec(s1);
  cout << "The duplicate eliminated form of " << s1 << " is " << revs1 << endl;

  // [5] move all x's to the end of the string recursively
  /*
    Eg :  init  : aaxbfxexedxaax
          final : aabfeedaaxxxxx
  */

  // moveAllXToEnd() handler
  s1 = "aaxbfxexedxaax";
  string mods1 = moveAllXToEnd(s1);
  cout << "The x modified form of " << s1 << " is " << mods1 << endl;

  // [6] recursively print all subsequences of a given string
  /*
    Eg : ABC
          prints : _,A,B,C,AB,BC,AC,ABC
  */

  // printAllSubseq() handler
  printAllSubseq("ABC", "");

  // [7] Subsequence with ASCII code (Not completed)
  cout << endl;
  // [8] Keypad string output
  string keypadArr[] = {"",    "./",  "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
  string numInput = "24";

  keypadTranslate(numInput, "", keypadArr);
  return 0;
}