#include <iostream>
using namespace std;

class Player
{
    public:

    int hp, hunger, thirst;

    void displayPlayerStats()
    {
        cout << "Health: " << hp << "\nHunger: " << hunger << "\nThirst: " << thirst << endl << endl;
    }

    void changeStats()
    {
        if(thirst > 0)
            thirst--; 
        if(hunger > 0)
            hunger--;
        if(thirst == 0 || hunger == 0)
            hp--;
    }

    bool gameEnded()
    {
        if(hp == 0)
            return true;
        return false;
    }

    void changeHealth()
    {
        hp--;
    }

    Player()
    {
        hp = 3;
        hunger = 10;
        thirst = 15;
    }
};

class Inventory
{
    public:

    int materials[8]; // stone, wood, food, water, Ropes, Torch, Axe, Fire

    void displayInventory(Player p1)
    {
        p1.displayPlayerStats();

        if(!checkEmpty())
        {
            cout << "Inventory is empty!\n\n";
            system("pause");
            return;
        }

        else
        {
            cout << "\tInventory\nStone: " << materials[0] << endl;

            cout << "\nWood: " << materials[1] << endl;

            cout << "\nFood: " << materials[2] << endl;

            cout << "\nWater: " << materials[3]<< endl;

            cout << "\nRopes: " << materials[4] << endl;

            cout << "\nTorch: " << materials[5] << endl;

            cout << "\nAxe: " << materials[6]<< endl;

            cout << "\nFire: " << materials[7]<< endl;

            system("pause");
            system("cls");

            inventoryAction(p1);
        }
    }

    void inventoryAction(Player p1)
    {
        char choice;

        cout << "\n<A> Drink water\n<B> Eat food\n<C> Drop Item\nAny other key to exit\nEnter your choice: ";
        cin >> choice;
        if(choice == 'a' || choice == 'A')
        {
            if(materials[3] == 0)
                cout << "Out of water!\n";
            else
            {
                materials[3]--;
                p1.thirst += 2;
            }
        }
        else if(choice == 'b' || choice == 'B')
        {
            if(materials[2] == 0)
                cout << "Out of food!\n";
            else
            {
                materials[2]--;
                p1.hunger += 2;
            }
        }
        else if(choice == 'c' || choice == 'C')
        {
            char count = 'A';
            cout << "Which item do you wish to drop?";

            if(materials[0] != 0)
                cout << "<0> Stone: " << materials[0] << endl;
            if(materials[1] != 0)
                cout << "<1> Wood: " << materials[1] << endl;
            if(materials[2] != 0)
                cout << "<2> Food: " << materials[2] << endl;
            if(materials[3] != 0)
                cout << "<3> Water: " << materials[3] << endl;
            if(materials[4] != 0)
                cout << "<4> Ropes: " << materials[4] << endl;
            if(materials[5] != 0)
                cout << "<5> Torch: " << materials[5] << endl;
            if(materials[6] != 0)
                cout << "<6> Axe: " << materials[6] << endl;
            if(materials[7] != 0)
                cout << "<7> Fire: " << materials[7] << endl;

            cin >> choice;
            switch(choice)
            {
                case('0'):
                    if(materials[0] != 0)
                    {
                        materials[0]--;
                        break;
                    }
                case('1'):
                    if(materials[1] != 0)
                    {
                        materials[1]--;
                        break;
                    }
                case('2'):
                    if(materials[2] != 0)
                    {
                        materials[2]--;
                        break;
                    }
                case('3'):
                    if(materials[3] != 0)
                    {
                        materials[3]--;
                        break;
                    }
                case('4'):
                    if(materials[4] != 0)
                    {
                        materials[4]--;
                        break;
                    }               
                case('5'):
                    if(materials[5] != 0)
                    {
                        materials[5]--;
                        break;
                    }
                case('6'):
                    if(materials[6] != 0)
                    {
                        materials[6]--;
                        break;
                    }
                case('7'):
                    if(materials[7] != 0)
                    {
                        materials[7]--;
                        break;
                    }
            }
        }
    }

    bool penalty()
    {
        if(checkEmpty())
        {
            system("CLS");
            srand(time(NULL));

            int pen = rand()%4;

            cout <<"You still went through but you lost " << pen << " items from each of your inventory!";
            reduceInventory(pen);
            return true;
        }

        return false;
    }

    void reduceInventory(int n)
    {
        int index = rand()%8;
        
        if(materials[index] != 0)
            materials[index] -= n;
    }

    bool checkEmpty()
    {
        if(materials[0] == 0 && materials[1] == 0 && materials[2] == 0 && materials[3] == 0 && materials[4] == 0&& materials[5] == 0 && materials[6] == 0 && materials[7] == 0)
            return false;
        return true;
    }

    Inventory()
    {
        for(int i=0; i<8; i++)
            materials[i] = 0;
    }
};