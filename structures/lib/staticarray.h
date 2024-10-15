#ifndef StaticArray_H
#define StaticArray_H

#include <iostream>
#include "../abstracts/abs_arrayclass.h"

template <class DT>
class StaticArray : virtual public AbstractArrayClass<DT> {
protected:
  int _size;
  DT* _data;

public:
  //Constructors
  StaticArray();
  StaticArray(int size);
  StaticArray(const StaticArray& other);
  ~StaticArray();

  //Accessors
  int size () const;

  //Operators
  DT& operator [] (int index);
  DT& operator [] (int index) const;
  StaticArray<DT>& operator = (const StaticArray& other);
  template<class U>
  friend std::ostream& operator << (std::ostream& s, const StaticArray<DT>& ac);
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
std::ostream& operator << (std::ostream& s, const StaticArray<U>& ac) {
  s << "[";
  for (int i=0; i<ac.size()-2; ++i)
    s << ac[i] << ", ";
  s << ac[ac.size()-1] << "]";
  return s;
}

#endif
