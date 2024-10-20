#include <stdio.h>
#include <stdlib.h>
void calculateFactorial(int n)
{
    int factorial=1;
    for (int i = 1 ; i<= n ; i++)
    {
        factorial=factorial*i;
    }
    printf("the answer is %d",factorial);
}
int main()
{
    calculateFactorial(5);
    return 0;
}
