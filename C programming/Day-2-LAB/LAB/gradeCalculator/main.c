#include <stdio.h>
#include <stdlib.h>

int main()
{
    int degree;

    int x;
    while (1)
    {
        printf("please enter your degree to calculate\n");
        _flushall();
        scanf("%d", &degree );

        if (degree>= 85 && degree <= 100 )
            printf("Excelant \n");
        else if (degree >= 75)
            printf("Very Good \n");

        else if (degree >= 65)
            printf("Good \n");

        else if (degree >= 50)
            printf("acceptable \n");

        else if (degree < 50)
            printf("Failed \n");

        else
            printf("invalaid number");

        getch();
        system("cls");
    }
    return 0;
}
