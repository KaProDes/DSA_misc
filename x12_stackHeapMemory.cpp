#include <iostream>

using namespace std;

void exchange(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  /*
    Stack Memory Alloc:
    Memory is allocated on the function call stack.
    Deallocated when function call gets over
    Deallocation handled by compiler

    Heap Memory Alloc :
    Allocation takes place on pile memory available for programs to
    alloc/dealloc Alloc, Dealloc handled by programmer

    Note, arrays can be scaled up and freed up during runtime if allocated on
    heap
  */

  // Sample program to allocate and deallocate dynamic memory on heap
  int *p = new int();
  int *q = (int *)malloc(sizeof(int));

  *p = 10;
  *q = 20;
  printf("%d %d\n", *p, *q);
  exchange(p, q);
  printf("%d %d\n", *p, *q);

  // Reallocate
  p = new int[10];
  q = (int *)realloc(q, sizeof(int) * 10);

  // Deallocate

  delete[] p; // p is now dangling (pointing to a non-authorized location)
  free(q);    // q is now dangling
  p = NULL;
  q = NULL;

  return 0;
}