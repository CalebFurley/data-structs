#include <iostream>
using namespace std;

class Point
{
private:
  int _x;
  int _y;
public:
  Point();
  Point(int x, int y);
  Point(const Point& P);
  Point& operator=(const Point& P);
  friend ostream& operator<<(ostream& S, const Point& P);
};

Point::Point()
  : _x(0), _y(0)
{
}

Point::Point(int x, int y)
  : _x(x), _y(y)
{  
}

Point::Point(const Point& P)
  : _x(P._x), _y(P._y)
{
}

Point& Point::operator=(const Point& P)
{
  this->_x = P._x;
  this->_y = P._y; 
  return *this;
}

ostream& operator<<(ostream& S, const Point& P)
{
  S << "(" << P._x << ", " << P._y << ")" << endl;
  return S;
}

int main ()
{
  Point first(1,1);
  Point second(first);
  Point third(0,0);
  third = second;

  cout << first;
  cout << second;
  cout << third;

  return 0;
}