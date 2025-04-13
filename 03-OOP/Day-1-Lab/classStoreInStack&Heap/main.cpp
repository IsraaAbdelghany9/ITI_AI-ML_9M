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


};



int main()
{
    employee e1;

    employee *e2 = new employee();
    delete e2;

    cout << "Hello world!" << endl;
    return 0;
}
