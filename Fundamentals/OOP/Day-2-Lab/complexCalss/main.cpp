#include <iostream>

using namespace std;


class Complex
{
    int real ;
    int img ;

public:
    void setReal(int _real)
    {
        real=_real;
    }
    void setImg(int _img)
    {
        img=_img;
    }
    int getReal()
    {
        return real;
    }
    int getImg()
    {
        return img;
    }
    void print()
    {
        if (img > 0) cout << real << "+" << img << "j" << endl ;
        else if (img < 0) cout << real << img << "j" << endl;
        else cout << real << endl ;
    }

    Complex compAdd(Complex c1)
    {
        Complex result ;

        result.real = c1.real +real ;
        result.img = c1.img  +img ;

        return result;
    }

    Complex ()
    {
        real = 0;
        img = 0 ;
    }

    Complex (int _real , int _img)
    {
        real = _real;
        img = _img ;
    }

};

Complex add(Complex c1 , Complex c2);

int main()
{
    Complex comp1 , comp2(2,3 )  ;

    comp2.setReal(2);
    comp2.setImg(3);
    comp2.print();

    comp1.print();

    Complex c2(2,44) , c4(22,33);

    Complex c10 , c11;
    c11 = c4.compAdd(c2);

    c11.print();



    Complex comp3 = add(comp1,comp2);
    comp3.print();

    return 0;
}


Complex add(Complex c1 , Complex c2)
{
    Complex result ;
    result.setReal(c1.getReal()+c2.getReal());
    result.setImg(c1.getImg()+c2.getImg());
    return result;
}
