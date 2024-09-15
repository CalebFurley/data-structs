#include <iostream>
using namespace std;

/**
 * Finish the implementatoin of this class.
 * 
 * This is an important class to build out and get used
 * to building a custom data structure inside the c++
 * language. And overall just the designing of what goes
 * into building a data structure that is flexible and robust.
 */

class Exception {

};

class DivideByZeroException : public Exception {

};

class ArrayOutOfBoundsException : public Exception {

};

class NegativeIndexException : public Exception {

};

template<class T>
class ArrayClass {
protected:
  T* _data;
  size_t _size;
public:
  ArrayClass ();
  ArrayClass (int size);
  ArrayClass (const ArrayClass& other);
  ArrayClass& operator = (const ArrayClass& other);
  T& operator [] (int index);
  const T& operator [] (int index) const;
  friend ostream& operator << (ostream& stream, const ArrayClass& object);
};
//finish definitions..

//implement class here..


int main()
{

  int** array = new int*[3];

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      array[i][j] = 1;
    }
  }

  for (int i=0; i < 3; ++i) delete[] array[i];
  delete[] array;
  array = nullptr;

  return 0;
}