#ifndef ABS_ARRAYCLASS_H
#define ABS_ARRAYCLASS_H

#include "abs_Exception.h"

class ArrayException : public Exception {};
class ArrayMemoryException : public ArrayException {};
class ArrayBoundsException : public ArrayException {};

template <class DataType>
class AbstractArrayClass {
public:
//returns the size of the array.
  virtual int size () const = 0;
//overloads [] operator for asignment.
  virtual DataType& operator [] (int index) = 0;
//overloads [] operator for access.
  virtual DataType& operator [] (int index) const = 0;
};

#endif