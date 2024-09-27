#include <iostream>
#include "exceptions.h"
using namespace std;

/************************** PROTOTYPE ****************************/
template <class DT>
class Point {
  DT _x;
  DT _y;
public:
  Point();
  Point(DT x, DT y);
  Point(const Point& other);
  ~Point();

  Point<DT> operator + (const Point<DT>& other);
  Point<DT> operator - (const Point<DT>& other);
  Point<DT> operator * (const Point<DT>& other);
  Point<DT> operator / (const Point<DT>& other);
  Point<DT>& operator = (const Point<DT>& other);//deep-copy

  template<class U>
  friend ostream& operator << (ostream& stream, const Point<U>& self);
};

/************************ IMPLEMENTATION *************************/
template <class DT>
Point<DT>::Point() {}

template <class DT>
Point<DT>::Point(DT x, DT y)
  :_x(x), _y(y) {}

template <class DT>
Point<DT>::Point(const Point& other) {
  //TODO write this method..
}

template <class DT>
Point<DT>::~Point() {}

template <class DT>
Point<DT> Point<DT>::operator + (const Point<DT>& other) {
  //TODO write this method..
}

template <class DT>
Point<DT> Point<DT>::operator - (const Point<DT>& other) {
  //TODO write this method..
}

template <class DT>
Point<DT> Point<DT>::operator * (const Point<DT>& other) {
  //TODO write this method..
}

template <class DT>
Point<DT> Point<DT>::operator / (const Point<DT>& other) {
  //TODO write this method..
}

template <class DT>
Point<DT>& Point<DT>::operator = (const Point<DT>& other) {
  //TODO write this method..
}

template <class DT>
ostream& operator << (ostream& stream, const Point<DT>& self) {
  //TODO write this method..
  return stream;
}

/*************************** TESTING *****************************/
int main() {
  cout << "Hello World!" << endl;
  return 0;
}
