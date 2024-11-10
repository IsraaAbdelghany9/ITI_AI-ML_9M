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

};

void printComplex(Complex comp1);

int main()
{
    Complex comp1;
    comp1.setImg(3);
    comp1.setReal(3);
    printComplex(comp1);
    return 0;
}

void printComplex(Complex comp1)
    {
        if (comp1.getImg() > 0) cout << comp1.getReal() << "+" << comp1.getImg() << "j" << endl ;
        else if (comp1.getImg() < 0) cout << comp1.getReal() << comp1.getImg() << "j" << endl;
        else cout << comp1.getReal() << endl ;
    }
