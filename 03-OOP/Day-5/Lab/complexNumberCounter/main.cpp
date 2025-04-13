#include <iostream>

using namespace std;

class Complex
{
    int real ;
    int img ;
    static int counter;

public:
///////////////////////// Setters //////////////////////////////

    void setReal(int _real)
    {
        real = _real ;
    }

    void setImg(int _img)
    {
        img = _img ;
    }

///////////////////////// Getters //////////////////////////////

    int getReal()
    {
        return real;
    }

    int getImg()
    {
        return img;
    }

    static int getcounter()
    {
        return counter;
    }
/////////////////////////// Print ////////////////////////////////

    void print()
    {
        if (img > 0) cout << real << "+" << img << "j" << endl ;
        else if (img < 0) cout << real << img << "j" << endl;
        else cout << real << endl ;
    }

////////////////////////// Constructors ////////////////////////////

    Complex ()
    {
        real = img = 0 ;
        counter++ ;
    }

    Complex (int _real)
    {
        real = _real ;
        img = 0 ;
        counter++ ;
    }

    Complex (int _real , int _img)
    {
        real = _real;
        img = _img ;
        counter++ ;
    }

/////////////////////// Operator Overload /////////////////////

    // by reference will prevent calling the copy constructor which lead to better performance
    Complex operator+ (Complex& c)
    {
        Complex res( real+ c.real , img + c.img ); // minimize code
        //res.real = real+ c.real ;
        //res.img = real + c.img ;
        return res;
    }

    Complex operator + (int x)
    {
        Complex res;
        res.real = real + x ;
        res.img = img ;
        return res;
    }

    int operator == (Complex& c)
    {
        return real==c.real && img == c.img;
    }

    int operator != (Complex& c)
    {
        return !(*this == c); // Another way to implement the == since I have created it
    }

    Complex operator = (Complex c) // complex = complex
    {
        real = c.real ;
        img = c .img ;
        return *this ;
    }

    explicit operator int() // casting int = complex
    {
        return real ;
    }

    Complex operator ++ () // prefix
    {
        real = real+1;
        return *this ;
    }

    Complex operator ++ (int) // postfix
    {
        Complex temp = *this;
        real = real + 1;
        return temp;
    }

    friend Complex operator+(int x, const Complex& c);


/////////////////////// Copy Constructor ////////////////////////////

    Complex(Complex const &c)
    {
        real = c.real ;
        img = c.img ;
        counter++;
    }

/////////////////////// Destructor ////////////////////////////

    ~Complex ()
    {
        cout<<"object deleted\n";
        counter -- ;
    }

};

Complex operator+(int x, const Complex& c) {
    Complex res;
    res.real = x + c.real;
    res.img = c.img;
    return res;
}

int Complex::counter = 0 ;
void separateByLine();

int main()
{
    Complex c1(4,6) , c2(2,3 ) , c3(7,66) ;

    c3 = c1 + c2 ;
    c3.print();
    separateByLine();


    c3 = 3 + c2 ;
    c3.print();
    separateByLine();

    c3 = c1 + 3 ;
    c3.print();
    separateByLine();

    int x = (int)c1 ;
    cout <<x <<endl;
    separateByLine();

    c1 = c2 ;
    c1.print();
    separateByLine();

    c1++.print();
    separateByLine();

    ++c1;
    c1.print();
    separateByLine();

    cout << "The counter is " << Complex::getcounter() << endl;
    return 0;
}

void separateByLine()
{
    cout <<"=================================================\n";
}


