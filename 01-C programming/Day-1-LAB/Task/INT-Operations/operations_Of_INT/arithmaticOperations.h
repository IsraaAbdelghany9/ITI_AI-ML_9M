#ifndef ARITHMATICOPERATIONS_H_INCLUDED
#define ARITHMATICOPERATIONS_H_INCLUDED

void multiplication(int num1 , int num2)
{
    printf("%d * %d = %d \n", num1 , num2 ,num1*num2);
}

void add(int num1 , int num2)
{
    printf("%d + %d = %d \n", num1 , num2 ,num1+num2);
}

void subtraction(int num1 , int num2)
{
    printf("%d - %d = %d \n", num1 , num2 ,num1-num2);
}

void division(int num1 , int num2)
{
    printf("%d / %d = %d \n", num1 , num2 ,num1/num2);
}

void modulus_(int num1 , int num2)
{
    printf("%d modulus %d = %d \n", num1 , num2 ,num1%num2);
}


void increment(int num1 , int num2)
{
    printf("The incremental of %d = %d and the incremental of %d = %d \n", num1 , num1+1 , num2 ,num2+1);
}


void decrement(int num1 , int num2)
{
    printf("The decremental of %d = %d and the decremental of %d = %d \n", num1 ,num1-1 , num2 , num2-1);
}
#endif // ARITHMATICOPERATIONS_H_INCLUDED
