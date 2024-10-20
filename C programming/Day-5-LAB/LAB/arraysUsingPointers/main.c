#include <stdio.h>
#include <stdlib.h>
#define size 5


int main()
{

    //=========================== Welcome Message ===============================

    printf("Welcome to our Program\n");
    _getch();
    system("cls");

    //=========================== Start the  Program ===============================
    int arr[size];

    int *ptr = arr;//address equality

    for(int i = 0 ; i<size ; ++i)
    {
        printf("Please enter a number : ");
        scanf("%d",(ptr+i));
    }

    for(int i = 0 ; i<size ; ++i)
    {
        printf("the %d element in the array is = %d \n",i,*(ptr+i));
    }

    return 0;
}
