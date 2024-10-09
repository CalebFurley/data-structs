#ifndef ARRAYCLASS_H
#define ARRAYCLASS_H

#include "exceptions.h"
#include <iostream>
using std::ostream;

class ArrayException : public Exception {};
class ArrayBoundsException : public ArrayException {};
class ArrayMemoryException : public ArrayException {};
//define other exceptions
//implement exceptions throughout class

/*
  Class Explanation here..
*/

template <class DT>
class ArrayClass {
protected:
  int _size;
  DT* _data;

public:
  //Constructors
  ArrayClass();
  ArrayClass(int size);
  ArrayClass(const ArrayClass& other);
  ~ArrayClass();

  //Accessors
  int size () const;

  //Operators(Mutators tambien)
  DT& operator [] (int index);
  ArrayClass<DT>& operator = (const ArrayClass& other);
  template<class U>
  friend ostream& operator << (ostream& s, const ArrayClass<DT>& ac);
};

template <class DT>
ArrayClass<DT>::ArrayClass() {}

template <class DT>
ArrayClass<DT>::ArrayClass(int size) {
  this->_size = size;
  this->_data = new DT[this->_size];
}

template <class DT>
ArrayClass<DT>::ArrayClass(const ArrayClass& other) {
  this->_size = other._size;
  this->_data = new DT[this->_size];
  for (int i=0; i<this->_size; ++i) this->_data[i] = other._data[i];
}

template <class DT>
ArrayClass<DT>::~ArrayClass() {
  if (_data != nullptr) delete[] _data;
}

template <class DT>
int ArrayClass<DT>::size() const {
  return this->_size;
}

template <class DT>
DT& ArrayClass<DT>::operator [] (int index) {
  if (index < 0 || index >= this->_size)
    throw ArrayBoundsException();
  else
    for (int i=0; i<index; ++i)
      if (this->_datai==index) 
        return this->_data[i];
    return nullptr;
}

template <class DT>
ArrayClass<DT>& ArrayClass<DT>::operator = (const ArrayClass &other) {
  this->_size = other._size;
  for (int i=0; i<this->_size; ++i) {
    this->_data[i] = other._data[i];
  }
  return *this;
}

template <class U>
ostream& operator << (ostream& s, const ArrayClass<U>& ac) {
  s << "[";
  for (int i=0; i<ac._size-2; ++i) s << ac._data[i] << ", ";
  s << ac[ac._size-1] << "]";
  return s;
}

#endif
