#include <iostream>
using namespace std;

class Point {
    public:
        int x;
        int y;
    // constructors
    Point ();
    Point (int s, int t);
    Point (const Point& P); //copy constructor
    Point& operator= (const Point& P); //overloaded assignment operator
    //display
    void display();
    //overloaded operators
    Point operator+ (const Point& P) ;
    //destructor
    ~Point();
};

Point& Point::operator=(const Point& P) {
    x = P.x;
    y = P.y;
    return *this; //this is a pointer to this object and
}

Point Point::operator+ (const Point& P)  {
    return Point(x+P.x, y+P.y);
}

Point::Point (const Point& P) {
    x = P.x;
    y = P.y;
}

Point::~Point() {
    cout << "The point is (" << x << ", " << y << ") was killed" << endl;
}

Point::Point() {
    x = 0;
    y = 0;
}
Point::Point (int s, int t) {
    x = s;
    y = t;
}

void Point::display () {
    cout << "The point is (" << x << ", " << y << ")" << endl;
}

int main () {

    Point aPoint(10, 20); //statically defined
    Point bPoint; //statically defined
    Point dPoint;
    Point* pointPtr;
    Point* cPoint;

    aPoint.display();
    bPoint.display();

    pointPtr = new Point (100, 200); //dynamically deleted

    cPoint = new Point (aPoint);

    delete pointPtr;
    delete cPoint; //the box cPoint is not delete; what is deleted is the object cPoint is pointing to

    cPoint = new Point (10, 33);

    //aPoint = bPoint = *cPoint;

    dPoint = aPoint + bPoint;
   
    return 0;
}

