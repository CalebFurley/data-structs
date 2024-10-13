#include <iostream>
#include "../lib/concretes/linkedlist.h"
using std::cout;
using std::endl;

/*
  1. Write proper testing for linkedlist.
  2. Go back and write exceptions, then test again.
  3. Maybe even write some unit tests? against file?
*/
int main(int argc, char** argv) {
  LinkedList<int>* list = new LinkedList<int>();
  delete list;
  return 0;
}
