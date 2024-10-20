#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch ,y;
    printf("Welcome\n");

    do
    {
        system("cls");

        printf("Please select from the menu:\n");
        printf("================================\n");
        printf("n for New \nd for Display \ne for Exit \n");

        scanf("%c",&ch);

        switch(ch)
        {
        case 'n':
            printf("You have selected New ,\n");
            break;

        case 'd':
            printf("You have selected Display ,\n");
            break;

        case 'e':
            printf("You have selected Exit ,\n");
            break;
        }
        getch();
       // scanf("%c",&y);

    }while(ch != 'e');

    return 0;
}
