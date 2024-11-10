#include <iostream>

using namespace std;

class Stack
{
    int size ;
    int arr[5];
    int tos ;

public:
    Stack()
    {
        size = 5;
        tos = -1 ;
        arr[5];
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

    Stack(Stack &s) // By reference
    {
        cout<<"you are in copy constructor"<<endl;
        tos=s.tos;
        size=s.size;
        for (int i = 0; i <= tos ; i++)
            arr[i]=s.arr[i];

    }

    ~Stack()
    {
        cout<<"Object has  been deleted"<<endl;
    }

};

myfunction(Stack s) // By value
{
    cout<<"you are in copy by value constructor"<<endl;

    int x = 0;
    if (s.Pop(x) == 1) cout << x << endl;
    if (s.Pop(x) == 1) cout << x << endl;
    if (s.Pop(x) == 1) cout << x << endl;
    if (s.Pop(x) == 1) cout << x << endl;
    if (s.Pop(x) == 1) cout << x << endl;
    if (s.Pop(x) == 1) cout << x << endl;
}

myfunction2(Stack *s) // By value
{
    cout<<"you are in copy by value constructor"<<endl;

    int x = 0;
    if (s->Pop(x) == 1) cout << x << endl;
    if (s->Pop(x) == 1) cout << x << endl;
    if (s->Pop(x) == 1) cout << x << endl;
    if (s->Pop(x) == 1) cout << x << endl;
    if (s->Pop(x) == 1) cout << x << endl;
    if (s->Pop(x) == 1) cout << x << endl;
}
int main()
{
//////////////////Object Creation///////////////
    Stack s1;

//////////////////////PUSH//////////////////////
    s1.Push(40);
    s1.Push(50);
    s1.Push(60);
    s1.Push(70);
    s1.Push(80);
    s1.Push(90);


//////////////////////POP//////////////////////
    int x = 0 ;
/*
    if (s1.Pop(x) == 1) cout << x << endl;
    if (s1.Pop(x) == 1) cout << x << endl;
    if (s1.Pop(x) == 1) cout << x << endl;
    if (s1.Pop(x) == 1) cout << x << endl;
    if (s1.Pop(x) == 1) cout << x << endl;
    if (s1.Pop(x) == 1) cout << x << endl;
*/

///////////////////////Copy constructor//////////////////
    Stack s2(s1); // by reference

    myfunction(s1); // by value

    myfunction2(&s1); // by pointer
/////////////////////////END////////////////////
    cout << "BYE!" << endl;

    return 0;
}
