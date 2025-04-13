#include <iostream>

using namespace std;

void swap2numbersByValue(int x , int y);
void swap2numbersByPointers(int *x, int *y);
void swap2numbersByReference(int &x , int &y);

int main()
{
    int x = 3 , y = 4;

    // Using copy (no effect on x and y in main)
    swap2numbersByValue(x, y);
    cout << "Numbers after swap (by value) are: " << x << "\t" << y << endl;

    // Using pointers (actual swap)
    swap2numbersByPointers(&x, &y);
    cout << "Numbers after swap (by pointer) are: " << x << "\t" << y << endl;

    // Using reference (actual swap)
    swap2numbersByReference(x, y);
    cout << "Numbers after swap (by reference) are: " << x << "\t" << y << endl;


    return 0;
}

//Can not have a return type
//Have copy of data
//Do not affect the actual variables of the main
void swap2numbersByValue(int x , int y)
{
    int temp;
    temp = x ;
    x=y;
    y=temp;
    cout<< "numbers after swap inside by value function are" << x<< y <<endl;

}


void swap2numbersByPointers(int *x, int *y)
{
    int temp = *x ;
    *x = *y ;
    *y = temp ;
}

void swap2numbersByReference(int &x , int &y)
{
    int temp = x ;
    x = y ;
    y = temp ;
}
