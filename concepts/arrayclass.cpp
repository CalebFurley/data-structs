#include <iostream>

/**
 * Finish the implementatoin of this class.
 * 
 * This is an important class to build out and get used
 * to building a custom data structure inside the c++
 * language. And overall just the designing of what goes
 * into building a data structure that is flexible and robust.
 */


// When building a vector, make sure to leave extra space 
//      (remember java does 1.5x real size of array until need to grow.)
//insertAt()
//removeAt()
//getSize()
//



class Exception {
  virtual std::string getMessage() const = 0;
};

class DivideByZeroException : public Exception {
public:
  std::string getMessage() const override {
    return "Divide by zero exception.";
  }
};

class ArrayOutOfBoundsException : public Exception {
  std::string getMessage() const override {
    return "Array out of bounds exception.";
  }
};

class NegativeIndexException : public Exception {
  std::string getMessage() const override {
    return "Negative array index exception.";
  }
};

template<class T>
class ArrayClass {
protected:
  T* _data;
  size_t _size;
public:
  ArrayClass ();
  ArrayClass (size_t size);
  ArrayClass (const ArrayClass& other); // deep copy constructor
  ArrayClass& operator = (const ArrayClass& other); // deep copy
  ~ArrayClass(); // destructor, delete[] _data;
  bool operator == (const ArrayClass& other); // deep compare
  T& operator [] (int index); // [] mutator
  const T& operator [] (int index) const; // [] compare
  friend ostream& operator << (ostream& stream, const ArrayClass& object);
  //finish definitions..
};

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