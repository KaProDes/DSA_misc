#include <climits>
#include <iostream>

using namespace std;

// [1] isArraySorted() function

bool isArraySorted(int *arr, int n) {
  if (n > 2)
    return (arr[n - 1] >= arr[n - 2]) && isArraySorted(arr, n - 1);
  return true;
}

// [2] printNaturalNumbersDec() function

void printNaturalNumbersDec(int n) {
  printf("%d ", n);
  if (n == 1) {
    printf("\n");
    return;
  } else
    printNaturalNumbersDec(n - 1);
}

// [3] printNaturalNumbersInc() function

void printNaturalNumbersInc(int n) {
  if (n > 1)
    printNaturalNumbersInc(n - 1);
  printf("%d ");
}

// [4] firstAndLastOccurenceInArray() function

void firstAndLastOccurenceInArray(int *arr, int n, int key, int *first,
                                  int *last) {
  if (n > 1) {
    if (arr[n - 1] == key && *last < n) {
      *last = n;
    }
    firstAndLastOccurenceInArray(arr, n - 1, key, first, last);
    if (arr[n - 1] == key && *first > n) {
      *first = n;
    }
  } else {
    if (arr[0] == key && *last < 1) {
      *last = 1;
    }
    if (arr[0] == key && *first > 1) {
      *first = 1;
    }
    return;
  }
}

int main() {
  // [1] check if a given array is sorted or not recursively

  // isArraySorted() handler
  int arr[] = {1, 3, 7, 14, 15, 15, 23};
  int brr[] = {2, 15, 6, 13, 15, 33};

  printf("The array : ");
  for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    printf("%d ", arr[i]);
  if (isArraySorted(arr, sizeof(arr) / sizeof(int)))
    printf("is sorted\n");
  else
    printf("is not sorted\n");

  printf("The array : ");
  for (int i = 0; i < sizeof(brr) / sizeof(int); i++)
    printf("%d ", brr[i]);
  if (isArraySorted(brr, sizeof(brr) / sizeof(int)))
    printf("is sorted\n");
  else
    printf("is not sorted\n");

  // [2] Print numbers from n to 1 using recursion

  // printNaturalNumbersDec() handler
  int n = 7;
  printNaturalNumbersDec(n);

  // [3] Print numbers from 1 to n recursively

  // printNaturalNumbersInc() handler
  printNaturalNumbersInc(n);
  cout << endl;

  // [4] Find the index of
  // first and last occurance of a number in an array recursively

  // firstAndLastOccurenceInArray() handler
  int key = 12;
  int crr[] = {11, 13, 12, 17, 12, 14, 19, 20, 12, 14};
  int first = INT_MAX, last = INT_MIN;
  firstAndLastOccurenceInArray(crr, sizeof(crr) / sizeof(int), key, &first,
                               &last);
  printf("First occurence of %d at %d, last at %d\n", key, first, last);

  return 0;
}