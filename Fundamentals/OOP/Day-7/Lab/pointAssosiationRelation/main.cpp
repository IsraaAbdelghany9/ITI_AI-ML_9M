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
    Point *ul; //if *ul it will not go to constructor and destructor
    Point *lr;

public:

    Rect()
    {
        cout <<"Rect CTOR\n";
        ul ;  // No dynamic allocation, just a null pointer
        lr ;  // No dynamic allocation, just a null pointer

    }


    // Constructor with initialization of Points using dynamic memory allocation
    Rect(int x1 = 0, int y1 = 0, int x2 = 0 , int y2 = 0 )
    {
        cout << "Rectangle CTOR\n";
        ul = new Point(x1, y1); // Dynamically allocate memory for ul and initialize it
        lr = new Point(x2, y2); // Dynamically allocate memory for lr and initialize it
    }

    Point getUL() { return *ul ; }

    Point getLR() { return *lr ; }

    void setUL(Point *_ul) { ul=_ul ; }

    void setUL(int _x , int _y)
    {
        ul->setX(_x);
        ul->setY(_y);
    }

    void setLR(Point *_lr) { lr=_lr ; }

    void setLR(int _x , int _y)
    {
        lr->setX(_x);
        lr->setY(_y);
    }

    void print()
    {
        ul->print();
        lr->print();
    }
    ~Rect()
    {
        cout << "Rect destructor\n";
        delete ul;
        delete lr;
    }
};


int main()
{
    Rect r2(10 , 20 , 30 , 40);
    r2.print();

    return 0;
}
