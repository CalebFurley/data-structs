#ifndef ABS_ARRAYCLASS_H
#define ABS_ARRAYCLASS_H

#include "Exception.h"

class ArrayException : public Exception {};
class ArrayMemoryException : public ArrayException {};
class ArrayBoundsException : public ArrayException {};

template <class DataType>
class AbstractArrayClass {
public:
  virtual int size () const = 0;
  virtual DataType& operator [] (int k) = 0;
};

#endif