#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int column , int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}

void textattr(int i )
{
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE) , i );
}


int main()
{
    char ch;
    char menu[4][8] = { "New" , "Display" , "Exit" };

    int diserdLine=0;

    do{
        system("cls");


    //============================Draw The Menu ======================================//
        for(int stageLine =0 ; stageLine < 3; stageLine++)
        {
            gotoxy( 20 , 10+stageLine );
            if ( stageLine == diserdLine )
                textattr(0x74);
            _cprintf("%s", menu[stageLine]);
            textattr(0x07);
        }

        ch = _getch(); // wait

    //==================== check if extended or normal key =============================//

        switch(ch)
        {
            case -32:
                ch = _getch();
                switch (ch)
                {
                    case 72: //up
                        diserdLine --;
                        if (diserdLine<0)
                            diserdLine=2 ;
                        break;

                    case 80: //down
                        diserdLine ++;
                        if (diserdLine>2)
                            diserdLine=0 ;
                        break;

                }

                break;

            case 13: //Enter

                system("cls");
                if(diserdLine == 0)printf("New Selected --");
                else if(diserdLine == 1) printf("Display Selected --");
                else if(diserdLine == 2) printf("Exit Selected --");
                _getch();
                break;

            case 'n':
                system("cls");
                printf("New Selected ....\n");
                _getch();
                break;

            case 'd':
                system("cls");
                printf("Display Selected ....\n");
                _getch();
                break;

            case 'e':
                system("cls");
                printf("Exit Selected ....\n");
                _getch();
                break;

            default:
                system("cls");
                printf("invalid char");
                _getch();
                break;

        }



    }while(ch != 'e' && ch != 27);



    return 0;
}
