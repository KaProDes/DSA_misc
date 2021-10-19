#include <iostream>

using namespace std;

// [1] function to get the posth bit of number n

int getBit(int n, int pos) { // Eg : n = 45(101101), pos = 3
  int bitMask = 1 << pos;    // bitMask = 1<<3 i.e. 8(001000)
  int residue = n & bitMask; // residue<-101101 & 001000(nonzero)
  if (residue == 0)
    return 0;
  else
    return 1;
}

// [2] function to set the posth bit of number n

int setBit(int n, int pos) {   // Eg : n = 45 (101101), pos = 4
  int bitMask = 1 << pos;      // bitMask = 1<<4 i.e. (16)010000
  int setOutput = n | bitMask; // setOutput<-101101|010000(111101)
  return setOutput;
}

// [3] function to reset the posth bit of number n

int clearBit(int n, int pos) {   // Eg : n = 45 (101101), pos = 3
  int bitMask = 1 << pos;        // bitMask = 1<<3 i.e. 001000
  bitMask = ~bitMask;            // bitMask = 1's (001000) i.e (110111)
  int resetOutput = n & bitMask; // setOutput <- 101101 & 110111
  return resetOutput;
}

// [4] function to update the posth bit of a number n to bit

int updateBit(int n, int pos, int bit) {
  if (bit == 1)
    return setBit(n, pos);
  else
    return clearBit(n, pos);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif

  // [1] git a particular bit of a number's binary form
  /*
    Eg : 45 --- 101101
          getBit(45,3) should return 1 as 3rd LSB (0 index counting)
          is 1
  */

  // getBit handler
  int n = 45;
  int pos = 3;
  printf("The No. %d bit of %d is %d\n", pos, n, getBit(n, pos));

  // [2] set bit at a specified position
  /*
    Eg : 45 --- 101101
      setBit(45,4) should return 45+16=61 as 4th LSB (0 index counting)
      is gets set to 1 => 111101
  */

  // setBit handler
  n = 45;
  pos = 4;
  printf("After setting the No. %d bit of %d we get %d\n", pos, n,
         setBit(n, pos));

  // [3] clear bit at a specified position
  /*
    Eg : 45 --- 101101
      clearBit(45,3) should return 45-8=37 as 3rd LSB (0 index counting)
      is gets reset to 0 => 110101
  */

  // clear bit handler
  n = 45;
  pos = 3;
  printf("After resetting No. %d bit of %d we get %d\n", pos, n,
         clearBit(n, pos));

  // [4] update bit to x at a specified position in the number
  /*
    Eg : 45 --- 101101
      updateBit(45,2,0) should return 41 as 2nd LSB (0 index counting)
      is gets changed from 1 to 0 => 110001
  */

  // update bit handler
  n = 45;
  pos = 2;
  int bit = 0;
  printf("On update No. %d bit of %d to %d we get %d\n", pos, n, bit,
         updateBit(n, pos, bit));

  return 0;
}