
#include <iostream>

using namespace std;

class Point{
    private:
        int x;
        int y;

    public:
        Point(){x=0; y=0;}
        Point(int x, int y): x(x), y(y){}
        Point operator+(const Point &);
        Point operator-(const Point &);
        Point operator+=(const Point &);
        Point operator-=(const Point &);
        friend ostream& operator <<(ostream &, const Point &);
        friend istream& operator >>(istream &,  Point &);
};

Point Point:: operator+(const Point &toAdd){
    Point thirdPoint(x + toAdd.x, y + toAdd.y);
    return thirdPoint;
}

Point Point::operator-(const Point &toSub){
     Point thirdPoint (x - toSub.x, y - toSub.y );
     return thirdPoint;
 }

 Point Point::operator+=(const Point &toAdd){
     x += toAdd.x;
     y += toAdd.y;
     return *this;
 }

  Point Point::operator-=(const Point &toSub){
     x -= toSub.x;
     y -= toSub.y;
     return *this;
 }

ostream& operator <<(ostream &out, const Point &point){
    out << "[" << point.x << ", " << point.y << "]" << endl;
    return out;
    }

    istream& operator >>(istream &in,  Point &point){
        cout << "Enter an x and y coord " << endl;
        in >> point.x >> point.y;
        return in;
    }