#ifndef ABS_ENUMERATION_H
#define ABS_ENUMERATION_H

#include "exception.h"

class EnumerationException : public Exception {};

template <class DataType>
class Enumeration {
public:
  //boolean method which determines whether there are any
  //more elements in the data structure being enumerated.
    virtual bool hasMoreElements() = 0;
    virtual DataType& nextElement() = 0;
  //returns the boject which is the next element
};

#endif