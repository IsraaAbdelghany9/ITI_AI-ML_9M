#include <stdio.h>
#include <stdlib.h>

int main()
{
//===============Var======================

    int x , y;
    char ch ;


//===============Menu======================
    printf("Enter no1 numbers ");
    scanf("%d", &x);
    printf("Enter no2 numbers ");
    scanf("%d", &y);
    _flushall();
    printf("Please select the operator that you need to perform : \n+ \n- \n* \n\\ \n ");
    scanf("%c", &ch);

//===============switch case======================

    switch (ch)
    {
        case '+':
            printf("%d + %d = %d " ,x , y , x+y);
            break;

        case '-':
            printf("%d - %d = %d " ,x , y , x-y);
            break;

        case '*':
            printf("%d * %d = %d " ,x , y , x*y);
            break;

        case '\\':
            printf("%d \\ %d = %d " ,x , y , (float)x/y);
            break;

        default:
            printf("Invalaid");
            break;

    }
    return 0;
}
