#include <stdio.h>
#include <stdlib.h>
#define NameMaxNumOfCharacter 30
#define NumberOfEmployees 5

struct employee
{
    char name[NameMaxNumOfCharacter];
    int ID;
    int Age;
};


int main()
{
    struct employee emp1 = {"Israa ", 91125 , 23};

    struct employee emp2[NumberOfEmployees] = {};

    for(int i = 0 ; i < NumberOfEmployees ; i++ )
    {
        printf("PLease Enter the data of the %d Employee : Name - ID - Age \n " , i);
        scanf("%s", &emp2[i].name );
        scanf("%d", &emp2[i].ID );
        scanf("%d", &emp2[i].Age );
    }

    for(int i = 0 ; i < NumberOfEmployees ; i++ )
    {
        printf("The %d employee data is :");
        printf("%s", emp2[i].name );
        printf("%d", emp2[i].ID );
        printf("%d\n", emp2[i].Age );
    }


    return 0;
}
