#ifndef RELATIONALOPERATIONS_H_INCLUDED
#define RELATIONALOPERATIONS_H_INCLUDED


void isEqual(int number1 , int number2)
{
    if (number1== number2)
        printf("The numbers are Equal \n");

    else
        printf("The numbers are not Equal \n");
}

void Compare_two_numbers(int number1 , int number2)
{
    if (number1== number2)
        printf("The numbers are Equal");

    else if (number1> number2)
        printf("Number %d is higher than %d \n", number1 , number2);

    else
        printf("Number %d is higher than %d \n", number2 , number1);

}



#endif // RELATIONALOPERATIONS_H_INCLUDED
