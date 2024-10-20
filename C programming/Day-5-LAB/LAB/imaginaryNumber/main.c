#include <stdio.h>
#include <stdlib.h>

struct imaginary
{
    int real;
    int img;
};

int main()
{
    struct imaginary numbers = {3 , 4};

    printf("the number is %d + %d i", numbers.real,numbers.img);

    return 0;
}
