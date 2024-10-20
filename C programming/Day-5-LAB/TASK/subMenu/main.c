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
    char subMenu1[3][12] = {"Israa","Abdelghany","Ibrahim"};
    char subMenu2[3][12] = {"Ibrahim","Israa","Abdelghany"};
    char subMenu3[3][12] = {"Abdelghany","Ibrahim","Israa"};

    int diserdLine=0;

    int diserdLine_inSubMenu=0;

    do{
        //system("cls");

    //============================Draw The Main Menu ======================================//
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
    //==================== check if extended or normal key =============================//

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

    //==================== check if extended or normal key =============================//

            case 13: //Enter

                switch(diserdLine )
                {
                    case 0:
                        for (int submenu_Elementselected=0; submenu_Elementselected<3 ; submenu_Elementselected++)
                        {
                            gotoxy( 40 , 10+submenu_Elementselected );
                            if ( submenu_Elementselected == diserdLine_inSubMenu )
                                textattr(0x74);
                            _cprintf("%s", subMenu1[submenu_Elementselected]);
                            textattr(0x07);
                        }
                    //_getch();
                    //break;
                    case 1:
                        for (int submenu_Elementselected=0; submenu_Elementselected<3 ; submenu_Elementselected++)
                        {
                            gotoxy( 40 , 10+submenu_Elementselected );
                            if ( submenu_Elementselected == diserdLine_inSubMenu )
                                textattr(0x74);
                            _cprintf("%s", subMenu2[submenu_Elementselected]);
                            textattr(0x07);
                        }
                    //_getch();
                    //break;
                    case 2:
                        for (int submenu_Elementselected=0; submenu_Elementselected<3 ; submenu_Elementselected++)
                        {
                            gotoxy( 40 , 10+submenu_Elementselected );
                            if ( submenu_Elementselected == diserdLine_inSubMenu )
                                textattr(0x74);
                            _cprintf("%s", subMenu3[submenu_Elementselected]);
                            textattr(0x07);
                        }
                    //_getch();
                    //break;
                    ch = _getch();
                    switch (ch)
                    {
                        case -32:
                            case 72: //up
                                diserdLine_inSubMenu --;
                                if (diserdLine_inSubMenu<0)
                                    diserdLine_inSubMenu=2 ;
                                break;

                            case 80: //down
                                diserdLine_inSubMenu ++;
                                if (diserdLine_inSubMenu>2)
                                    diserdLine_inSubMenu=0 ;
                                break;

                            case 75 : //left

                                break;

                            case 77 : //right

                                break;


                    }



                ///////////////////////////////////////////////////////
            //_getch();
    //==================== check if extended or normal key =============================//

                break;
            case 'n':
                system("cls");
                printf("New Selected ....\n");
                _getch();
                break;
    //==================== check if extended or normal key =============================//

            case 'd':
                system("cls");
                printf("Display Selected ....\n");
                _getch();
                break;
    //==================== check if extended or normal key =============================//

            case 'e':
                system("cls");
                printf("Exit Selected ....\n");
                _getch();
                break;
    //==================== check if extended or normal key =============================//

            default:
                system("cls");
                printf("invalid char");
                _getch();
                break;


        }



    }while(ch != 'e' && ch != 27);



    return 0;
}
