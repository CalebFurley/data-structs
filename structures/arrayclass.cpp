#include <iostream>
#include "exceptions.h"

/**
 * Finish the implementatoin of this class.
 * 
 * This is an important class to build out and get used
 * to building a custom data structure inside the c++
 * language. And overall just the designing of what goes
 * into building a data structure that is flexible and robust.
 */

/*  When building a vector, make sure to leave extra space 
      (remember java does 1.5x real size of array until need to grow.)
    insertAt()
    removeAt()
    getSize()
*/

template<class T>
class ArrayClass {
protected:
    T* _data;
    size_t _size;

public:
    ArrayClass();
    ArrayClass(size_t size);
    ArrayClass(const ArrayClass& other);
    ~ArrayClass();

    void insertAt(size_t index);
    void removeAt(size_t index);
    void pushBack();
    size_t getSize();

    T& operator [] (size_t index);
    ArrayClass& operator = (const ArrayClass& other);
    friend ostream& operator << (ostream& stream, const ArrayClass& object);
};

template <class T>
ArrayClass<T>::ArrayClass() {}

template <class T>
ArrayClass<T>::ArrayClass(size_t size) 
  : _size(size) {}

template <class T>
ArrayClass<T>::ArrayClass(const ArrayClass &other) {
    //perform deep copy here..
}

template <class T>
ArrayClass<T>::~ArrayClass() {
    if (_data != nullptr) delete[] _data;
}

template <class T>
void ArrayClass<T>::insertAt(size_t index) {
  //inserts element at passed index
}

template <class T>
void ArrayClass<T>::removeAt(size_t index) {
  //removes elements at passed index.
}

template <class T>
void ArrayClass<T>::pushBack() {
  //adds to the back of the array
}

template <class T>
size_t ArrayClass<T>::getSize() {
  return this->_size;
}

template <class T>
T& ArrayClass<T>::operator[](size_t index) {
  // TODO: insert return statement here
}

template <class T>
ArrayClass<T>& ArrayClass<T>::operator=(const ArrayClass<T> &other) {
  // TODO: insert return statement here
}
template <class U>
std::ostream &operator<<(std::ostream &stream, const ArrayClass<U> &object) {
  // TODO: insert return statement here
}

int main(int argc, char** argv) {
  return 0;
}
