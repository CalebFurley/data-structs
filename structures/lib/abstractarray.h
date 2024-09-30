#ifndef ABSTRACTARRAY_H
#define ABSTRACTARRAY_H

#include "exceptions.h"

class ArrayException : public Exception {};
class ArrayMemoryException : public ArrayException {};
class ArrayBoundsException : public ArrayException {};

template <class DT>
class AbstractArrayClass {
public:
  virtual int size () const = 0;
  virtual DT& operator [] (int index) = 0;
};

#endif
