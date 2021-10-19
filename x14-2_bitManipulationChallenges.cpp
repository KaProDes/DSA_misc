#include <cmath>
#include <iostream>

using namespace std;

// [1] checkPowerOf2() function

bool checkPowerOf2(int n) {
  if (n == 0)
    return false;
  int logicalAnd = n & n - 1;
  return !logicalAnd;
}

// [2] noOfSetBits() function

int noOfSetBits(int n) {
  int count = 0;
  while (n) {
    count++;
    n = n & n - 1;
  }
  return count;
}

// [3] printAllSubsets() function

void printAllSubsets(int *arr, int n) {
  for (int i = 0; i < (1 << n); i++) {
    int subsetInd = i;
    printf("Subset %d : { ", subsetInd);
    for (int j = 0; j < n; j++) {
      int mask = 1 << j;
      if (mask & subsetInd)
        cout << arr[j] << " ";
    }
    cout << "}\n";
  }
}

int main() {
  // [1] check if a number is power of 2 or not
  /*
    Approach :
      if we bitwise AND a power of 2 and its preceeding number
      we always get 0
      for other numbers, results are non-zero

      Eg1 : 8 : 1000
            7 : 0111
            --------
            & : 0000
      Eg2 : 6 : 0110
            5 : 0101
            --------
            & : 0100
  */

  // checkPowerOf2() handler
  int n1 = 16;
  int n2 = 14;
  int n3 = 17;

  int nums[] = {n1, n2, n3};
  for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
    if (checkPowerOf2(nums[i]))
      printf("%d is a power of 2\n", nums[i]);
    else
      printf("%d is not a power of 2\n", nums[i]);
  }
  cout << endl;
  // [2] Check number of a set bits (1) in given number's binary
  /*
    Approach : Repeatedly perform n&n-1 until we get a 0
    1]
    14 : 1110
    13 : 1101
    ---------
    2]
    &  : 1100
    &-1: 1011
    ---------
    3]
    &  : 1000
    &-1: 0111
    ---------
    &  : 0000

    Iterations : 3, no of set bits = 3
  */

  // noOfSetBits() handler
  for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
    printf("Number of set bits in %d is %d\n", nums[i], noOfSetBits(nums[i]));
  }

  // [3] Print all subsets of a given set

  int arr[] = {10, 20, 30};
  printAllSubsets(arr, sizeof(arr) / sizeof(int));
  return 0;
}