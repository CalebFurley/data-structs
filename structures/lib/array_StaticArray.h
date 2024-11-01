#ifndef ARRAY_STATICARRAY_H
#define ARRAY_STATICARRAY_H

/** TODO For this class
 * test the class and implement exceptions
 * where necessary.
 */

#include <iostream>
#include "abs_ArrayClass.h"

template <class DT>
class StaticArray : virtual public AbstractArrayClass<DT> {
protected:
  int _size;
  DT* _data;
public:
  StaticArray();
  StaticArray(int size);
  StaticArray(const StaticArray& other);
  ~StaticArray();
  int size () const;
  DT& operator [] (int index);
  DT& operator [] (int index) const;
  StaticArray<DT>& operator = (const StaticArray& other);
  template<class U>
  friend std::ostream& operator << (std::ostream& os, const StaticArray<DT>& object);
};

template <class DT>
StaticArray<DT>::StaticArray() 
  : _size(0) , _data(nullptr) {}

template <class DT>
StaticArray<DT>::StaticArray(int size) {
  this->_size = size;
  this->_data = new DT[this->_size];
}

template <class DT>
StaticArray<DT>::StaticArray(const StaticArray& other) {
  this->_size = other._size;
  this->_data = new DT[this->_size];
  for (int i=0; i<this->_size; ++i) 
    this->_data[i] = other._data[i];
}

template <class DT>
StaticArray<DT>::~StaticArray() {
  if (_data != nullptr) delete[] _data;
}

template <class DT>
int StaticArray<DT>::size() const {
  return this->_size;
}

template <class DT>
DT& StaticArray<DT>::operator [] (int index) {
  if (index<0 || index>=size()) throw ArrayBoundsException();
  else return _data[index];    
}

template <class DT>
DT& StaticArray<DT>::operator [] (int index) const {
  if (index<0 || index>=size()) throw ArrayBoundsException();
  else return _data[index];
}

template <class DT>
StaticArray<DT>& StaticArray<DT>::operator = (const StaticArray &other) {
  this->_size = other._size;
  for (int i=0; i<this->_size; ++i) {
    this->_data[i] = other._data[i];
  }
  return *this;
}

template <class U>
std::ostream& operator << (std::ostream& os, const StaticArray<U>& object) {
  s << "[";
  for (int i=0; i<ac.size()-2; ++i)
    s << ac[i] << ", ";
  s << ac[ac.size()-1] << "]";
  return s;
}

#endif
