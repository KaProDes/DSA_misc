#include <iostream>
#include <vector>

using namespace std;

// [1] allPermutationsStr() function

void allPermutationsStr(string baseStr, string ansStr) {
  // Base case -- if baseStr is empty (VaryingStr part) print ansStr and return
  if (baseStr.length() == 0) {
    cout << ansStr << " ";
    return;
  }

  for (int i = 0; i < baseStr.length(); i++) {
    char fixedChar = baseStr[i];
    string VaryingStr = baseStr.substr(0, i) + baseStr.substr(i + 1);
    string fixedStr = ansStr + fixedChar;
    allPermutationsStr(VaryingStr, fixedStr);
  }
}

// [2] allPermutationsArray() function

void allPermutationsArray(vector<int> baseArr, vector<int> ansArr) {

  if (baseArr.size() == 0) {
    for (int i = 0; i < ansArr.size(); i++)
      cout << ansArr[i] << " ";
    cout << endl;
    return;
  }

  for (int i = 0; i < baseArr.size(); i++) {
    int fixedElement = baseArr[i];
    vector<int> varyingArr;
    for (int j = 0; j < baseArr.size(); j++) {
      if (i != j)
        varyingArr.push_back(baseArr[i]);
    }
    vector<int> fixedArr = ansArr;
    fixedArr.push_back(fixedElement);
    allPermutationsArray(varyingArr, fixedArr);
  }
}

// NoOfPaths() function

int NoOfPaths(int start, int end) {
  if (start > end) {
    return 0;
  }
  if (start == end) {
    return 1;
  }
  int count = 0;
  for (int i = 1; i <= 6; i++) {
    count += NoOfPaths(start + i, end);
  }
  return count;
}

// NoOfPathsGrid() function

int NoOfPathsGrid(int n, int i, int j) {
  if (i == n && j == n) {
    return 1;
  }
  if (i > n || j > n) {
    return 0;
  }
  return NoOfPathsGrid(n, i + 1, j) + NoOfPathsGrid(n, i, j + 1);
}

int main() {
  // [1] all possible permutations of a string recursively
  /*
    Approach : Fix one character, permutate the rest of the string
                   A B C
              A,BC  B,AC  C,AB
      AB,C AC,B  BA,C  BC,A  CA,B CB,A
  */

  // allPermutationsStr() handler

  string baseStr = "ABC";
  string ansStr = "";
  allPermutationsStr(baseStr, ansStr);

  // [2] all possible permutations of an array recursively

  /*Approach very similar to string*/

  // allPermutationsArray() hander [not working]

  vector<int> baseArr = {1, 2, 3};
  vector<int> ansArr;

  allPermutationsArray(baseArr, ansArr);
  cout << endl;

  // [3] Number of paths from start to the end of the game board
  /*
    Please read problem statement
  */

  // NoOfPaths() handler
  int start = 1;
  int end = 4;
  cout << "Number of paths from " << start << " to " << end << " : "
       << NoOfPaths(start, end) << endl;

  // [4] No of paths from top left to bottom right of a square grid
  /*
    We are at the top left of a grid and our goal is to go to the bottom right
    recursively We can at any given moment take one of 2 moves : Go down or Go
    Right Find number of paths from Top left to bottom right
  */

  // NoOfPathsGrid() handler

  int n = 3;
  cout << "No of paths from top left to bottom right are "
       << NoOfPathsGrid(n, 1, 1) << endl;
  return 0;
}