#include <stdio.h>
#include <stdlib.h>
#define size 5
int main()
{

    printf("please enter the array\n");
    int arr[size];

//====================Scan==========================
    for(int i =0 ; i<size ; i++)
    {
        printf("enter a number:");
        scanf("%d", &arr[i]);
    }

//====================Print==========================
    for(int i =0 ; i<size ; i++)
        printf("%d \t ", arr[i]);

    printf("\n");

//====================Print Max==========================
    int max = arr[0];

    for (int i = 0 ; i<size ; i++)
    {
        if (max<arr[i])
            max = arr[i];
    }
    printf("The maximum of the array = %d \n" , max);

//====================Print Min==========================
    int min = arr[0];

    for (int i = 0 ; i<size ; i++)
    {
        if (min>arr[i])
            min = arr[i];
    }
    printf("The minimum of the array = %d \n" , min);
    return 0;
}
