#ifndef MATH_POINT_H
#define MATH_POINT_H

/** TODO For this class
 * implement constructor that accepts unlimited arguments
 * then make a vector to hold the deminsions of the point.
 * 
 * also check for and implement error checking.
 */

#include "abs_Exception.h"
#include <iostream>

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
  friend std::ostream& operator << (std::ostream& s, const Point<U>& p);
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
std::ostream& operator << (std::ostream& s, const Point<U>& p) {
  s << "(" << p._x << "," << p._y << ")";
  return s;
}

#endif
