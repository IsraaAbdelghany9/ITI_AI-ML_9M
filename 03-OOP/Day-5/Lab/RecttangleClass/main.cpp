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

class Rect
{
    Point ul; //if *ul it will not go to constructor and destructor
    Point lr;

public:

    Rect()
    {
        cout <<"Rect CTOR\n";
    }

    //this called chaining which call the constructor of the point to initialize it
    Rect(int x1 , int y1 , int x2 , int y2) : ul(x1 , y1) , lr (x2 , y2)
    {
        /*
        ul.setX(x1);
        ul.setY(y1);
        lr.setX(x2);
        lr.setY(y2);
        */
    }
    Point getUL()
    {
        return ul;
    }

    Point getLR()
    {
        return lr;
    }

    void setUL(Point _ul)
    {
        ul=_ul;
    }

    void setUL(int _x , int _y)
    {
        ul.setX(_x);
        ul.setY(_y);
    }

    void setLR(Point _lr)
    {
        lr=_lr;
    }

    void setLR(int _x , int _y)
    {
        lr.setX(_x);
        lr.setY(_y);
    }

    void print()
    {
        ul.print();
        lr.print();
    }
    ~Rect()
    {
        cout << "Rect destructor\n";
    }
};


int main()
{

    Point P1(2,3);
    P1.print();

    Rect r1;
    r1.setLR(2,3);
    r1.setUL(4,6);
    r1.print();

    Rect r2(10 , 20 , 30 , 40);
    r2.print();

    return 0;
}
