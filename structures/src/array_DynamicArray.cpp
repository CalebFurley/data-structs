#include <iostream>
using namespace std;

#include "../lib/array_DynamicArray.h"

/**
 * This script is for testing the DynamicArray class.
 */

int main () {
  DynamicArray<int>* array = new DynamicArray<int>();
  cout << array->size() << endl;
  cout << array->capacity() << endl;
  cout << *array << endl;
  return 0;
}