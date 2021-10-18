#include <climits>
#include <iostream>

using namespace std;

// functions to exchange the values of two variables

void exchange(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int a = 10;
  int *aptr;
  aptr = &a; // address of a stored in haryana

  cout << &a << endl;    // address of a
  cout << aptr << endl;  // hex print
  printf("%u\n", aptr);  // unsigned int print (decimal)
  printf("%u\n", &a);    // unsigned int print (decimal)
  cout << *aptr << endl; // hex print

  *aptr = 20; // manipulating content using pointers
  cout << a << endl << endl;

  // Pointer arithmetic
  // Note : int is 4B on my machine
  cout << "Original address : " << aptr << endl; // 0x61ff08
  aptr++; //(newAddr = currAddr + sizeof(int)*1)
  cout << "After incrementing address : " << aptr << endl; // 0x61ff0c
  aptr = aptr - 2; //(newAddr = currAddr - sizeof(int)*2)
  cout << "After subtracting 2 from it : " << aptr << endl; // 0x61ff04

  // Pointer arithmetic over chars
  cout << endl;
  char ch = 'k';
  char *chptr = &ch;

  cout << "Original address : " << chptr << endl; // 0x61ff08
  chptr++; //(newAddr = currAddr + sizeof(char)*1)
  cout << "After incrementing address : " << chptr << endl; // 0x61ff0c
  chptr = chptr - 2; //(newAddr = currAddr - sizeof(int)*2)
  cout << "After subtracting 2 from it : " << chptr << endl; // 0x61ff04

  // Pointers and Arrays
  cout << endl;
  int arr[] = {10, 20, 30, 40};

  cout << "Array base address : " << arr << endl;
  cout << "Array base value : " << *arr << endl;
  cout << "Array index 1 value : " << *(arr + 1) << endl;
  cout << "Array index 2 value + 100 : " << (*(arr + 2) + 100) << endl;

  /*
    Note : array's base pointer cannot be modified
    arr++; // is illegal
    But...
  */

  int *ptr = arr; // Pointer to an array;
  cout << "Pointer to array : " << ptr << "| Array base address : " << arr
       << endl;
  ptr++;
  cout << "pointer to array after we increment it will shift by 4B : " << ptr
       << endl;
  cout << "Value at address ptr will be 20 : " << *ptr << endl;

  // Printing the array using pointers
  ptr = arr;

  for (int i = 0; i <= 3; ++i) {
    printf("%d --- %d\n", *(arr + i), *ptr);
    ptr++;
  }

  // Pointer to pointer

  int n = 22;
  int *nptr = &n;
  int **ptrptr = &nptr;

  printf("n : %d nptr : %p ptrptr : %p *nptr : %d **ptrptr : %d\n", n, nptr,
         ptrptr, *nptr, **ptrptr);

  /*
    Pass by reference : sending number's address to a function for inplace
    modification
    Pass by value : sending number's value to a function
  */

  // swapping two numbers
  int x = 10;
  int y = 20;

  printf("x : %d , y : %d\n", x, y);

  exchange(&x, &y);

  printf("x : %d , y : %d\n", x, y);

  return 0;
}