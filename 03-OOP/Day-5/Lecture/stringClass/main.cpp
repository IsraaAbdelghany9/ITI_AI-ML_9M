#include <iostream>
#include <string.h>

using namespace std;

class stringClass
{
    int Size ;
    int activeIndex;
    char *arr;

public:
///////////////////////// Constructors ////////////////////////////////

    stringClass() // parameterless
    {
        Size = 10 ;
        activeIndex = -1;
        arr = new char[Size];
    }

    stringClass(int _Size) // one parameter
    {
        Size = _Size+10 ;
        activeIndex = -1;
        arr = new char[Size];
    }

    stringClass(int _Size , char* name) // two parameter
    {
        Size = _Size+10 ;
        arr = new char(Size);
        strcpy(arr , name);
        activeIndex = strlen(arr) - 1;
        //cout << activeIndex <<endl;
    }

    stringClass(char* name) // two parameter
    {
        Size = strlen(name)+10 ;
        arr = new char(Size);
        strcpy(arr , name);
        activeIndex = strlen(arr) - 1;
    }

//////////////////////// Setters ///////////////////////

    void setSize(int _Size)
    {
        Size = _Size;
    }

    void setString(char *name)
    {
        if (activeIndex + strlen(name) < Size)
        {
            strcat(arr , name);
            activeIndex += strlen(name);
        }
        else
            cout << "The size of input string exceeding the available size left\n";
    }


//////////////////////// Getters ///////////////////////

    int getSize()
    {
        return Size;
    }

    int getActiveIndex()
    {
        return activeIndex;
    }

    char* getString()
    {
        for (int i = 0 ; i <= activeIndex ; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
//////////////////////// Print ///////////////////////

    void print()
    {
        cout << "Size = "<< Size << ", The activeIndex = " << activeIndex  ;
        if (activeIndex == -1) cout << "The String you are trying to print is empty\n" ;
        else
        {
            cout << ", String is " ;
            for (int i = 0 ; i <= activeIndex ; i++)
            {
                cout << arr[i];
            }
        }

        cout << endl;
    }
//////////////////////// Operator Overload ///////////////////////////

    stringClass operator = (stringClass const &c)
    {
        activeIndex = c.activeIndex;
        Size = c.Size ;
        strcpy(arr , c.arr);
    }

    stringClass operator + (const stringClass &s)
    {
        stringClass result(Size + s.Size);

        strcpy(result.arr , arr);
        strcat(result.arr , s.arr);
        result.activeIndex = strlen(result.arr)-1;

        return result;
    }

///////////////////////// Copy Constructor ////////////////////////////////

    stringClass(const stringClass &s) // By reference
    {
        cout<<"you are in copy by reference constructor"<<endl;
        activeIndex=s.activeIndex;
        Size=s.Size;
        arr = new char[Size]; // Allocate memory for arr to prevent shallow copy
        strcpy(arr, s.arr);
    }

///////////////////////// Destructor ////////////////////////////////

    ~stringClass()
    {
        delete arr ;
        cout << "object deleted successfully\n";
    }

};

int main()
{

    stringClass s1(5 , "israa");
    s1.print();

    stringClass s3("Ahmed");
    s3.print();

    stringClass s4("hi");
    s4.setString("Hi");
    s4.print();


    stringClass s5 = s4 ;
    s5.print();

    stringClass s6 = s5 + s4 ;
    s6.print();

    stringClass s7(s6);
    s7.print();

    return 0;
}
