
#include <iostream>

using namespace std;
template <class Type>
class Point;

template <class Type>
ostream& operator <<(ostream &, const Point<Type> &);

template <class Type>
istream& operator >>(istream &,  Point<Type> &);

template <class Type>
class Point{
    private:
        Type x;
        Type y;

    public:
        Point(){x=0; y=0;}
        Point(Type x, Type y): x(x), y(y){}
        Point operator+(const Point<Type> &);
        Point operator-(const Point<Type> &);
        Point operator+=(const Point<Type> &);
        Point operator-=(const Point<Type> &);
        friend ostream& operator << <>(ostream &, const Point<Type> &);
        friend istream& operator >> <>(istream &,  Point<Type> &);
};

template <class Type>
Point<Type> Point<Type>:: operator+(const Point<Type> &toAdd){
    Point thirdPoint(x + toAdd.x, y + toAdd.y);
    return thirdPoint;
}

template <class Type>
Point<Type> Point<Type>::operator-(const Point<Type> &toSub){
     Point thirdPoint (x - toSub.x, y - toSub.y );
     return thirdPoint;
 }

template <class Type>
Point<Type> Point<Type>::operator+=(const Point<Type> &toAdd){
     x += toAdd.x;
     y += toAdd.y;
     return *this;
 }

template <class Type>
Point<Type> Point<Type>::operator-=(const Point<Type> &toSub){
     x -= toSub.x;
     y -= toSub.y;
     return *this;
 }

template <class Type>
ostream& operator <<(ostream &out, const Point<Type> &point){
    out << "[" << point.x << ", " << point.y << "]" << endl;
    return out;
    }

template <class Type>
istream& operator >>(istream &in,  Point<Type> &point){
        cout << "Enter an x and y coord " << endl;
        in >> point.x >> point.y;
        return in;
    }