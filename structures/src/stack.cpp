#include <iostream>
#include "../lib/stack.h"
using std::cout;
using std::endl;

/*
  1. Write proper testing for Stack Class.
  2. Go back and write exceptions, then test again.
  3. Maybe even write some unit tests? against file?
*/
int main(int argc, char** argv) {
  Stack<int>* stack = new Stack<int>();
  delete stack;
  return 0;
}