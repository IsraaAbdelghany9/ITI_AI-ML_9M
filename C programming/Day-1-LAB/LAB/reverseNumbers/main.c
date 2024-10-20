#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[3];
    for (int i =0 ; i<3 ; i++)
    {
        printf("Enter the number %d number :\n", i);
        scanf("%d", &num[i]);
    }
    for (int j = 2 ;  j>=0 ; j-- )
    {
        printf("\n%d ", num[j]);
    }
    return 0;
}
