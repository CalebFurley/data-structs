#include <iostream>

template <class DT>
class Point
{
private:
//data members
  DT m_x;
  DT m_y;
public:
//constructors
  Point();
  Point(DT x, DT y);
  Point(const Point<DT>& other); //copy constructor
//destructor
  ~Point();
//overload operatrs =,-,+
  Point<DT>& operator=(const Point<DT>& other); //TODO
  Point<DT> operator-(const Point<DT>& other); //TODO
  Point<DT> operator+(const Point<DT>& other); //TODO
//getters and setters
  void setX(DT value);
  void setY(DT value);      
  DT getX() const;
  DT getY() const;
//friend functions
  template <class T>
  friend std::ostream& operator<<(std::ostream& os, const Point<T>& point); //TODO
  template <class T>
  friend std::istream& operator>>(std::istream& is, Point<T>& point); //TODO
};

//implementations
template <class DT>
Point<DT>::Point()
  : m_x(0), m_y(0)
{
}

template <class DT>
Point<DT>::Point(DT x, DT y)
  : m_x(x), m_y(y)
{ 
}

template <class DT>
Point<DT>::Point(const Point<DT>& other)
  : m_x(other.m_x), m_y(other.m_y)
{
}

template <class DT>
Point<DT>::~Point()
{
  std::cout << "Deleted Point = " << "(" << this->m_x << ", " << this->m_y << ")" << std::endl;
}

template<class DT>
DT Point<DT>::getX() const
{
  return this->m_x;
}

template <class DT>
DT Point<DT>::getY() const
{
  return this->m_y;
}

template <class DT>
void Point<DT>::setX(DT value)
{
  this->m_x = value;
}

template <class DT>
void Point<DT>::setY(DT value)
{
  this->m_y = value;
}

//overloaded operators here..
//overloaded stream operators here..
//friend std::ostream&


int main()
{
  Point<int> first_point;
  Point<float>* second_point;
  Point<float>* third_point;

  first_point.setX(1);
  first_point.setY(5);
  second_point = new Point<float>(2.5, 3.5);
  third_point = new Point<float>(*second_point);

  std::cout << "First Point = " << "(" << first_point.getX() << ", " << first_point.getY() << ")" << std::endl;
  std::cout << "Second Point = " << "(" << (*second_point).getX() << ", " << second_point->getY() << ")" << std::endl;
  std::cout << "Third Point = " << "(" << third_point->getX() << ", " << (*third_point).getY() << ")" << std::endl;

  delete second_point;
  second_point = nullptr;
  delete third_point;
  third_point = nullptr;

  return 0;
}