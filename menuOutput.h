#include <iostream>
using namespace std;

void displayInstructions();

int mainMenu()
{
    startSwitch:
    system("cls");
    cout<<"************ WELCOME TO THE GAME OF ZOAIL***************\n";
	cout<<"Select any of the following option: \n";
	cout<<"<1> New Game \n<2> Load Game \n<3> Instructions \n<4> Exit \n";
	int n;
    cin>>n;

    switch (n)
    {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            displayInstructions();
            goto startSwitch;
        case 4:
            cout << "Thank you for playing!\n";
            exit(0);
        default: 
            cout<<"invalid argument!";
            goto startSwitch;
    }
}

void displayInstructions()
{
    system("cls"); 
    cout << "\t\t\tINSTRUCTIONS FOR THE GAME\n";
    cout << "The game decision-based game that the player will make throughout its course.\nMay include choosing between paths and items.";
    cout << "\nAt any point in time, if the user chooses to enter 'S' as the input, the player will commit suicide.\n";
    cout << "\nYou can also press 'I' for Inventory.\n";
    system("pause");
}