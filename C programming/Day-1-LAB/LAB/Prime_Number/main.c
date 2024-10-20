#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    char ch;
    while(1)
    {
        system("cls");
        printf("plz enter the number to check:\n");
        scanf("%d", &num );

        int counter=1;
        for (int i=1; i<num ; i++ )
        {
            if (num%i == 0)
                counter++;
        }
        if (counter == 2 )
            printf("%d is a prime Number and counter is %d ",num ,counter);
        else
            printf("%d is Not Prime Number and counter is %d ",num ,counter);
        _flushall();
        scanf("%c",&ch);

    }

    return 0;
}
