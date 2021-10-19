#include <cmath>
#include <iostream>

using namespace std;

// helper function to check if kth bit is set in n

bool checkIfSet(int n, int k) {
  int mask = 1 << k;
  return mask & n;
}

// helper function to set the kth bit of number n

int setBit(int n, int k) { return n | (1 << k); }

// helper function to get the kth bit of number n

int getBit(int n, int k) { return n & (1 << k); }

// [1] nonRepeatingNumber() function

int nonRepeatingNumber(int *arr, int n) {
  int xorVal = 0;
  for (int i = 0; i < n; i++)
    xorVal ^= arr[i];
  return xorVal;
}

// [2] uniqueNonPairNumbers() function

void uniqueNonPairNumbers(int *arr, int n, int *res) {
  int xorVal = 0;
  for (int i = 0; i < n; i++)
    xorVal ^= arr[i];

  // Find the lsb that is set in xorVal
  int pos = 0;
  int setBit = 0;
  int xorValCopy = xorVal;
  while (setBit != 1) {
    setBit = xorValCopy & 1;
    pos++;
    xorValCopy >>= 1;
  }
  pos--; // now contains the pos of rightmost set bit

  int num1 = 0;
  for (int i = 0; i < n; i++) {
    if (checkIfSet(arr[i], pos)) {
      num1 ^= arr[i];
    }
  }
  res[0] = num1;
  res[1] = xorVal ^ num1;
}

// uniqueInSetOfThrees() function

int uniqueInSetOfThrees(int *arr, int n) {
  int result = 0;
  for (int i = 0; i < 31; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (getBit(arr[j], i))
        sum++;
    }
    if (sum % 3 != 0)
      result = setBit(result, i);
  }
  return result;
}

int main() {
  // [1] find the non-repeating number from the array
  /*
    Array contains every number in pairs of 2 except 1 number
    Find that number (all numbers non zero)
    Approach : take XOR of all the numbers, it will give the
    non duplicate number
    Eg : 2, 4, 6, 3, 4, 6, 2
          return 3
    Think of why it works ...
  */

  // nonRepeatingNumber() handler
  int arr[] = {2, 4, 6, 3, 4, 6, 2};
  printf("The non-repeating number is : %d\n",
         nonRepeatingNumber(arr, sizeof(arr) / sizeof(int)));

  // [2] find 2 unique non-pair numbers in an array
  /*
    Eg : 2,4,6,7,4,5,6,2
    return 5,7
  */

  // uniqueNonPairNumbers() handler
  int brr[] = {2, 4, 6, 7, 4, 5, 6, 2};
  int res[2];
  uniqueNonPairNumbers(brr, sizeof(brr) / sizeof(int), res);
  printf("The non-repeating numbers in the array are %d and %d\n", res[0],
         res[1]);

  // [3] unique number in groups of three
  /*
    Array contains 1 unique solo number and all other numbers in groups of 3
    find the solo number
    Eg :  1,3,2,5,3,2,1,1,3,2 return 5
    Approach: initialize result as 0
    tally up all the numbers with kth bit set
    if such a tally is not divisible by 3, set this kth bit in result
    do this for all k from 0 to 31
  */

  // uniqueInSetOfThrees() handler
  int crr[] = {12, 36, 27, 47, 36, 27, 12, 12, 36, 27};
  int unique = uniqueInSetOfThrees(crr, sizeof(crr) / sizeof(int));
  printf("The unique number in set of 3's is %d\n", unique);

  return 0;
}