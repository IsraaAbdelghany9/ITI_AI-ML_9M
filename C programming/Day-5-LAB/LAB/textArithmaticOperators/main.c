#include <stdio.h>
#include <stdlib.h>



int main()
{
    int x = 20;
    int y = 10;

    int z = x +y;
    printf("x= %d \t y= %d \t z=%d \n" ,x,y, z);

     z = ++x+y;
    printf("x= %d \t y= %d \t z=%d \n" ,x,y, z);

     z = ++x+y;
    printf("x= %d \t y= %d \t z=%d \n" ,x,y, z);

     z = x+y++;
    printf("x= %d \t y= %d \t z=%d \n" ,x,y, z);



    printf("Hello world!\n");
    return 0;
}
