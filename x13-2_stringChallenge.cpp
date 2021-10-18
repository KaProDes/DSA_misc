#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

// function to convert string to lowercase
string convertToLowerCase(string s1) {
  int i = 0;
  while (s1[i] != '\0') {
    if (s1[i] >= 65 && s1[i] <= 91)
      s1[i] = s1[i] + 32;
    i++;
  }
  return s1;
}

// function for sorting numeric string (largest number problem)

void sortDecreasingString(string &num) {
  int n = num.size();
  for (int i = 0; i < n - 1; i++) {
    int j = i + 1;
    int key = num[j];
    while (key > num[j - 1] && j > 0) {
      num[j] = num[j - 1];
      j--;
    }
    num[j] = key;
  }
  cout << num << endl;
}

// function for maximum frequency character

void maxFreqChar(string &str) {
  int freq[26];
  for (int i = 0; i <= 25; i++) {
    freq[i] = 0;
  }
  int i = 0;
  while (str[i] != '\0')
    freq[str[i++] - 'a']++;

  int maxFreq = INT_MIN;
  char freqChar;
  for (i = 0; i <= 25; i++) {
    if (maxFreq < freq[i]) {
      maxFreq = freq[i];
      freqChar = (char)(97 + i);
    }
  }
  printf("The most frequent character is %c\n", freqChar);
}

int main() {
  string s1 = "BAcVErCUi";
  s1 = convertToLowerCase(s1);
  cout << s1 << endl;

  // [1] transform -- toupper
  transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
  // transform -- tolower
  // transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  cout << s1 << endl;

  // [2] Largest number that can be formed from a given string
  string num = "4393984929";
  sortDecreasingString(num);

  // [3] character with highest frequency (assume all chars are lowercase)
  string str = "abcacbade";
  maxFreqChar(str);
}