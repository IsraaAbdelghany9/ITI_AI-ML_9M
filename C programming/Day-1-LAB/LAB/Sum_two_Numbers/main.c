#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x , y;

    printf("please Enter the first number : \n");
    scanf("%d", &x);

    printf("please Enter the Second number : \n");
    scanf("%d", &y);

    printf("%d + %d = %d", x , y , x+y);

    printf("%d - %d = %d", x , y , x-y);

    printf("%d * %d = %d", x , y , x*y);

    return 0;
}
