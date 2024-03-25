#include <iostream>
#include <fstream>
using namespace std;

/*
    You can pass functions as a pointer argument using the notation
    functionCall(ret_type (*func)(data_type))
*/

class Node
{
    public:

    string contextMessage;
    char solution;
    int index;
    Node *left, *right, *middle;

    Node()
    {
        left = NULL;
        right = NULL;
        middle = NULL;
        solution = 'n';
    }

    Node(string context)
    {
        contextMessage = context;
        left = NULL;
        right = NULL;
        middle = NULL;
        solution = 'n';
        this->index = index;
    }

    Node(string context, char danger, int index)
    {
        contextMessage = context;
        left = NULL;
        right = NULL;
        middle = NULL;
        solution = danger;
    }

//     void gameAction(Node playerPosition, Player p1, Inventory inventory)
//     {
//         cout << playerPosition.contextMessage << endl;
//         displayInventory(p1, inventory);

//         if(inventory.checkEmpty())
//         {
//             cout << "Inventory is empty, your only choice is to run!\n";
//             p1.hp--; p1.thirst-=2; p1.hunger--;
//             return;
//         }

//         cout << "What item do you want to use to get out of this?";
//         char choice;
//         cin >> choice;
//     }
};

void constructGameTree(Node*&root, Node*&suicide, Node*&damageNode)
{
    Node *temproot = new Node("You look around and see two paths before you:\nA) Explore a cave\nB) Make your way into the jungle\nC) End your misery\n");
    Node *tempsuicide = new Node("Congrats, you decided to kill yourself and end the game prematurely!");
    Node *tempDamageNode = new Node("You took 1 damage!");
    Node *endGame = new Node("You have reached the end of your journey. You are Free!");

    root = temproot;
    suicide = tempsuicide;
    damageNode = tempDamageNode;

    //root->left = suicide;
    root->middle = new Node("Are you sure you want to head into the cave with the preparation that you have?\nA) Yes\nB) No\n");
    root->middle->middle = new Node("You step into the dark cave and realise that it probably would've been better with a light source. Regardless, you trudge forward and come across two paths. Do you go\nA) Right\nB) Left\n");
    
    //stream path
    root->middle->middle->right = new Node("You jumped down and you land, you see a flowing stream. What do you do?\nA) Use woods to make a bridge\nB) Use stones to make a path\n", 'a',1);
    root->middle->middle->right->right = new Node("As you came in running, you see that the roof of the cave is about to give in, what do you do?\nA) Throw stones at it\nB) Run!\n", 'b',0);
    root->middle->middle->right->middle = new Node("You are welcomed by the hissing sounds by the snakes, what do you do?\nA) Give them your food\nB) Throw stones at it\n", 'b',0);
    root->middle->middle->right->right->right = new Node("After a harsh landing, you almost fell into a deep trench\nYou feel chills down you spine as you look down\n to see the spikes. What do you do?\nA) Use a rope to swing across\nB) Use an axe\n",'a',4);
    root->middle->middle->right->right->middle = new Node("Suddenly you feel very hot, like you are standing in front of a heater\nWhen you go deeper, you find the source of all that heat\nMolten Magma. What do you do?\nA) Use stones to make a path\nB)Use water\n",'b',3);
    root->middle->middle->right->right->middle->middle = new Node("The path is unusually hurdle-free, are you sure do you want to move forward?\nA) Yes\nB) No\n",'d',69);
    root->middle->middle->right->right->middle->middle->right = endGame;
    root->middle->middle->right->right->middle->middle->middle = endGame;
    root->middle->middle->right->middle->middle = new Node("You look as you enter yet another part of the cave to see thousands of eyes staring back at you, what do you do?\nA) Scream!\n B) Use a torch to scare them\n",'b',5);
    root->middle->middle->right->middle->right = new Node("You enter a dark cave, one wrong step and you can be hurt badly, what do you do?\nA) Use a torch\nB) Run!\n", 'a',1);
    root->middle->middle->right->right->right->right = new Node("As you enter the small area, you see a lot of bushes\n you don't know what could be crawling in there, what do you do?\nA) Use the axe to cut down the wood\nB) Use the rope to fly across\n",'a',6);
    root->middle->middle->right->right->right->right->middle = endGame;
    root->middle->middle->right->right->right->right->right = endGame;
    root->middle->middle->right->right->right->middle = new Node("Sadly you have stepped into the dead end cave and there is no way out.\nA) Kill yourself.\nB) Murder yourself.\n ",'d',69);
    root->middle->middle->right->right->middle->right = root->middle->middle->right->right->right->middle;
    root->middle->middle->right->middle->right->middle = new Node("You see a sea of spiders as you walk in deeper into the cave, what do you do?\nA) Use fire\nB) Give them food\n",'a',7);
    root->middle->middle->right->middle->right->middle->right = endGame;
    root->middle->middle->right->middle->right->middle->middle = endGame;
    root->middle->middle->right->middle->right->right = new Node("Growl of a leopard fills the room and it scares the living hell out of you , what do you do?\nA) Scream back at it\nB) Use fire to scare it off\n",'b',7);
    root->middle->middle->right->middle->right->right->middle = endGame;
    root->middle->middle->right->middle->right->right->right = endGame;
    root->middle->middle->right->middle->middle->right = new Node("There are a lot of logs between you and the other side, what do you do?\nA) Move them yourself\nB) Use the axe",'a', 2);
    root->middle->middle->right->middle->middle->right->right = endGame;
    root->middle->middle->right->middle->middle->right->middle = endGame;
    root->middle->middle->right->middle->middle->middle = root->middle->middle->right->right->right->middle;
    root->right = root;
    root->middle->right = root;
    root->right = new Node("Upon venturing into the jungle, you think of how you can begin harvesting resources here\n");

    //dripping water path 
    root->middle->middle->middle=new Node("You have stepped into a cave where the water is dripping from the head above, What will you do?\nA) Use stones to place in the holes.\nB) Use the wood to stop it.\n",'a',0);
    root->middle->middle->middle->right= new Node("A disgusting smell fills the air around you and you start coughing and choking, what do you do?\nA) Make a fire\nB) Run!\n",'b',69);
    root->middle->middle->middle->middle=new Node("A psycopath is standing right in front of you, What you will do?\nA)Kill him with a stone\nB) Use the wood to block his way.\n",'a',0);
    root->middle->middle->middle->right->right=new Node("Bad luck you have dropped yourself in the quick-sand, What you will do?\nA) Use the stones to get out.\nB) Throw some water and use the scientific knowledge\n ",'b',3);
    root->middle->middle->middle->right->middle=new Node("Sadly you have stepped in th cave where no one can stay for the long period its the arctic zone and tempreature right now is -20(c), What you do?\nA) Run as Fast as you can.\nB) Use some fire\n ",'a',69);
    root->middle->middle->middle->right->right->right=new Node("Sadly you have stepped into the dead end cave and there is no way out.\nA) Kill yourself.\nB) Murder yourself.\n ",'d',69);
    root->middle->middle->middle->right->right->middle=new Node("This is the last stage of the cave and then you are free\nThere are unusual flowers everywhere and they are opening their mouth to spit the poison, What you will do?\nA) Set all of them on fire.\nB) Chop them with axe\n ",'a',7);
    root->middle->middle->middle->right->right->middle->right = endGame;
    root->middle->middle->middle->right->right->middle->middle = endGame;
    root->middle->middle->middle->right->middle->right=new Node("This ground is soo slipprey if you dont take decision wisely you will be loosing your life, What you will do?\nA) Use a rope to have a firm grip.\nB) Place the wood on ground\n ",'a',4);
    root->middle->middle->middle->right->middle->right->middle = endGame;
    root->middle->middle->middle->right->middle->right->right = endGame;
    root->middle->middle->middle->right->middle->middle=new Node("Sadly you have stepped into the dead end cave and there is no way out.\nA) Kill yourself.\nB) Murder yourself.\n '",'d',69);
    root->middle->middle->middle->middle->right=new Node("Dont be amazed to see those stalogmites these stalogmites can put your life to an end, what will you do?\nA) Use rope to cross them.\nB) Place the woods to make a path\n",'a',4);
    root->middle->middle->middle->middle->middle=new Node("Sadly you have stepped into the dead end cave and there is no way out.\nA) Kill yourself.\nB) Murder yourself.\n ",'d',69);
    root->middle->middle->middle->middle->right->right=new Node("Answer the granny riddle correctly and then you are set to free from the cave\nHow is Ron 10 years old in 1870, but only 5 years old in 1875?\nA) Ron was born in 1880 B.C.\nB)Ron was born in 1880 C.E.\n",'a',69);
    root->middle->middle->middle->middle->right->right->right = endGame;
    root->middle->middle->middle->middle->right->right->middle = endGame;
    root->middle->middle->middle->middle->right->middle=new Node("Sadly you have stepped into the dead end cave and there is no way out.\nA) Kill yourself.\nB) Murder yourself.\n ",'d',69);

}

