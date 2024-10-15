#ifndef POINT_H
#define POINT_H

#include "exception.h"
#include <iostream>
using std::ostream;

class PointException : public Exception {};

template <class DT>
class Point {
protected:
  DT _x;
  DT _y;
public:
  Point();
  Point(DT x, DT y);
  Point(const Point& other);
  ~Point();
  Point<DT>& operator + (const Point<DT>& other);
  Point<DT>& operator - (const Point<DT>& other);
  Point<DT>& operator * (const Point<DT>& other);
  Point<DT>& operator / (const Point<DT>& other);
  Point<DT>& operator = (const Point<DT>& other);
  template <class U>
  friend ostream& operator << (ostream& s, const Point<U>& p);
};

template <class DT>
Point<DT>::Point() {}

template <class DT>
Point<DT>::Point(DT x, DT y)
  :_x(x), _y(y) {}

template <class DT>
Point<DT>::Point(const Point& other) {
  this->_x = other._x;
  this->_y = other._y;
}

template <class DT>
Point<DT>::~Point() {}

template <class DT>
Point<DT>& Point<DT>::operator + (const Point<DT>& other) {
  Point<DT>* newPoint = new Point<DT>();
  newPoint->_x = (this->_x + other._x);
  newPoint->_y = (this->_y + other._y);
  return *newPoint;
}

template <class DT>
Point<DT>& Point<DT>::operator - (const Point<DT>& other) {
  Point<DT>* newPoint = new Point<DT>();
  newPoint->_x = (this->_x - other._x);
  newPoint->_y = (this->_y - other._y);
  return *newPoint;
}

template <class DT>
Point<DT>& Point<DT>::operator * (const Point<DT>& other) {
  Point<DT>* newPoint = new Point<DT>();
  newPoint->_x = (this->_x * other._x);
  newPoint->_y = (this->_y * other._y);
  return *newPoint;
}

template <class DT>
Point<DT>& Point<DT>::operator / (const Point<DT>& other) {
  Point<DT>* newPoint = new Point<DT>();
  newPoint->_x = (this->_x / other._x);
  newPoint->_y = (this->_y / other._y);
  return *newPoint;
}

template <class DT>
Point<DT>& Point<DT>::operator = (const Point<DT>& other) {  
  this->_x = other._x;
  this->_y = other._y;
  return *this;
}

template <class U>
ostream& operator << (ostream& s, const Point<U>& p) {
  s << "(" << p._x << "," << p._y << ")";
  return s;
}

#endif
