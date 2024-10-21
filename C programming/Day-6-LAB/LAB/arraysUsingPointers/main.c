#include <stdio.h>
#include <stdlib.h>
#define size 5


void enterArrayValues(int *ptr);
void printArrayValues(int *ptr);
int getSumArrayValues(int *ptr);

int main()
{
    int arr[size];

    printf("Welcome!\n");
    printf("Please Enter Numbers!\n");

    enterArrayValues(arr);

    printf("Numbers you have entered are :\n");
    printArrayValues(arr);

    printf("\n the sum of array values is %d",getSumArrayValues(arr));
    return 0;
}


void enterArrayValues(int arr[])
{
    for(int i = 0 ; i <size ; i++)
        scanf("%d", &arr[i]);
}

void printArrayValues(int arr[])
{
    for(int i = 0 ; i <size ; i++)
        printf("\n %d \t", arr[i]);
}

int getSumArrayValues(int arr[])
{
    int sum = 0;
    for(int i = 0 ; i <size ; i++)
        sum+=arr[i];

    return sum;
}
