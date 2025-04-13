#include <iostream>

using namespace std;



class Duration_Time
{
    int seconds ;
    int minutes ;
    int hours ;

public:

/////////////////////// Setters ////////////////////////
    void setSecond(int _seconds)
    {
        if (_seconds < 60 )
            seconds=_seconds;

        else
        {
            minutes += (_seconds / 60);
            seconds = _seconds % 60;
            if (minutes >= 60)
            {
                int extraHours;
                extraHours = minutes / 60;
                minutes = minutes % 60 ;
                hours += extraHours;
            }
        }
    }

    void setMinutes(int _minutes)
    {
        if (_minutes >= 60)
            {
                int extraHours;
                extraHours = _minutes / 60;
                minutes = _minutes % 60 ;
                hours += extraHours;
            }

        else
            minutes = _minutes;
    }

    void setHours(int _hours)
    {
        hours = _hours;
    }

/////////////////////// Getters ////////////////////////

    int getSeconds()
    {
        return seconds;
    }

    int getMinutes()
    {
        return minutes;
    }

    int getHours()
    {
        return hours;
    }

//////////////////////// Print //////////////////////////////////////

    void print()
    {
        if (hours == 0 && minutes == 0 && seconds == 0)
            cout << "The Duration is set to 0" << endl;

        if (hours == 0 && minutes == 0)
            cout << "Seconds :" << seconds << endl;

        else if (hours == 0 )
            cout << "Minutes :" <<minutes << "," << " Seconds :" << seconds << endl;

        else
            cout << "Hours :" << hours << ","  <<" Minutes :" <<minutes << "," << " Seconds :" << seconds << endl;

    }


//////////////////////////////////Operator Overload ///////////////////////////////


    Duration_Time operator + (const Duration_Time& d)
    {
        Duration_Time res;
        res.setHours(hours + d.hours);
        res.setMinutes( minutes + d.minutes);
        res.setSecond(seconds + d.seconds);
        return res;
    }

    Duration_Time operator+(int x)
    {
        this->setSecond(seconds+x); //seconds += x;
        return *this;
    }

    friend Duration_Time operator+(int x, const Duration_Time& d);// d3 = 7800 + d1


    Duration_Time operator ++ () // ++ prefix
    {
        this->setMinutes(minutes + 1);
        return *this ;
    }

    Duration_Time operator ++ (int) // ++ postfix
    {
        Duration_Time temp = *this;
        this->setMinutes(minutes + 1);
        return temp;
    }


    Duration_Time operator -- () // ++ prefix
    {
        this->setMinutes(minutes - 1);
        return *this ;
    }

    Duration_Time operator -- (int) // ++ postfix
    {
        Duration_Time temp = *this;
        this->setMinutes(minutes - 1);
        return temp;
    }


    int operator > (Duration_Time& d)
    {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds_D = d.hours * 3600 + d.minutes * 60 + d.seconds;

        return (totalSeconds > totalSeconds_D);
    }

    int operator <= (Duration_Time& d)
    {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds_D = d.hours * 3600 + d.minutes * 60 + d.seconds;

        return (totalSeconds <= totalSeconds_D);
    }
/////////////////////////// Constructors /////////////////////////////

    Duration_Time() // parameterless
    {
        hours = minutes = seconds = 0;
    }

    Duration_Time(int _seconds) // one parameter
    {
        hours = minutes = 0;
        setSecond(_seconds);// _seconds;

    }

    Duration_Time(int _minutes , int _seconds) // two parameter
    {
        hours = 0;
        minutes = _minutes ;
        setSecond(_seconds);// _seconds;

    }

    Duration_Time(int _hours , int _minutes , int _seconds) // three parameter
    {
        hours = _hours;
        minutes = _minutes ;
        setSecond(_seconds);// _seconds;
    }


};

Duration_Time operator+(int x,Duration_Time& d) {
    d.setSecond(d.getSeconds() + x);
    return d;
}
void separateByLine();

int main()
{

    Duration_Time d1(1,10,15) , d2(3600) , d3(7800) , d4(666);

    //d1.setSecond(400);
    d1.print();
    d2.print();
    d3.print();
    d4.print();

    Duration_Time d5 = d1 + d2 ; //  2 : 10 : 15 // correct
    d5.print();
    separateByLine();

    Duration_Time d6 = 350 + d5 ; // 2 : 16 : 5 // correct
    d6.print();
    separateByLine();

    Duration_Time d7 = d6 + 350 ; // 2 : 21 : 55 // correct
    d7.print();
    separateByLine();

    Duration_Time d8 = d7++ ; // 2 : 21 : 55 // correct
    d8.print();
    d7.print();
    separateByLine();

    d8.print();
    Duration_Time d9 = ++d8; // 2 : 21 : 55 // correct
    d9.print();
    d8.print();
    separateByLine();

    d8 = d7-- ; // 2 : 21 : 55 // correct
    d8.print();
    d7.print();
    separateByLine();

    d8.print();
    d9 = --d8; // 2 : 21 : 55 // correct
    d9.print();
    d8.print();
    separateByLine();


    d1 > d2 ?  cout << "d1 is greater than d2\n" :  cout << "d2 is greater than d1\n" ;
    d8 <= d2 ?  cout << "d2 is greater than or equal d8\n" :  cout << "d8 is greater than or equal d2\n" ;

    return 0;
}


void separateByLine()
{
    cout << "=========================================" << endl;
}
