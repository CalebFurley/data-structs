#ifndef ARRAY_DYNAMICARRAY_H
#define ARRAY_DYNAMICARRAY_H

#include <iostream>
#include "abs_ArrayClass.h"

template <class DT>
class DynamicArray : virtual public AbstractArrayClass<DT> {
protected:
  DT* _data; // array data
  int _size; //size of elements in array
  int _capacity; //total size of array
  void grow(); //grow _capacity by 2x     <-- still need to implement when correctly needed for growth.
public:
  DynamicArray();
  DynamicArray(int size);
  DynamicArray(const DynamicArray& other);
  ~DynamicArray();
  int size() const;
  int capacity() const;
  DT& operator[] (int index);
  DT& operator[] (int index) const;
  DynamicArray<DT>& operator = (const DynamicArray<DT>& other);
  template<class U>
  friend std::ostream& operator << (std::ostream& os, const DynamicArray<DT>& object);
};

template <class DT>
void DynamicArray<DT>::grow() { 
    _capacity = _size * 2;
}

template <class DT>
DynamicArray<DT>::DynamicArray() 
  : _data(nullptr), _size(0), _capacity(0) {}

template <class DT>
DynamicArray<DT>::DynamicArray(int size) {
  _size = size;
  _capacity = _size * 2;
}

template <class DT>
DynamicArray<DT>::DynamicArray(const DynamicArray &other) {
  //implement the copy constructor.
}

template <class DT>
DynamicArray<DT>::~DynamicArray() {
  //implement the destructor.
}

template <class DT>
int DynamicArray<DT>::size() const {
  return _size;
}

template <class DT>
int DynamicArray<DT>::capacity() const {
  return _capacity;
}

template <class DT>
DT& DynamicArray<DT>::operator[](int index) {
  if (index < 0 || index >= _size) throw ArrayBoundsException();
  return _data[index];
}

template <class DT>
DT& DynamicArray<DT>::operator[](int index) const {
  if (index < 0 || index >= _size) throw ArrayBoundsException();
  return _data[index];
}

template <class DT>
DynamicArray<DT>& DynamicArray<DT>::operator = (const DynamicArray<DT>& other) {
  this->_size = other._size;
  this->_capacity = other._capacity;
  for (int i=0; i<this->_size; ++i) {
    this->_data[i] = other._data[i];
  }
  return *this;
}

template <class U>
std::ostream& operator << (std::ostream& os, const DynamicArray<U>& object) {
  if (object.size() <= 0) throw ArrayMemoryException();
  os << "[";
  for (int i=0; i<object.size()-2; ++i) 
    os << object[i] << ", ";
  os << object[object.size()-1] << "]";
  return os;
}
#endif