#include <iostream>

using namespace std;

class Point
{
    int x ;
    int y ;

public:
////////////////////Constructors////////////////////////
    Point()
    {
        x = y = 0;
        cout <<"Point CTOR\n";
    }

    Point(int _x)
    {
        x = _x ;
        y = 0 ;
        cout <<"Point CTOR\n";

    }

    Point(int _x , int _y)
    {
        x = _x ;
        y = _y ;
        cout <<"Point CTOR\n";
    }

///////////////////////// Setters /////////////////////////

    void setX(int _x)
    {
        x = _x ;
    }

    void setY(int _y)
    {
        y = _y ;
    }
///////////////////////// Getters /////////////////////////

    int getX()
    {
        return x ;
    }

    int getY()
    {
        return y;
    }

///////////////////////// Print /////////////////////////

    void print()
    {
        cout << "(" << x << "," << y << ")" <<endl;
    }

/////////////////////////Destructor /////////////////////////

    ~Point()
    {
        cout << "Point destructor\n";
    }

};

class Circle
{
    Point center;
    int r;

public:

    Circle()
    {
        cout <<"Circle CTOR\n";
    }

    //this called chaining which call the constructor of the point to initialize it
    Circle(int x1 , int y1 , int x ) : center(x1 , y1) , r(x)
    {
        /*
        ul.setX(x1);
        ul.setY(y1);
        lr.setX(x2);
        lr.setY(y2);
        */
    }
    Point getRadius()
    {
        return r;
    }

    Point getCenter()
    {
        return center;
    }

    void setRadius(int x)
    {
        r=x;
    }

    void setCenter(int x , int y)
    {
        center.setX(x);
        center.setY(y);
    }


    void print()
    {
        cout << "The center is : " ;
        center.print() ;
        cout << " radius is : " << r << endl ;
    }
    ~Circle()
    {
        cout << "Circle destructor\n";
    }
};


int main()
{

    Point P1(2,3);
    P1.print();

    Circle r1;
    r1.setCenter(2,3);
    r1.setRadius(4);
    r1.print();

    Circle r2(10 , 20 , 30);
    r2.print();

    return 0;
}
