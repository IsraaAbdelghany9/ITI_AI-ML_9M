#include <iostream>
#include <string.h>
using namespace std;

class employee
{
    int ID;
    int Age;
    char name[100];

public:

    void setID(int _ID)
    {
        ID=_ID ;
    }

    void setAge(int _Age)
    {
        Age=_Age;
    }

    void setName(char _name[])
    {
        strcpy(name , _name);
    }

    int getID()
    {
        return ID;
    }
    int getAge()
    {
        return Age;
    }

    char* getName()
    {
        return name;
    }

    void print()
    {
        cout<<ID<<":"<<name<<":"<<Age<<endl;
    }

    employee()
    {
        ID=0;
        Age = 30;
        strcpy(name , "no name");
    }

    employee(int _ID , char _name[])
    {
        ID= _ID;
        strcpy(name , _name);
        Age = 30;
    }
    employee(int _ID , char _name[] , int _Age)
    {
        ID= _ID;
        strcpy(name , _name);
        Age = _Age;
    }
    employee(int _ID)
    {
        ID = _ID ;
        strcpy(name , "no name yet");
        Age = 30 ;
    }
    ~employee()
    {
        cout<<"object dead"<<endl;
    }
};


int main()
{
    employee emp1(11,"israa");
    emp1.print();
    emp1.getName();

    employee emp2(22,"Ali",66);
    emp2.print();
    //cout << "Hello world!" << endl;
    return 0;
}
