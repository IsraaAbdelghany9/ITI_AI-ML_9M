#include <iostream>

using namespace std;

int add ( int a = 0 , int b = 0 , int c = 0 , int d = 0 );


int main()
{
    cout << add() << endl;
    cout << add(3) << endl;
    cout << add(3,5) << endl;
    cout << add(3,5,6) << endl;
    cout << add(3,5,6,8) << endl;

    return 0;
}


int add ( int a, int b, int c , int d )
{
    return (a + b + c + d);
}
