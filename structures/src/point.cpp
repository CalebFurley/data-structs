#include <iostream>
#include "../lib/point.h"
using std::cout;
using std::endl;

/*
  1. Write proper testing for Point Class.
  2. Go back and write exceptions, then test again.
  3. Maybe even write some unit tests? against file?
*/
int main(int argc, char** argv) {
  Point<int>* point = new Point<int>();
  delete point;
  return 0;
}