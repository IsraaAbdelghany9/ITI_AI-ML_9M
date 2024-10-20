#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum=0;
    int x;
    printf("please enter a 5 integer numbers");

    for(int i =0 ; i<5 ; i++)
    {
        printf("Number %d Number : \n" , i);
        scanf("%d",&x);
        sum+=x;
    }

    printf("The result = %d",sum);
    return 0;
}
