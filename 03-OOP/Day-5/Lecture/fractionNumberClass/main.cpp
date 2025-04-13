#include <iostream>

using namespace std;

class fractionNumber
{
    int Num ;
    int Den ;

public:

/////////////////////// Setters ////////////////////////
    void setNum(int _Num)
    {
        Num=_Num;
    }
    void setDen(int _Den)
    {
        Den=_Den;
    }
/////////////////////Getters//////////////////////////
    int getNum()
    {
        return Num;
    }
    int getDen()
    {
        return Den;
    }
//////////////////// Print ///////////////////////////
    void print()
    {
        simplify();
        if ( Den > 0 )cout << "Number = "<< Num << "/" << Den << endl ;
        else if (Den == 1) cout << Num << endl;
        else if (Den == 0) cout << "The number is divided by zero"<< endl;
        else if (Den == Num) cout << "1" << endl ;
    }

//////////////////// Constructors ///////////////
    fractionNumber ()
    {
        Num = 0;
        Den = 1;
    }

    fractionNumber (int _Num)
    {
        Num = _Num;
        Den = 1;
    }

    fractionNumber (int _Num , int _Den)
    {
        Num = _Num;
        Den = _Den;
    }

//////////////////// Operator overload /////////////////////

    fractionNumber operator + (const fractionNumber & f) //f =  f1 + f2  (done)
    {
        fractionNumber res;
        res.Num = Num * f.Den + f.Num * Den ;
        res.Den = Den * f.Den;

        return res;
    }

    fractionNumber operator - (const fractionNumber & f) //f =  f1 - f2
    {
        fractionNumber res;
        res.Num = Num * f.Den - f.Num * Den ;
        res.Den = Den * f.Den;

        return res;
    }

    fractionNumber operator * (const fractionNumber & f) //f =  f1 * f2
    {
        fractionNumber res;
        res.Num = Num * f.Num ;
        res.Den = Den * f.Den ;

        return res;
    }

    fractionNumber operator / (const fractionNumber & f) //f =  f1 / f2
    {
        fractionNumber res;
        res.Num = Num * f.Den ;
        res.Den = Den * f.Num ;

        return res;
    }


    fractionNumber operator ++ () // ++ prefix
    {
        Num = Num + Den;
        return *this ;
    }

    fractionNumber operator ++ (int) // ++ postfix
    {
        fractionNumber temp = *this;
        Num = Num + Den;
        return temp;
    }

    fractionNumber operator -- () // -- prefix
    {
        Num = Num - Den;
        return *this ;
    }

    fractionNumber operator -- (int) // -- postfix
    {
        fractionNumber temp = *this;
        Num = Num - Den;
        return temp;
    }


    explicit operator float() // casting float = fractionNumber
    {
        return ((float)Num / Den) ;
    }

/////////////////////simplify the fraction /////////////////////////////////////////////
    void simplify()
    {
        int up = Num >= 0 ? Num : -Num; // Ensure the value of the Num is positive since we do not have ads fun
        int down = Den >= 0 ? Den : -Den; // Ensure the value of the den is +
        int divisor = 1;
        for(int i=1 ; i <= down && i <= up; ++i)
        {
            if(up%i==0 && down%i==0)
                 divisor = i ;
        }

        Num /= divisor;
        Den /= divisor;


        if (Den < 0) // ensure the den is + cuz
        {
            Num = -Num;
            Den = -Den;
        }

    }
};

void separateByLine();

int main()
{
    fractionNumber f1(5, 6); //= 5/6
    fractionNumber f2(3, 4); //= 3/4

    fractionNumber f3 = f1 + f2 ;
    f3.print();
    separateByLine();

    fractionNumber f4  = f1 - f2 ;
    f4.print();
    separateByLine();

    fractionNumber f5  = f1 * f2 ;
    f5.print();
    separateByLine();

    fractionNumber f6  = f1 / f2 ;
    f6.print();
    separateByLine();

    f1.print();
    fractionNumber f7  = f1++ ;
    f7.print();
    f1.print();
    separateByLine();

    f2.print();
    fractionNumber f8  = ++f2 ;
    f8.print();
    f2.print();
    separateByLine();

    f1.print();
    fractionNumber f9  = f1-- ;
    f9.print();
    f1.print();
    separateByLine();

    f2.print();
    fractionNumber f10  = --f2 ;
    f10.print();
    f2.print();
    separateByLine();

    fractionNumber f11(-11, -12) ;
    f11.print();
    separateByLine();

    fractionNumber f12(-11 ,13);
    f12.print();
    separateByLine();

    fractionNumber f13(11,-13);
    f13.print();
    separateByLine();

    float x ;
    f1.print();
    x = (float)f1 ;
    cout << x << endl;
    separateByLine();

    return 0;
}


void separateByLine()
{
    cout << "=========================================" << endl;
}


////////////////////////////////////////////////
/*
        while (down != 0) // euclidean method
        {
            int temp = down ; // to save the last den
            down = up % down ; // the reminder of dividing the Num / Den // as we do in real life
            up = temp ;
        }
*/
