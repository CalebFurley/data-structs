#ifndef ABS_ENUMERATION_H
#define ABS_ENUMERATION_H

#include "abs_Exception.h"

class EnumerationException : public Exception {};

template <class DataType>
class Enumeration {
public:
//boolean if there are more elements to enumerate.
  virtual bool hasMoreElements() = 0;
//returns next element in enumeration.
  virtual DataType& nextElement() = 0;
};

#endif