#include <windows.h>
#include <string.h>
#include <conio.h>
#include <iostream>
using namespace std;

#define numberOfLines 5

int empNumber;
int numberOfEmployeesEntered ;
int diserdLine;

void gotoxy(int column , int line);
void textattr(int i );


class menuSystem // Clear
{
    const char* menuOptions[numberOfLines];

public:
    menuSystem()
    {
        menuOptions[0] = "New";
        menuOptions[1] = "Display by ID";
        menuOptions[2] = "Display by name";
        menuOptions[3] = "Display All";
        menuOptions[4] = "Exit";
    }

    void startSys()
    {
        cout << "Wlcome to our Employee Mangement System :\n" ;
        cout << "PLease enter How many Employees do you want in your system ? " ;
        cin >> empNumber ;
    }

//============================Draw The Menu ======================================//
    void menuDisplay()
    {

        system("cls");  // Clear the screen for the next iteration

        for(int stageLine = 0; stageLine < numberOfLines; stageLine++)
        {
            gotoxy(20 , 10 + stageLine);
            if (stageLine == diserdLine)
                textattr(0x74);  // Change color to highlight
            cout << menuOptions[stageLine];  // Print the menu option
            textattr(0x07);  // Reset text color to default
        }

        //_getch(); // Wait till press any button
    }

    void clearMenu()
    {
        _getch();
        system("cls");
    }

};


class employee
{
    int ID; // ID of employee
    char name[30]; //names of employee
    int Age; // Age of employee

public:

    static employee *arr ; /////////////////////////////////ASK

    // Single constructor that handles all cases
    employee(int _ID = -1, char* _name = "no name yet", int _Age = 30)
    {
        cout << "employee CTOR" << endl;
        ID = _ID;
        strcpy(name, _name);
        Age = _Age;
        //numberOfEmployeesEntered ++ ;
    }

/////////////////////////////////////Setters///////////////////////////

    static void newEmployee()
    {
        cout << "New Selected --\n";

        if (numberOfEmployeesEntered < empNumber)
        {
            cout <<"Please Enter the ID :";
            cin >>  arr[numberOfEmployeesEntered].ID;
            cout <<"Please Enter the Age :";
            cin >>  arr[numberOfEmployeesEntered].Age;
            cout <<"Please Enter the Name :";
            cin >>  arr[numberOfEmployeesEntered].name;
        }
        else cout << "The array is FULL \n" ;
        numberOfEmployeesEntered ++ ;
        _getch();
    }

////////////////////////////////////Getters//////////////////////////////////////////////////

    int getID() { return ID ;}
    int getAge() { return Age ;}
    char* getName() { return name ;}

///////////////////////////////////Print//////////////////////////////////////////////////
    static void printAll()
    {
        if (numberOfEmployeesEntered == 0)
        {
            cout << "You have not entered any employees yet.\n";
            return;
        }

        for (int i = 0; i < numberOfEmployeesEntered; i++)
        {
            cout << "Employee no." << i+1 << " ID: " << arr[i].getID() << ", Name: " << arr[i].getName() << ", Age: " << arr[i].getAge() << endl;
        }
    }

    static void displayByID()
    {
        int IdToSearch;
        cout << "Display by ID Selected --\n" ;
        cout << "What is the ID you want to search about ?" ;
        cin >> IdToSearch ;
        int i;
        int found = 0 ;
        for ( int i =0 ; i< empNumber ; i++)
        {
            if(IdToSearch==arr[i].ID)
            {
                cout << "The ID is " << arr[i].getID() << endl ;
                cout << "The name is " << arr[i].getName() << endl ;
                cout << "The Age is " << arr[i].getAge() << endl ;
                found = 1;
                break;
            }
        }
            if (found == 0) {
                cout << "The ID was not found.\n";
            }
    }

    static void displayByName()
    {
        char NameToSearch[30];
        cout << "Display by Name Selected --\n" ;
        cout << "What is the ID you want to search about ?" ;
        cin >> NameToSearch ;
        int found = 0 ;
        int i;
        for ( i =0 ; i< empNumber ; i++)
        {
            if(strcmp(NameToSearch, arr[i].getName()) == 0)
            {
                cout << "The ID is " << arr[i].getID() << endl ;
                cout << "The name is " << arr[i].getName() << endl ;
                cout << "The Age is " << arr[i].getAge() << endl ;
                found = 1;
                break;
            }

        }
            if (found == 0) {
                cout << "The Name was not found.\n";
            }
    }
/////////////////////////////Destructor/////////////////////////////////////////
    ~employee()
    {
        //cout << "Employee destructor\n" ;
    }

};

employee* employee::arr = new employee[empNumber];

int main()
{

    menuSystem menu1;
    menu1.startSys();

    //employee::arr[numberOfEmployeesEntered] = employee(91125 , "israa" , 23) ;
    char ch ;
    //menu1.menuDisplay();

    do{
        menu1.menuDisplay();
        //==================== check if extended or normal key =============================//
        ch = _getch();
        switch(ch)
        {
            case -32:
                ch = _getch();
                switch (ch)
                {
                    case 72: //up
                        diserdLine --;
                        if (diserdLine<0)
                            diserdLine=numberOfLines-1 ;
                        break;

                    case 80: //down
                        diserdLine ++;
                        if (diserdLine>(numberOfLines-1))
                            diserdLine=0 ;
                        break;

                }

                break;

            case 13: //Enter

                system("cls");
                if(diserdLine == 0) employee::newEmployee();
                else if(diserdLine == 1) employee::displayByID();
                else if(diserdLine == 2) employee::displayByName();
                else if(diserdLine == 3) employee::printAll();
                else if(diserdLine == 4)
                {
                    ch = 'e';
                    cout << "Exit Selected --";
                }
                _getch();
                break;

            default:
                system("cls");
                cout << "invalid char" ;
                _getch();
                break;

        }



    }while(ch != 'e' && ch != 27);

    //employee::newEmployee();

    //employee::printAll();

    _getch();

    delete[] employee::arr; // Free the dynamically allocated memory
    return 0;
}


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


