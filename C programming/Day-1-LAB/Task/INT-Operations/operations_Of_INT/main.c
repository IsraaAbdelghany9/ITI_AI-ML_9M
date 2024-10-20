#include <stdio.h>
#include <stdlib.h>
#include "arithmaticOperations.h"
#include "relationalOperations.h"
#include "Bitwise_operations.h"


int main()
{
    printf(" Welcome to Our Application \n");

    while(1)
    {
        int num1 , num2;
        printf("please enter Number1\n");
        scanf("%d", &num1);
        printf("please enter Number2\n");
        scanf("%d", &num2);

        printf("\n");
        printf("============= Arithmetic Operations=========\n");
/*
        subtraction(num1,num2);
        add(num1,num2);
        multiplication(num1,num2);
        division(num1,num2);
        modulus_(num1,num2);
        */
        increment(num1,num2);
        decrement(num1,num2);

/*        printf("\n");
        printf("============= Relational Operations=========\n");

        isEqual(num1,num2);
        Compare_two_numbers(num1,num2);

        printf("\n");
        printf("============= Bitwise Operations=========\n");
        and_operation(num1,num2);
        or_operation(num1,num2);
        xor_operation(num1,num2);

        printf("\n");
        printf("Try Again\n");*/
    }
    printf("THE END \n BYE \n");

    getchar();
    return 0;
}
