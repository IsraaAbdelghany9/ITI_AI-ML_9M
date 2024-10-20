#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int i) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

int main() {

    char ch; // character to check the input

    char menu[3][8] = { "New", "Display", "Exit" };

    char subMenu1[3][12] = { "Israa", "Abdelghany", "Ibrahim" };
    char subMenu2[3][12] = { "Ibrahim", "Israa", "Abdelghany" };
    char subMenu3[3][12] = { "Abdelghany", "Ibrahim", "Israa" };

    int diserdLine = 0;
    int diserdLine_inSubMenu = 0;

    int inSubMenu = 0; // 0-> main menu & 1-> submenu

    do {
        system("cls");

        // ============================ Draw The Main Menu ======================================//
        for (int stageLine = 0; stageLine < 3; stageLine++) {
            gotoxy(20, 10 + stageLine);
            if (stageLine == diserdLine && !inSubMenu)
                textattr(0x74);
            printf("%s", menu[stageLine]);
            textattr(0x07);
        }

        // ============================ Draw The Sub-menu if Active ============================//
        if (inSubMenu) {
            char (*currentSubMenu)[12];
            switch (diserdLine) {
                case 0: currentSubMenu = subMenu1; break;
                case 1: currentSubMenu = subMenu2; break;
                case 2: currentSubMenu = subMenu3; break;
            }

            for (int submenu_Elementselected = 0; submenu_Elementselected < 3; submenu_Elementselected++) {
                gotoxy(40, 10 + submenu_Elementselected);
                if (submenu_Elementselected == diserdLine_inSubMenu)
                    textattr(0x74);
                printf("%s", currentSubMenu[submenu_Elementselected]);
                textattr(0x07);
            }
        }

        ch = _getch(); // wait for key press

        // ============================ Handle Input ============================//
        switch (ch) {
            case -32: // Extended keys
                ch = _getch();
                if (!inSubMenu) { // Main menu navigation
                    switch (ch) {
                        case 72: // Up arrow
                            diserdLine--;
                            if (diserdLine < 0)
                                diserdLine = 2;
                            break;
                        case 80: // Down arrow
                            diserdLine++;
                            if (diserdLine > 2)
                                diserdLine = 0;
                            break;
                    }
                } else { // Sub-menu navigation
                    switch (ch) {
                        case 72: // Up arrow
                            diserdLine_inSubMenu--;
                            if (diserdLine_inSubMenu < 0)
                                diserdLine_inSubMenu = 2;
                            break;
                        case 80: // Down arrow
                            diserdLine_inSubMenu++;
                            if (diserdLine_inSubMenu > 2)
                                diserdLine_inSubMenu = 0;
                            break;
                        case 75: // Left arrow
                            inSubMenu = 0; // Go back to main menu
                            break;
                    }
                }
                break;

            case 13: // Enter key
                if (!inSubMenu) {
                    inSubMenu = 1; // Enter the sub-menu
                    diserdLine_inSubMenu = 0; // Reset sub-menu selection
                }
                break;

            case 27: // Escape key to exit
                ch = 'e';
                break;
        }
    } while (ch != 'e' && );

    return 0;
}
