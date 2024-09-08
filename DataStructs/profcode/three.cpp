#include <iostream>
using namespace std;

template <class DT>
class Point {
    public:
        DT* x;
        DT* y;
    // constructors
    Point ();
    Point (DT s, DT t);
    Point (const Point<DT>& P); //copy constructor
    
    Point<DT>& operator= (const Point<DT>& P); //overloaded assignment operator
    //display
    void display();
    //overloaded operators
    Point<DT> operator+ (const Point<DT>& P);
    friend ostream& operator<<(ostream& s, const Point<DT>& P) {
        if (!(P.x == NULL) && !(P.y == NULL)) {
            s << "The point is (" << *(P.x) << ", " << *(P.y) << ")";
        }
        return s;
    }

    //destructor
    ~Point(); 

};
template <class DT>
Point<DT>::Point() {
    x = NULL;
    y = NULL;
}

template <class DT>
Point<DT>& Point<DT>::operator= (const Point<DT>& P) {
    if (!(x == NULL)) delete x;
    if (!(y == NULL)) delete y;
    x = new DT (*(P.x));
    y = new DT (*(P.y));
    return *this; //this is a pointer to this object and
}


template <class DT>
Point<DT> Point<DT>::operator+ (const Point<DT>& P)  {
    if (!(x == NULL) && !(y == NULL)) return Point<DT>(*x + *(P.x), *y + *(P.y));
    return Point<DT>(0 + *(P.x), 0 + *(P.y));
}

template <class DT>
Point<DT>::Point (const Point<DT>& P) {
    if (!(x == NULL)) delete x;
    if (!(y == NULL)) delete y;
    x = new DT (*(P.x));
    y = new DT (*(P.y));
}


template <class DT>
Point<DT>::~Point() {
    if (!(x == NULL) && !(y == NULL)) {
        cout << "The point is (" << *x << ", " << *y << ") was killed" << endl;
        delete x;
        delete y;
    }
}

template <class DT>
Point<DT>::Point (DT s, DT t) {
    x = new DT(s);
    y = new DT(t);
}

template <class DT>
void Point<DT>::display () {
    if (!(x == NULL) && !(y == NULL))
        cout << "The point is (" << *x << ", " << *y << ")" << endl;
}

int main () {

    Point<int> aPoint(10, 20); //statically defined
    Point<int> bPoint; //statically defined
    Point<int> dPoint;
    Point<int>* pointPtr;
    Point<int>* cPoint;

    aPoint.display();
    bPoint.display();

    cout << aPoint << endl;

    pointPtr = new Point<int> (100, 200); //dynamically deleted

    cPoint = new Point<int> (aPoint);

     delete pointPtr;
     delete cPoint; //the box cPoint is not delete; what is deleted is the object cPoint is pointing to

    cPoint = new Point<int> (10, 33);

    aPoint = bPoint = *cPoint;

    dPoint = aPoint + bPoint;

    return 0;
}