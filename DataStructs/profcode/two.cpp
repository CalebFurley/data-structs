#include <iostream>
using namespace std;

template <class DT>
class Point {
    public:
        DT x;
        DT y;
    // constructors
    Point ();
    Point (DT s, DT t);
    Point (const Point<DT>& P); //copy constructor
    Point<DT> operator= (const Point<DT>& P); //overloaded assignment operator
    //display
    void display();
    //overloaded operators
    Point<DT> operator+ (const Point<DT>& P);
    //destructor
    ~Point();

};

template <class DT>
Point<DT> Point<DT>::operator= (const Point<DT>& P) {
    x = P.x;
    y = P.y;
    return *this; //this is a pointer to this object and
}

template <class DT>
Point<DT> Point<DT>::operator+ (const Point<DT>& P)  {
    return Point<DT>(x+P.x, y+P.y);
}
template <class DT>
Point<DT>::Point (const Point<DT>& P) {
    x = P.x;
    y = P.y;
}

template <class DT>
Point<DT>::~Point() {
    cout << "The point is (" << x << ", " << y << ") was killed" << endl;
}
template <class DT>
Point<DT>::Point() {
    x = 0;
    y = 0;
}
template <class DT>
Point<DT>::Point (DT s, DT t) {
    x = s;
    y = t;
}

template <class DT>
void Point<DT>::display () {
    cout << "The point is (" << x << ", " << y << ")" << endl;
}

int main () {

    Point<int> aPoint(10, 20); //statically defined
    Point<int> bPoint; //statically defined
    Point<int> dPoint;
    Point<int>* pointPtr;
    Point<int>* cPoint;

    aPoint.display();
    bPoint.display();

    pointPtr = new Point<int> (100, 200); //dynamically deleted

    cPoint = new Point<int> (aPoint);

    delete pointPtr;
    delete cPoint; //the box cPoint is not delete; what is deleted is the object cPoint is pointing to

    cPoint = new Point<int> (10, 33);

    aPoint = bPoint = *cPoint;

    dPoint = aPoint + bPoint;

    
   
    return 0;
}

