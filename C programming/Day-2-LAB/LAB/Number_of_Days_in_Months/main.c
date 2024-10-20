#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i ;
    printf("enter the month number");
    scanf("%d", &i);

    switch (i)
    {
        case 1:
            printf("There are 31 Days in Jan ");
            break;

        case 2:
            printf("There are 28 Days in Fab ");
            break;

        case 3:
            printf("There are 31 Days in March ");
            break;

        case 4:
            printf("There are 30 Days in April ");
            break;
        case 5:
            printf("There are 31 Days in May ");
            break;

        case 6:
            printf("There are 30 Days in June ");
            break;

        case 7:
            printf("There are 31 Days in July ");
            break;

        case 8:
            printf("There are 31 Days in Auguest ");
            break;
        case 9:
            printf("There are 30 Days in Sep ");
            break;

        case 10:
            printf("There are 31 Days in Oct ");
            break;

        case 11:
            printf("There are 30 Days in Nov ");
            break;

        case 12:
            printf("There are 31 Days in Dec ");
            break;

        default:
            printf("Invalaid Number");
            break;

    }
    return 0;
}
