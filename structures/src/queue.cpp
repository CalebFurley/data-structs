#include <iostream>
#include "../lib/concretes/queue.h"
using std::cout;
using std::endl;

/*
  1. Write proper testing for Queue Class.
  2. Go back and write exceptions, then test again.
  3. Maybe even write some unit tests? against file?
*/
int main(int argc, char** argv) {
  Queue<int>* queue = new Queue<int>(7);
  delete queue;
  return 0;
}