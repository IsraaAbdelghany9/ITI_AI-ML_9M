#include <iostream>
#include <string.h>
using namespace std;

struct employee
{
    int ID;
    int Age;
    char name[100];

//public: // it is public by default

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

};


int main()
{
    employee emp1,emp2;
    emp1.Age=30;
    emp1.ID = 91125;
    strcpy(emp1.name,"Israa");
    emp1.print();

    emp2.setAge(33);
    emp2.setID(2453);
    emp2.setName("Ahmed");
    emp2.print();
    return 0;
}
