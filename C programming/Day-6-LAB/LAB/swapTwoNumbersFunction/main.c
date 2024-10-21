#include <stdio.h>
#include <stdlib.h>

void swap2numbers(int *x , int *y);

int main()
{
    int x , y;
    printf("Hello !\n");
    printf("PLease enter 2 numbers to swap");

    scanf("%d",&x);
    scanf("%d",&y);

    printf("Numbers before swap are : x= %d and y = %d \n" , x , y);

    swap2numbers( &x , &y);
    printf("Numbers after swap are : x= %d and y = %d \n" , x , y);

    return 0;
}

void swap2numbers(int *x , int *y)
{
    int temp = *x;
    *x = *y ;
    *y = temp ;
}

