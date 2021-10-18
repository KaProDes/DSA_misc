#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif

  // Taking string input
  string str;
  cin >> str;
  cout << str << endl;
  cin.ignore();

  // String input with spaces
  string s1;
  getline(cin, s1);
  cout << s1 << endl;

  // Raw declaring string
  string s2 = "Some sentence";
  cout << s2 << endl;

  // Initialize with same characters
  string s3 = string(5, 'k');
  cout << s3 << endl;

  // Concatenation styles
  s1 = "hello ";
  s2 = "there ";

  cout << s1 + s2 << endl;
  s1.append(s2);
  cout << s1 << endl;

  // single character access
  cout << "Second char : " << s1[1] << endl;

  // C++ strings are modifiable
  s1[1] = 'a';
  cout << "After modification : " << s1 << endl;

  // Clearing the string
  cout << "Before clearing : " << s3 << endl;
  s3.clear();
  cout << "After clearing : " << s3 << endl;
  // Another way
  s3 = "bruh";
  cout << "Before clearing : " << s3 << endl;
  s3 = "";
  cout << "After clearing : " << s3 << endl;

  // Comparting strings
  s1 = "xyz";
  s2 = "abc";
  cout << s1.compare(s2) << endl; // 1 if s1 is greater, -1 if  s2 greater

  s1 = "bruh";
  s2 = "bruh";
  cout << s1.compare(s2) << endl; // 0

  // Checking empty string
  cout << "Empty ? : " << s1.empty() << endl; // False : 0
  s1.clear();
  cout << "Empty ? : " << s1.empty() << endl; // True : 1

  // Erasing elements
  s1 = "hippopotomonstrosesquippedaliophobia";
  cout << "Before erase : " << s1
       << endl;    // hippopotomonstrosesquippedaliophobia
  s1.erase(5, 25); // (start,noOfChars)
  cout << "After erase : " << s1 << endl; // hippophobia

  // Find substring within string
  s1 = "hippopotomonstrosesquippedaliophobia";
  cout << "Substring found at : " << s1.find("pedal") << endl;

  // Insert a string in a string
  s1 = "dysctional";
  s2 = "fun";
  cout << "Before insert : " << s1 << endl;
  s1.insert(3, s2); // (startPoint,stringToInsert)
  cout << "After insert : " << s1 << endl;

  // Finding length of a string
  cout << "The size of string " << s1 << " is " << s1.size() << endl;
  cout << "The length of string " << s1 << " is " << s1.length() << endl;
  int i = 0;
  while (s1[i] != '\0')
    i++;
  cout << "The number of chars in the string " << s1 << " are " << i << endl;

  // substring of a given string
  int start = 3, end = 6;
  cout << "Required substring : " << s1.substr(3, 6 - 3)
       << endl; //(startInd,noOfChars)

  // substring iterative method
  cout << "Required substring (iterative): ";
  for (int i = start; i < end; i++)
    cout << s1[i];
  cout << endl;

  // string to integer
  string sNum = "123";
  cout << "The string number : " << sNum << endl;
  int x = stoi(sNum);
  cout << "Proof of number by predecrement : " << --x << endl;

  // to string

  int y = 356;
  sNum = to_string(y);
  cout << "The string + 2 : " << sNum + to_string(2)
       << " The number + 2 : " << y + 2 << endl;

  // Lexicographical sort

  string seq = "ibdjebjebjksfjbk";
  sort(seq.begin(),
       seq.end()); // sorting using iterator (strings/vectors supported)
  cout << "Lexicographical order :" << seq;
  return 0;
}