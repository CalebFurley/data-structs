#include <iostream>
using namespace std;

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