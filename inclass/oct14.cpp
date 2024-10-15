#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv) {
  cout << "Oct14!" << std;
  return 0;
}

/*
  InClass Notes:

  Traversales (check-this)
    pre-order = Root,Left,Right
    in-order = Left,Root,Right
    post-order = Left,Right,Root
  
  Store Binary Trees:
    Pointer Implem.
    Array Implem.
    Generalized List Implem. <- import check
    Parent Array Implem.

  Non-Recursive Traversal:
    Use the stack
    push right first so pop left

      Think about non-recursive in-order <------------ Actually do this.
    
    How to do this without a stack? :
      Double link, with loops somehow..
*/
