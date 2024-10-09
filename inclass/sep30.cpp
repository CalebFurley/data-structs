#include <iostream>
using std::cout;
using std::endl;

//fix this
//returns index of searched key
int binarySearch(int* arr, int low, int high, int key) {
  if (low > high) return -1;
  int mid = (low + high) / 2;
  if (arr[mid] == key) return mid;
  else {
    if (arr[mid] < key)
      return binarySearch(arr, mid+1, high, key);
    else
      return binarySearch(arr, low, mid-1, key);
  }
}

int main (int argc, char** argv) {
  int array[10] = {9,4,2,6,5,3};
  cout << binarySearch(array, 0, 6, 4) << endl;
  return 0;
}

/*
  Para el exam, es importante practicar
  LinkedList.

  Practice the sortsearch.cpp file. 
  - Binary and Mergesort. ***
*/

/* Stacks and Queues  

  p + q / z <-- build that out.

  operand push 
  operator pop

  
  *Operations
    1. pop  (dring this -1 size)
    2. push (during this +1 size) *all O(C)
    3. peak
    4. size (! actually compute size on go for err check)

    Stack underflow exception: 
      try to pop stack and nothing there.
    Stack overflow exception:
      fill up stack allocated portion of memory.

    Stacks remember the recent past. can pop back to
    locations, then push, and sit somewhere in the mid-
    dle of the stack to run program.
*/

/*
  Maze problem DO THIS FOR FUN!

  if(top==1||left==1||right||.....)
    follow 0 path 
  another matrix, with T/F for postions been too.
  use stack implementation for forward progress and
  backtracking.
*/

