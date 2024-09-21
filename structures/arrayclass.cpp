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

  void insertAt();
  void removeAt();
  void pushBack();
  void getSize();

  ArrayClass& operator = (const ArrayClass& other);
  friend ostream& operator << (ostream& stream, const ArrayClass& object);
};

template <class T>
ArrayClass<T>::ArrayClass()
{
}

template <class T>
ArrayClass<T>::ArrayClass(size_t size)
{
}

template <class T>
ArrayClass<T>::ArrayClass(const ArrayClass &other)
{
}

template <class T>
ArrayClass<T>::~ArrayClass()
{
}

template <class T>
void ArrayClass<T>::insertAt()
{
}

template <class T>
void ArrayClass<T>::removeAt()
{
}

template <class T>
void ArrayClass<T>::pushBack()
{
}

template <class T>
void ArrayClass<T>::getSize()
{
}

template <class T>
ArrayClass<T> &ArrayClass<T>::operator=(const ArrayClass<T> &other)
{
    // TODO: insert return statement here
}
template <class U>
std::ostream &operator<<(std::ostream &stream, const ArrayClass<U> &object)
{
    // TODO: insert return statement here
}

int main(int argc, char** argv) {
  return 0;
}
