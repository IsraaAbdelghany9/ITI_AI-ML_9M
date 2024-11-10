#include <iostream>

using namespace std;

class Stack
{
    int size ;
    int *arr;
    int tos ;

public:
    Stack(int _size)
    {
        size = _size;
        tos = -1 ;
        arr=new int[size];
    }

    Stack()
    {
        size = 5;
        tos = -1 ;
        arr=new int[size];
    }

    void Push(int d)
    {
        if (tos < size -1)
        {
            tos++;
            arr[tos] = d ;
        }
        else cout<< "Sorry ,Stack is full"<<endl;
    }
    int Pop(int& d)
    {
        if (tos != -1)
        {
            d = arr[tos];
            tos--;
            return 1;
        }
        else
        {
            cout<< "Sorry, Sack is empty "<<endl;
            return 0;
        }
    }

/*    Stack(Stack &s) // By reference
    {
        cout<<"you are in copy by reference constructor"<<endl;
        tos=s.tos;
        size=s.size;
        arr = new int[size]; // Allocate memory for arr to prevent shallow copy
        for (int i = 0; i <= tos ; i++)
            arr[i]=s.arr[i];

    }
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////


    Stack operator = (Stack &s) // stack = stack
    {
        tos = s.tos ;
        size = s.size ;
        arr = new int[size]; // Allocate memory for arr to prevent shallow copy
        for (int i = 0; i <= tos ; i++)
            arr[i]=s.arr[i];

        return *this ;
    }

    Stack operator +(const Stack &s)
    {
        Stack result(size + s.size); // Create a new stack large enough for both stacks

        // Copy elements from the first stack
        for (int i = 0; i <= tos; i++)
            result.Push(arr[i]);

        // Copy elements from the second stack
        for (int i = 0; i <= s.tos; i++)
            result.Push(s.arr[i]);

        return result;
    }


//////////////////////////////////////////////////////////////////////////////////////////////////////

    void print() {
        for (int i = 0; i <= tos; i++)
            cout << arr[i] << endl;
        cout << endl;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////

    ~Stack()
    {
        cout<<"Object has  been deleted"<<endl;
        delete arr;
    }

};

int main()
{
//////////////////Object Creation///////////////
    Stack s1(5) , s2(3) ;//s3(1);

//////////////////////PUSH//////////////////////
    s1.Push(40);
    s1.Push(50);
    s1.Push(60);
    s1.Push(70);
    s1.Push(80);
    s1.Push(90);

////////////////////// = //////////////////////////
    s2=s1;
    int x = 0 ;
/*
    if (s2.Pop(x) == 1) cout << x << endl;
    if (s2.Pop(x) == 1) cout << x << endl;
    if (s2.Pop(x) == 1) cout << x << endl;
    if (s2.Pop(x) == 1) cout << x << endl;
*/

///////////////////////// + /////////////////////
    {
        Stack s4;
    }
    Stack s3 = s1 + s2;
    s3.print();
/////////////////////////END////////////////////
    cout << "BYE!" << endl;

    return 0;
}




//    s3 = s1+s2;
