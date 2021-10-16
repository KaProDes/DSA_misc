#include <iostream>

using namespace std;

// max value till index i function

void maxTillIndexi(int *arr, int n) {
  int currMax = arr[0];

  for (int i = 0; i < n; ++i) {
    if (currMax < arr[i]) {
      currMax = arr[i];
    }
    cout << currMax << " ";
  }
  cout << endl << endl;
}

// sum of all subarrays function

// Helper function declaration
int arraySum(int *arr, int startInd, int endInd);

void sumOfSubArrays(int *arr, int n) {
  cout << "Here are all the " << n * (n + 1) / 2
       << " subarrays and their sums : " << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int sum = arraySum(arr, i, j);
      cout << "Sum : " << sum << endl;
    }
  }
}

// Helper function to calculate array sums

int arraySum(int *arr, int startInd, int endInd) {
  static int count = 0;
  int sum = 0;
  cout << "Sub Array " << ++count << " : ";
  for (int i = startInd; i <= endInd; ++i) {
    cout << arr[i] << " ";
    sum += arr[i];
  }
  cout << endl;

  return sum;
}

int longestArithmenticProgressionSubarray(int *arr, int n) {
  int currDiff;
  int maxLen = 2;
  int currLen = maxLen;

  for (int i = 0; i < n - 1; ++i) {
    if (i == 0) {
      currDiff = arr[i + 1] - arr[i];
      continue;
    }
    if (arr[i + 1] - arr[i] == currDiff) {
      currLen++;
      maxLen = max(currLen, maxLen);
    } else {
      currDiff = arr[i + 1] - arr[i];
      currLen = 2;
    }
  }
  return maxLen;
}

// recordBreaker function

int recordBreaker(int *arr, int n) {
  if (n == 1)
    return 1;
  int maxVal = arr[0];
  int days = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1 && arr[i] > maxVal) {
      days++;
    } else if (i == 0 && arr[i] > arr[i + 1]) {
      days++;
    } else if (arr[i] > maxVal && arr[i] > arr[i + 1]) {
      days++;
      maxVal = arr[i];
    }
  }
  return days;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif

  // sample array :
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  // unsorted array
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;

  // Max till i handler
  maxTillIndexi(arr, n);

  /*
    Subarray : A contiguous portion of an array
    Eg : 5 4 6  is a subarray of 1 0 5 4 6 8
    In n element array nC2 + n subarrays exist

    Subsequence : A contiguous/non-contiguous in-order portion of an array
    Eg : 0 4 8 is a subsequence of 1 0 5 4 6 8
    In n element array 2^n subsequences exist

    Every Subarray is a subsequence, converse not necessary
  */

  // Sum of all subarrays of a given array handler
  sumOfSubArrays(arr, n);

  // Longest arithmetic progression subarray length
  /*
    Eg : 10 7 4 6 8 10 11
    Longest AP array : 4 6 8 10 (len = 4)
  */
  // Statement :
  // https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bf4ed

  cin >> n;
  int brr[n];
  for (int i = 0; i < n; ++i)
    cin >> brr[i];

  // given array
  for (int i = 0; i < n; ++i)
    cout << brr[i] << " ";
  cout << endl;

  // Longest arithmetic progression subarray length handler

  cout << longestArithmenticProgressionSubarray(brr, n) << endl;

  // Recording breaking days
  // Statement :
  // https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171

  cin >> n;
  int crr[n];
  for (int i = 0; i < n; ++i)
    cin >> crr[i];

  // given array
  for (int i = 0; i < n; ++i)
    cout << crr[i] << " ";
  cout << endl;

  // Recording breaking days handler

  cout << "No of record breaking days : " << recordBreaker(crr, n) << endl;
  return 0;
}

/*
input.txt dump :

6

1 0 5 4 6 8

7

10 7 4 6 8 10 11

8

1 2 0 7 2 0 2 2

*/