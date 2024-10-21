#include <stdio.h>
#include <stdlib.h>
void calculateFactorial(int n);


int main()
{
    printf("Enter a number to get its factorial : ");
    int numberToGetFactorial;
    scanf("%d", &numberToGetFactorial);
    calculateFactorial(numberToGetFactorial);
    return 0;
}


void calculateFactorial(int n)
{
    int factorial=1;
    for (int i = 1 ; i<= n ; i++)
    {
        factorial=factorial*i;
    }
    printf("the answer is %d",factorial);
}
