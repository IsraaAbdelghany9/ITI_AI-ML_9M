#include <stdio.h>
#include <stdlib.h>
#define size 10

int main()
{
    int num;
    char ch;

    //int arrayOfPrimeNumbers[size] = {0};
    //int *ptr = arrayOfPrimeNumbers;
    do
    {
        int arrayOfPrimeNumbers[size] = {0};
        int *ptr = arrayOfPrimeNumbers;

        system("cls");
        printf("plz enter the number to check , allowed numbers are : 0 -> 50\n");
        scanf("%d", &num );


        for (int stateNumber = 1 ; stateNumber < num ; ++stateNumber)
        {
            int counter=0;
            for (int divide_on=1; divide_on<=stateNumber ; divide_on++ )
            {
                if (stateNumber%divide_on == 0)
                    counter++;
            }

            if (counter == 2 )
            {
                *ptr = stateNumber;
                ptr++;
            }
        }

        //====================print the array ====================
        for(int k = 0 ; k < size ;k++)
        {
            if (arrayOfPrimeNumbers[k] != 0)
                printf("%d is a prime number \n", arrayOfPrimeNumbers[k]);
        }
        ch =_getch();
    }while(ch != 27 );

    return 0;
}
