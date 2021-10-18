#include <climits>
#include <iostream>

using namespace std;

// function to print all subarrays of the given array

// helper function printSubarray()

void printSubarray(int *arr, int startInd, int endInd) {
  static int count = 1;
  cout << "Subarray Number " << count++ << " : ";
  ;
  for (int i = startInd; i <= endInd; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

void generateSubArrays(int *arr, int n) {
  cout << "Here are the " << n * (n + 1) / 2 << " subarrays : " << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      printSubarray(arr, i, j);
    }
  }
}

// Brute : function for maximum subarray sum O(n^3)

void maxSubarraySumBrute(int *arr, int n) {
  int maxSum = INT_MIN;
  int minInd, maxInd;
  // Generate all arrays and check
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int tempSum = 0;
      for (int k = i; k <= j; k++) {
        tempSum += arr[k];
      }
      if (tempSum > maxSum) {
        maxSum = tempSum;
        minInd = i;
        maxInd = j;
      }
    }
  }
  printf("Maximum sum : %d for subarray arr[%d,%d] i.e. subarray : ", maxSum,
         minInd, maxInd);
  printSubarray(arr, minInd, maxInd);
}

// Optimal : function for maximum subarray sum O(n+n^2)

void maxSubarraySumOptimal(int *arr, int n) {
  // Generating cumSum array
  int cumSum[n + 1];

  cumSum[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    cumSum[i] = cumSum[i - 1] + arr[i - 1];
  }
  cout << endl;

  // Calculating for optimality for all n subarrays
  int maxSum = INT_MIN;
  int subArraySum;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      // sum of subarray[i,j]

      subArraySum = cumSum[j + 1] - cumSum[i];

      if (maxSum < subArraySum)
        maxSum = subArraySum;
    }
  }
  cout << "Maximum Sum cummulative sum approach : " << maxSum << endl;
}

// Optimal : maximum subarray sum kadane method (O(n))

int maxSubarraySumKadane(int *arr, int n) {
  int kadane[n];
  int currSum = 0;
  int maxSum = INT_MIN;
  for (int i = 0; i < n; ++i) {
    if (arr[i] < 0) {
      currSum = 0;
    } else {
      currSum += arr[i];
    }
    if (maxSum < currSum)
      maxSum = currSum;
  }

  return maxSum;
}

// Max circular subarray sum using kadane

void maxCircularSubarraySum(int *arr, int n) {
  // Max subarray sum = Total sum of array - sum of nonContributing elements

  int wrapSum;
  int nonWrapSum;
  int totalSum = 0;

  nonWrapSum = maxSubarraySumKadane(arr, n);
  // Changing sign of the array
  for (int i = 0; i < n; ++i) {
    totalSum += arr[i];
    arr[i] = -arr[i];
  }
  wrapSum = totalSum + maxSubarraySumKadane(arr, n);

  cout << "Max Circular subarray sum : " << max(nonWrapSum, wrapSum) << endl;
}

// Brute : function to check pairSum

bool pairSum(int arr[], int k, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (arr[i] + arr[j] == k) {
        printf("Brute : a[%d]+a[%d] = %d\n", i, j, k);
        return true;
      }
    }
  }
  return false;
}

// Optimal : function to check pairSum -- array must be sorted

bool pairSumOptimal(int arr[], int k, int n) {
  int i = 0, j = n - 1;
  int sum;
  while (i < j) {
    sum = arr[i] + arr[j];
    if (sum == k) {
      printf("Optimal : a[%d]+a[%d] = %d\n", i, j, k);
      return true;
    } else if (sum < k)
      i++;
    else if (sum > k)
      j--;
  }
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  // given array
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;

  /*
    1] Print all Subarrays
    Stmt : Print all subarrays of a given array (all n+nC2 = n(n+1)/2 of them)
  */
  generateSubArrays(arr, n);
  cout << endl;
  /*
    2] Maximum Subarray Sum
    Stmt : Given an array find the maximum subarray sum
    Eg : -1 4 7 2
        Maximum subarray sum = 13 for subarray : 4 7 2
  */

  maxSubarraySumBrute(arr, n);
  cout << endl;

  // Optimal approach to previous problem (cummulative sum approach :
  // Memoization)
  /*
    Eg : arr :      -1 4 7 2
        cumSum  : 0 -1 3 10 12
        for sum from (i,j):
          cumSum[j] - cumSum[i-1]
  */

  maxSubarraySumOptimal(arr, n);
  cout << endl;

  // Kadane's algorithm for maximum subarray sum (Greedy? Dynamic? IDK)
  // Maximum sub upto that point with resets
  // If -ve reset sum to 0, if positive sum+=arr[i]
  /*
    Eg : arr :    -1 4 7 2
      cumSum :    -1 3 10 12
      kadane :     0 4 11 13
  */

  cout << "Max sum using kadane : " << maxSubarraySumKadane(arr, n);

  cout << endl;
  // [3] Maximum circular subarray sum using kadane
  // View source material 18:32

  cin >> n;
  int brr[n];
  for (int i = 0; i < n; ++i)
    cin >> brr[i];
  // given array
  for (int i = 0; i < n; ++i)
    cout << brr[i] << " ";
  cout << endl;

  maxCircularSubarraySum(arr, n);

  // [4] pairSum
  /*
    if a[i],a[j] exists within array s.t. a[i]+a[j]==target
       print them and true
    else false
  */

  int crr[] = {2, 4, 7, 11, 14, 16, 20, 21};
  n = 8;
  int k = 31;
  cout << pairSum(crr, k, n) << endl;

  // Optimal approach (Array must be sorted for this to work)
  cout << pairSumOptimal(crr, k, n) << endl;

  return 0;
}

/*
  input.txt dump
  4

-1 4 7 2

7

4 -4 6 -6 10 -11 12
*/