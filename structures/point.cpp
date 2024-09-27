#include <iostream>

/*LinkedLists
    1. Grow and shrink in size.
        -Grow and shrink by re-connecting pointers
        -Can only insert to beginning or end(on doubly-linked-lists)

        -Advatange is fast growth
        -DisAdvantage is slow lookup

    2. LinkedLists-Attributes
        -create
        -add, to the beginning
        -remove
        -etc..etc..
*/

/*Advice
    1. Make very general abstract version of all structures.
    2. Inherit rom that and build your custom structures.
*/

// !!! Finish the ArrayClass, can use in many other places for ease of printing and just everything bh.

template <class T>
class Point {
protected:
    size_t size;
    T* values;

public:
    //Constructors
    Point();
    template<typename... Args>
    Point(Args... args);
    ~Point() {delete[] T};

    //Overrides & Functionality
    void display() const;
    Point<T> operator + (const Point<T>& other);
    Point<T> operator - (const Point<T>& other);
    Point<T> operator * (const Point<T>& other);
    Point<T> operator / (const Point<T>& other);
    Point<T>& operator += (const Point<T>& other);
    Point<T>& operator -= (const Point<T>& other);
    Point<T>& operator *= (const Point<T>& other);
    Point<T>& operator /= (const Point<T>& other);

    template<typename U>
    friend std::ostream& operator << (std::ostream& stream, Point<U>& point);
};

template<typename T>
Point<T>::Point() : size(0) {
    values = new T[0];
}

template<typename T>
template <typename... Args>
Point<T>::Point(Args... args) 
    : size(sizeof...(args)) 
    {values = new T[size]{args...};}

template<typename T>
void Point<T>::display() const {
  std::cout << "(";
  for (T val : values) std::cout << val << ", ";
  std::cout << ")" << std::endl;
}

template<typename T>
Point<T> Point<T>::operator+(const Point<T>& other) {
    return Point(_x + other._x, _y + other._y);
}

template <typename T>
Point<T> Point<T>::operator-(const Point<T>& other) {
     return Point(_x - other._x, _y - other._y);
}

template <typename T>
Point<T> Point<T>::operator*(const Point<T> &other) {
    return Point(_x * other._x, _y * other._y);
}

template <typename T>
Point<T> Point<T>::operator/(const Point<T> &other) {
    return Point(_x / other._x, _y / other._y);
}
template <typename T>
Point<T>& Point<T>::operator+=(const Point<T> &other) {
    _x += other._x;
    _y *= other._y;
    return *this;
}

template <typename T>
Point<T> &Point<T>::operator-=(const Point<T> &other) {
    _x -= other._x;
    _y -= other._y;
    return *this;
}

template <typename T>
Point<T> &Point<T>::operator*=(const Point<T> &other) {
    _x *= other._x;
    _y *= other._y;
    return *this;
}

template <typename T>
Point<T> &Point<T>::operator/=(const Point<T> &other) {
    _x /= other._x;
    _y /= other._y;
    return *this;
}

template<typename T>
std::ostream& operator << (std::ostream& stream, Point<T>& point) {
  stream << "(";
  for (T val : values) stream << val << ", ";
  stream << ")" << std::endl;
}

int main(int argc, char** argv) {
  std::cout << "Hello World!" << std::endl;

  Point<double> first(1.2, 9.3);
  Point<double>* second = new Point<double>(8.8, 0.7);

  Point<int> third(1, 2);

  first = first + *second;
  std::cout << first;

  first *= third;
  std::cout << first;

  delete second;
  second = nullptr;

  return 0;
}