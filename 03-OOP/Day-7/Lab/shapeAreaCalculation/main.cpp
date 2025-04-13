#include <iostream>

using namespace std;

class Shape
{
protected:

    int dimension1 ;
    int dimension2 ;

public:
    Shape ( int _dimension1 = 0 , int _dimension2 = 0)
    {
        dimension1 = _dimension1;
        dimension2 = _dimension2;
    }
    //void setDimension1(int _dimension1) { dimension1 = _dimension1 ;}
    //void setDimension2(int _dimension2) { dimension2 = _dimension2 ;}

    virtual void set2Dimension(int _dimension1 = 0 , int _dimension2 = 0)
    {
        dimension1 = _dimension1 ;
        dimension2= _dimension2;
    }

    virtual void setDimension( int _dimension = 0) {dimension1 = dimension2 = _dimension ;}

    virtual double calcArea() = 0 ;// Pure virtual class

    // the addition is the ostream &out and the ostream
    friend ostream &operator<<(ostream &out, Shape &s)
    {
        out << "Dimension 1: " << s.dimension1 << ", Dimension 2: " << s.dimension2;
        out << ", Area: " << s.calcArea();
        return out;
    }

};

class Rectangle :public Shape
{
public:
    Rectangle (int dimension1 , int dimension2) : Shape(dimension1 , dimension2)
    {}

    double calcArea()
    {
        return dimension1 * dimension2 ;
    }

    void set2Dimension(int _dimension1 = 0 , int _dimension2 = 0)
    {
        dimension1 = _dimension1 ;
        dimension2= _dimension2;
    }

};

class Square : public Rectangle
{
public:
    Square(int side) : Rectangle(side, side) {}

    double calcArea()
    {
        return dimension1 * dimension1;  // or just Rectangle::calcArea() since both dimensions are equal
    }

    void setDimension( int _dimension = 0) {dimension1 = dimension2 = _dimension ;}

};

class Triangle :public Shape
{
public:
    Triangle (int dimension1 , int dimension2) : Shape(dimension1 , dimension2)
    {}

    double calcArea()
    {
        return 0.5 * dimension1 * dimension2 ;
    }
    void set2Dimension(int _dimension1 = 0 , int _dimension2 = 0)
    {
        dimension1 = _dimension1 ;
        dimension2= _dimension2;
    }


};

class Circle : public Shape
{
public:
    Circle(int r) : Shape(r, r) {}

    double calcArea()
    {
        return 3.14 * dimension1 * dimension1;  // or just Rectangle::calcArea() since both dimensions are equal
    }

    void setDimension( int _dimension = 0) {dimension1 = dimension2 = _dimension ;}

};

//general function to print the area of any shape sent to it
void myfun(Shape* e1) ;

//calculate the sum of multiple shapes
void sum(Shape *s[] , int _size);

int main()
{
    //Shape s; // abstract type so I can not add a object of it
    Rectangle r1(2 ,5);
    Square s1(5);
    Circle c1(7);
    Triangle t1(4 , 4);

    cout << r1.calcArea() << endl;
    cout << s1.calcArea() << endl;
    cout << c1.calcArea() << endl;
    cout << t1.calcArea() << endl;

    r1.set2Dimension(2 , 4);
    s1.setDimension(2);
    c1.setDimension(2);
    t1.set2Dimension(2,3);

    cout << r1.calcArea() << endl;
    cout << s1.calcArea() << endl;
    cout << c1.calcArea() << endl;
    cout << t1.calcArea() << endl;

    Shape *shapes[4] = {&r1 , &c1 ,&t1 ,&s1 };

    sum(shapes , 4);

    cout << "Shape details:" << endl;
    cout << "Rectangle: " << r1 << endl;
    cout << "Square: " << s1 << endl;
    cout << "Triangle: " << t1 << endl;

    return 0;
}

void myfun(Shape* e1)
{
    cout << e1->calcArea() << endl;

}

void sum(Shape *s[] , int _size)
{
    double sum = 0.0 ;
    for (int i = 0 ; i < _size ; i ++ )
    {
        sum += s[i]->calcArea();
    }
    cout << "the sum is " << sum << endl ;
}

/*
// overloaded << operator for objects
ostream &operator<<(ostream &out, const Shape &s)
{
    out << "Dimension 1: " << s.dimension1 << ", Dimension 2: " << s.dimension2;
    out << ", Area: " << s.calcArea();
    return out;
}
*/
