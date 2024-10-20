#include <stdio.h>
#include <stdlib.h>
#define NumberOfPoints 4

struct two_D_value
{
    int x;
    int y;
};

int main()
{
    struct two_D_value values[NumberOfPoints];

    for (int i = 0 ; i < NumberOfPoints ; i++)
    {

    printf("Enter a 2D value : \n x= ");
    scanf("%d", &values[i].x);

    printf("y= ");
    scanf("%d", &values[i].y);

    }

    for (int i = 0 ; i < NumberOfPoints ; i++)
        printf("The values of the %d element x = %d , y = %d \n", i , values[i].x , values[i].y );


    printf("Hello world!\n");
    return 0;
}
