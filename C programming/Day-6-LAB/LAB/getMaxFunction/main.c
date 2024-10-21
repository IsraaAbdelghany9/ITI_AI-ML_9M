#include <stdio.h>
#include <stdlib.h>

int getMax(int x , int y);

int main()
{
    int x , y;
    printf("Hello !\n");
    printf("PLease enter 2 numbers to compare");

    scanf("%d",&x);
    scanf("%d",&y);

    printf("the maximum Number is %d" , getMax(x , y));

    return 0;
}


int getMax(int x , int y)
{
    if (x>y)
        return(x);

    return y;
}
