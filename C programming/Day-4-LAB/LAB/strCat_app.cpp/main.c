#include <stdio.h>
#include <stdlib.h>

int main()
{
    char fname[6]= "Israa";
    char lname[11]= "Abdelghany";

    char fullname[17];


    strcpy(fullname , fname);

    strcat(fullname , " ");
    strcat(fullname , lname);

    printf("%s" , fullname);

    /*
    int address = &fname[1];

    for (int i = 0 ; i < 6 ; i++ )
    {
        printf("%c", fname[i] );
    }
    printf("%c", address);
    */

    return 0;
}
