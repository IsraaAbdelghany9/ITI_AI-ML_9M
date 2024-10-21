#include <stdio.h>
#include <stdlib.h>
#define NumberOfEmployees 5
#define NameMaxNumOfCharacter 30

struct employee
{
    char name[NameMaxNumOfCharacter];
    int ID;
    int Age;
};



int main()
{
    struct employee emp2;
    struct employee *ptr = &emp2;

    printf("Enter the employee ID");
    scanf("%d",&(ptr->ID));

    printf("%d is" , ptr->ID);


    return 0;
}

