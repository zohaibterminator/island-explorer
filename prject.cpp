#include <iostream>
#include "classes.h"
#include "trees.h"
#include "menuOutput.h"
using namespace std;

/*
    You can pass functions as a pointer argument using the notation
    functionCall(ret_type (*func)(data_type))
*/

int main()
{
    int menuChoice = mainMenu();
    Node *root = new Node();
    Node *suicide = new Node();
    Node *damageNode = new Node();
    constructGameTree(root, suicide, damageNode);

    Player p1;
    Inventory inventory;
    Node *playerPosition = new Node();

    playerPosition = root;
    displayInstructions();
    do
    {
        system("cls");
        char choice;

        p1.displayPlayerStats();
        cout << playerPosition->contextMessage;
        // playerPosition->gameAction(*playerPosition, p1, inventory);

        invalidChoice:
        cout << endl;
        cin >> choice;

        // Exceptional case for deadend nodes to be inserted here
        
        if(playerPosition->solution == 'd')
        {
            playerPosition = suicide;
        }
        else if((choice == 'A' || choice == 'a') && playerPosition->solution == 'n')
            playerPosition = playerPosition->middle;
        else if(choice == 'A' || choice == 'a')
        {
            if(choice == 'A')
                choice = tolower(choice);

            if(int(playerPosition->solution) != 'a')
            {
                if(inventory.penalty())
                {
                    //add a random item as a reward
                    //subtract item used
                    do
                    {
                        system("cls");
                        cout << "You chose the wrong option!\nYou somehow made it past the obstacle\nWhere do you want to go?\nA) Right\nB) Left\n";
                        cout << "Choice: ";
                        cin >> choice;
                    } while (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b');

                    if(choice == 'A' || choice == 'a')
                        playerPosition = playerPosition->middle;
                    
                    else
                        playerPosition = playerPosition->right;           
                }

                else
                {
                    p1.changeHealth();

                    do
                    {
                        system("cls");
                        cout << "You chose the wrong option!\nYou somehow made it past the obstacle\nWhere do you want to go?\nA) Right\nB) Left\n";
                        cout << "Choice: ";
                        cin >> choice;
                    } while (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b');

                    if(choice == 'A' || choice == 'a')
                        playerPosition = playerPosition->middle;
                    
                    else
                        playerPosition = playerPosition->right;
                }
            }

            else
            {
                do
                {
                    system("CLS");
                    cout << "You chose the correct option!\nWhere do you want to go?\nA) Right\nB) Left\n";
                    cout << "Choice: ";
                    cin >> choice;
                } while (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b');

                if(choice == 'A' || choice == 'a')
                    playerPosition = playerPosition->middle;
                
                else
                    playerPosition = playerPosition->right;
            }
        }
    

        else if((choice == 'B' || choice == 'b') && (playerPosition == root))
            playerPosition = welcomeToTheJungle(root, p1, inventory);

        else if((choice == 'B' || choice == 'b') && playerPosition->solution == 'n')
            playerPosition = playerPosition->right;

        else if(choice == 'B' || choice == 'b')
        {
            if(choice == 'B'){
                choice = tolower(choice);
            }

            if(int(playerPosition->solution) != 'b')
            {
                if(inventory.penalty())
                {
                    do
                    {
                        system("cls");
                        cout << "You chose the wrong option!\nYou somehow made it past the obstacle\nWhere do you want to go?\nA) Right\nB) Left\n";
                        cout << "Choice: ";
                        cin >> choice;
                    } while (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b');

                    if(choice == 'A' || choice == 'a')
                        playerPosition = playerPosition->middle;
                    
                    else
                        playerPosition = playerPosition->right;
                }

                else
                {
                    p1.changeHealth();

                    do
                    {
                        system("cls");
                        cout << "You chose the wrong option!\nYou somehow made it past the obstacle\nWhere do you want to go?\nA) Right\nB) Left\n";
                        cout << "Choice: ";
                        cin >> choice;
                    } while (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b');

                    if(choice == 'A' || choice == 'a')
                        playerPosition = playerPosition->middle;
                    
                    else
                        playerPosition = playerPosition->right;
                }
            }

            else
            {
                do
                {
                    system("CLS");
                    cout << "You chose the correct option!\nWhere do you want to go?\nA) Right\nB) Left\n";
                    cout << "Choice: ";
                    cin >> choice;
                } while (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b');

                if(choice == 'A' || choice == 'a')
                    playerPosition = playerPosition->middle;
                
                else
                    playerPosition = playerPosition->right;
            }
        }
        else if(choice == 'C' || choice == 'c')
            playerPosition = playerPosition->left;
        else if(choice == 'S' || choice == 's')
        {
            playerPosition = suicide;
        }
        // else if(choice == 'P' || choice == 'p')
        // {

        // }
        else if(choice == 'I' || choice == 'i')
        {
            system("cls");
            inventory.displayInventory(p1);
            continue;
        }
        else
        {
            cout << "Invalid option, try again";
            goto invalidChoice;
        }

        p1.changeStats();
        if(p1.gameEnded())
        {
            cout << "You died!\nPress an key to return to the main menu\n\n";
            system("pause");
            main();
        }

        if(playerPosition == suicide)
            cout << playerPosition->contextMessage;

    }while(playerPosition != suicide);

    return 0;
}