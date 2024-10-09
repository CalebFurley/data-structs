#include <iostream>
#include "../lib/arrayclass.h"
using std::cout;
using std::endl;

/*
  1. Write proper testing for Array Class.
  2. Go back and write exceptions, then test again.
  3. Maybe even write some unit tests? against file?
*/
int main(int argc, char** argv) {
  ArrayClass<int>* array = new ArrayClass<int>();
  delete array;
  return 0;
}