//int materials[8]; stone, wood, food, water, Ropes, Torch, Axe, Fire

// void SavePlayerProfile(){
//     fstream f;
//     f.open("player profile.txt");
// }

Node* welcomeToTheJungle(Node *playerPosition, Player p1, Inventory inventory)
{
    cout << "You enter the jungle to scavenge" << endl << endl;
    system("pause");
    system("cls");

    int iteration = 0;
    char ch;
    char choice;
    int result;
    int danger = 0;
    bool breakLoopFlag1 = false;

    do
    {
        inventory.displayInventory(p1);
        if(iteration > 5)
        {
    
            cout << "\nYou notice it's getting darker.\n";
            cout << "The likelihood of getting attacked increases with every passing action\n";
            system("pause");
            
            srand(time(NULL));
            int probabilityOfAttack = rand() % 4;
            if (danger == 25 && probabilityOfAttack == 0)
            {
                system("cls");
                cout << "The dark of night obscures your vision, causing you to trip and get hurt!\n\n";
                p1.hp--;
                system("pause");
            }

            else if (danger == 50 && (probabilityOfAttack == 0 || probabilityOfAttack == 1))
            {
                system("cls");
                cout << "You were attacked by bats!\n\n";
                p1.hp--;
                system("pause");
            }

            else if (danger == 75 && (probabilityOfAttack >= 0 && probabilityOfAttack < 3))
            {
                system("cls");
                cout << "You stepped into a pool of acid created by a toxic plant nearby!\n\n";
                p1.hp--;
                system("pause");
            }

            else if (danger == 100)
            {
                system("cls");
                cout << "You were attacked by a swarm of bees and you had to run to safety!\n\n";
                p1.hp--; p1.thirst;
                system("pause");
            }
        }

        do
                {
                    system("cls");
                    cout << "Available resources:\n--------------------\n";
                    cout << "1. Food\n";
                    cout << "2. Wood\n";
                    cout << "3. Stone\n";
                    cout << "4. Water\n";
                    cout << "5. Ropes\n";
                    cout << "6. Torches\n";
                    cout << "7. Axes\n";
                    cout << "8. Fire\n";
                    cout << "9. Head back to the shore\n";
                    cout << "What do you want to scavenge for: ";
                    cin >> ch;
                }while(ch < '1' || ch > '9');

                srand(time(NULL));

                switch(ch)
                {
                    case('9'):
                        system("cls");
                        cout << "You decide to return to the shore with the gathered resources in hand\n\n";
                        system("pause");
                        breakLoopFlag1 = true;
                        system("cls");
                        break;
                    case('8'):
                        system("cls");
                        result = rand()%2;
                        cout << "You decided to search for fire\n";

                        if(result)
                        {
                            cout << "You searched and found an empty campsite!\n";
                            cout << "Number of fires has increased by 1!";
                            inventory.materials[7] += result;
                            system("pause");
                            system("cls");
                            break;
                        }

                        else
                        {
                            cout << "You searched but found no campsites for fire!\n";
                            system("pause");
                            system("cls");
                            break;
                        }
                    case('7'):
                        system("cls");
                        result = rand()%2;
                        cout << "You decided to search for axes\n";

                        if(result)
                        {
                            cout << "You searched and found an axe stuck in a tree!\n";
                            cout << "Number of axes has increased by 1!";
                            inventory.materials[6] += result;
                            system("pause");
                            system("cls");
                            break;
                        }

                        else
                        {
                            cout << "You searched but found no axes\n";
                            system("pause");
                            system("cls");
                            break;
                        }
                    case('6'):
                        system("cls");
                        result = rand()%2;
                        cout << "You decided to search for torches\n";

                        if(result)
                        {
                            cout << "You searched and found a torch!\n";
                            cout << "Your torches has increased by 1\n";
                            inventory.materials[5] += result;
                            system("pause");
                            system("cls");
                            break;
                        }

                        else
                        {
                            cout << "You searched but found no torches\n";
                            system("pause");
                            system("cls");
                            break;
                        }
                    case('5'):
                        system("cls");
                        result = rand()%2;
                        cout << "You decided to search for ropes\n";

                        if(result)
                        {
                            cout << "You searched and found a rope hanging from a branch!\n";
                            cout << "Number of ropes has increased by 1\n";
                            inventory.materials[4] += result;
                            system("pause");
                            system("cls");
                            break;
                        }

                        else
                        {
                            cout << "You searched but found no water\n";
                            system("pause");
                            system("cls");
                            break;
        }
        case ('4'):
            system("cls");
            result = rand() % 2;
            cout << "You decided to search for water\n";

            if (result)
            {
                cout << "You searched and found a stream\n";
                cout << "Your water has increased by 2\n";
                inventory.materials[3] += (result + 1);
                system("pause");
                system("cls");
                break;
            }

            else
            {
                cout << "You searched but found no water\n";
                system("pause");
                system("cls");
                break;
            }

        case ('3'):
            system("cls");
            result = rand() % 3 + 1;
            cout << "You found " << result << " stones while scavenging\nThey have been added to your inventory\n\n";
            inventory.materials[0] += result;
            system("pause");
            system("cls");
            break;

        case ('2'):
            system("cls");
            result = rand() % 3 + 1;
            cout << "You found some loose branches\nYou got " << result << " wood out of them\nThey have been added to your inventory\n\n";
            inventory.materials[1] += result;
            system("pause");
            system("cls");
            break;

        case ('1'):
            system("cls");
            result = rand() % 4;
            if (result)
            {
                cout << "You found " << result << " food items while scavenging\nThey have been added to your inventory\n\n";
                inventory.materials[2] += result;
                system("pause");
                system("cls");
                break;
            }

            else
            {
                cout << "In your search for food, you found a rabbit!\nYou tried to catch it but it got away!\n\n";
                system("pause");
                system("cls");
                break;
            }
        }
        if (iteration > 4 && danger < 100)
            danger += 25; // Danger initially set to 0
        iteration++;
    }while(breakLoopFlag1 == false);

    return playerPosition;
}