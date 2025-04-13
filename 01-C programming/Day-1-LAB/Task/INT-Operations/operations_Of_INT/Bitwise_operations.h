#ifndef BITWISE_OPERATIONS_H_INCLUDED
#define BITWISE_OPERATIONS_H_INCLUDED

void and_operation(int number1,int number2)
{
    if (number1 && number2)
        printf("%d and %d is TRUE\n" ,number1 , number2);
    else
        printf("%d and %d is False\n" ,number1 , number2);
}

void or_operation(int number1,int number2)
{
    if (number1 || number2)
        printf("%d or %d is TRUE\n" ,number1 , number2);
    else
        printf("%d or %d is False\n" ,number1 , number2);}

void xor_operation(int number1,int number2)
{
    if (number1 ^ number2)
        printf("%d xor %d is True \n" , number1 , number2 );
    else
        printf("%d xor %d is False \n", number1 , number2 );
}
#endif // BITWISE_OPERATIONS_H_INCLUDED
