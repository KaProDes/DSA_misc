#include <climits>
#include <iostream>

using namespace std;

// first repeating element function

int firstRepeatingElement(int *arr, int n) {
  const int N = 100000;

  int minIndexArray[N];
  for (int i = 0; i < N; ++i)
    minIndexArray[i] = -1;

  int minIndex = 1000000;
  for (int i = 0; i < n; i++) {
    if (minIndexArray[arr[i]] != -1)
      minIndex = (minIndex < minIndexArray[i] ? minIndex : minIndexArray[i]);
    else if (minIndexArray[arr[i]] == -1)
      minIndexArray[arr[i]] = i;
  }
  if (minIndex != 1000000)
    return arr[minIndex];
  return -1;
}

// subarray sum function (optimal)
// for brute force approach refer to 8.4

void subArraySum(int arr[], int n, int s) {
  int start = 0, end = 0;
  int sum = 0;
  while (end < n && sum + arr[end] <= s) {
    sum += arr[end];
    end++;
  }

  if (sum == s)
    cout << start << " " << end << endl;

  while (end < n) {
    sum += arr[end];
    while (sum > s) {
      sum -= arr[start];
      start++;
    }
    if (sum == s) {
      start++;
      end++;
      break;
    }
    end++;
  }
  cout << start - 1 << " " << end << endl;
}

// smallest missing positive function

void smallestMissingPositive(int arr[], int n) {
  int N = 1000000;
  bool attendence[N];
  for (int i = 0; i < N; i++) {
    attendence[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0)
      continue;
    attendence[arr[i]] = true;
  }
  int i;
  for (i = 1; i < N; i++)
    if (attendence[i] == false)
      break;

  cout << i << endl;
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

  // given array
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;

  // First repeating element
  /*
    Eg : 1 5 3 4 3 5 6
    ans : 5
    element that occurs more than once and whose index of
    first occurence is the least
  */

  // First repeating element handler
  cout << "The first repeating element is : " << firstRepeatingElement(arr, n)
       << endl;

  // Continuous subarray sum
  /*
    Eg : 1,2,3,7,5 and S = 12
    2,3,7 sums up to 12
    So : indices : 1 to 3
         Subarray : 2,3,7
  */

  // sample array :
  n;
  cin >> n;
  int brr[n];
  for (int i = 0; i < n; ++i)
    cin >> brr[i];

  // given array
  for (int i = 0; i < n; ++i)
    cout << brr[i] << " ";
  cout << endl;
  // target value
  int s;
  cin >> s;

  // Continuous subarray sum handler
  subArraySum(brr, s, n);

  // Smallest positive missing number
  // Given an array containing elements(+ve and -ve) from return smallest number
  // non negative number missing from it
  /*
    Eg : 0 -9 1 3 4 5
    return 2
  */

  cin >> n;
  int crr[n];
  for (int i = 0; i < n; ++i)
    cin >> crr[i];
  // given array
  for (int i = 0; i < n; ++i)
    cout << crr[i] << " ";

  cout << endl;

  // smallest positive missing handler
  cout << "Smallest positive missing number is : ";
  smallestMissingPositive(crr, n);

  return 0;
}

/*
  input.txt dump

7

1 5 3 4 3 5 6

5

1 2 3 7 5

10

6

0 -9 1 3 4 5

*/