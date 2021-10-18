#include <climits>
#include <iostream>

using namespace std;

// function to check pallindrome

bool checkPallindrome(char *word) {
  // find length of the string
  int n = 0;
  while (word[n] != '\0')
    n++;
  n--;
  for (int i = 0; i < n / 2; i++) {
    if (word[i] != word[n - i])
      return false;
  }
  return true;
}

// function to evaluate longest word length in sentence

int longestWordLength(char *sentence) {
  int maxLength = INT_MIN;
  int i = 0;
  int currLength = 0;
  int start = 0, end = 0;
  int maxWStart, maxWEnd;

  while (sentence[i] != '\0') {
    if (sentence[i] == ' ') {
      currLength = 0;
      start = end = i + 1;
    } else {
      currLength++;
      end++;
      if (maxLength < currLength) {
        maxLength = currLength;
        maxWStart = start;
        maxWEnd = end;
      }
    }
    i++;
  }
  cout << "Longest Word : ";
  for (int i = maxWStart; i <= maxWEnd; i++)
    cout << sentence[i];
  cout << endl;
  return maxLength;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif

  // Declaring char array and \0 as an autoadded terminator
  char arr[100] = "char array";
  int i = 0;
  while (arr[i] != '\0') {
    cout << arr[i] << endl;
    i++;
  }

  // Char array input output (spaces will cause breaks)
  char charArr[100];
  cin >> charArr;
  cout << charArr << endl;

  // accessing particular element
  cout << charArr[0] << endl;

  // [1] check if pallindrome
  char word[100];
  cin >> word;
  if (checkPallindrome(word)) {
    cout << word << " is a pallindrome" << endl;
  } else {
    cout << word << " is not a pallindrome" << endl;
  }

  // [2] longest word in a sentence
  char sentence[100] = "calculus has limits and integration";
  cout << sentence << endl;
  cout << "Longest word in the sentence is " << longestWordLength(sentence)
       << " characters long" << endl;
  return 0;
}

/*
  input.txt dump:

  shrek malayalam
*/