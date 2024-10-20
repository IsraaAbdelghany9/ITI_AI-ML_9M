#include <stdio.h>
#include <stdlib.h>

#define num_of_rows 3
#define num_of_columns 4

int main()
{
    int arr[num_of_rows][num_of_columns];

//====================Scan==========================

    for (int i = 0; i <num_of_rows ; i++)
    {
        for (int j=0 ; j<num_of_columns ; j++)
        {
            printf("Enter a number in [%d][%d] :" , i , j);
            scanf("%d", &arr[i][j]);
        }
    }

//====================Print==========================

    for (int i = 0; i <num_of_rows; i++)
    {
        for (int j=0 ; j<num_of_columns ; j++)
        {
            printf("%d\t" , arr[i][j]);
        }
        printf("\n");
    }


//====================Find Sum==========================

    int sum[num_of_rows]={0};

    for (int i = 0 ; i < num_of_rows ; i++)
    {
        for (int j=0 ; j<num_of_columns ; j++)
        {
            sum[i]+=arr[i][j];
        }
    }

//====================Print Sum==========================

    for (int i = 0 ; i < num_of_rows ; i++)
    {
        printf("the sum number %d is %d \n", i , sum[i]);
    }

    return 0;
}
