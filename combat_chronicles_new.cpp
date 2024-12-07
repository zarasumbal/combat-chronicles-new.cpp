#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>
using namespace std;

struct Player
{
    string name;
    string playerClass;
    string inventory[5];
    string weapon;
    int health;
    int level;
    int levelMax;
    int experiencePoints;
    int attack;
};

struct Enemy
{
    string enemyName;
    int enemyHealth;
    int difficultyLevel;
};

string lowerString(string str) // This function converts Uppercase Letters into Lowercase Letters
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32; // Adding 32 in string[i] will change ASCII code and convert it into lowercase letters
        }
    }
    return str;
}

string upperString(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
    return str;
}

bool validateAlphaString(string name) //User defined function declaration
{
    for (const char c : name)
    {
        if (!isalpha(c) && !isspace(c))
        return false;
    }

    return true;
}

string getValidName(string name)
{
    while (!validateAlphaString(name))
    {
        cout << "Wrong Input ! please USE only alphabets for name" << endl;
        cout << "Enter Name: ";
        getline(cin, name);
    }
    return name;
}

string input(string x)
{
    while(true)
    {
        if ( cin.fail())
        {
            cin.clear();
        }
        else if ( !cin.fail())
        {
            return x;
        }
    }
}
 
void Quit()
{
    cout << setw(50) << " ~ GOODBYE! ~ " << endl;
}

void initializePlayer(Player& player)
{
    cout << "\n\n" << setw(60) << "CREATING PLAYER" << endl << endl << endl;
    cout << "Player Name: ";

    while(true)
    {
        getline(cin, player.name);
        player.name = input(player.name);
        player.name = getValidName(player.name);
        player.name = upperString(player.name);

        if (player.name.empty() && !validateAlphaString(player.name))
        {
            cout << "Invalid Input ! " << endl;
        }
        else if(player.name.length() < 3 || player.name.length() > 8)
        {
            cout << "Length must be between 3 to 8 characters." << endl;
        }
        else
        {
            player.name;
            break;
        }
        cout << "Enter name: ";
    }

    while (true)
    {
        cout << endl << setw(55) << "CLASSES";
        cout << "\n\n* SKY HUNTER\n\n* EMBER KNIGHT\n\n* RUNE SAGE " << endl;
        cout << "\n\n* SKY HUNTER : Aerial Precision\n\n* EMBER KNIGHT : Fiery Warrior\n\n* RUNE SAGE : Mystical Scholar" << endl;
        cout << endl;
        cout << "\nChoose your class: ";


        getline(cin, player.playerClass);
        player.playerClass = input(player.playerClass);
        player.playerClass = upperString(player.playerClass);
        if (player.playerClass == "SKY HUNTER" || player.playerClass == "EMBER KNIGHT" || player.playerClass == "RUNE SAGE")
        {
            player.playerClass;
            break;
        }
        else
        {
            cout << "\nThat class does not belong in this realm.." << endl;
        }
    }
    player.experiencePoints = 0;
        player.level = 1;
        player.health = 100;
        player.levelMax = 5;
}

void EnemyInfo(Player& player, Enemy& enemy)
{
    cout << "Press ( 1 to 9 ) for body shoot" << endl;
    cout << "Press ( 0 ) for headshot" << endl;

    if (player.level == 1)
    {
        cout << setw(50) << " === LEVEL 1 === " << endl << endl;
        enemy.enemyName = "TWILIGHT SERPENT";
        enemy.enemyHealth = 50;
        enemy.difficultyLevel = 1;
        cout << "Foe Identified: " << enemy.enemyName << endl;
        cout << "Vitality: " << enemy.enemyHealth << endl;
        cout << "Difficulty Rank: " << enemy.difficultyLevel << endl;
        cout << endl << endl;
        Sleep(2000);
        cout << endl << endl;
        cout << "Level 1: The Arena Awaits Your Courage!" << endl;
        cout << "The TWILIGHT SERPENT slithers in the murky depths, its venomous strike a silent threat in the dark. " << endl; 
        cout << "Face it now to prove your strength in the first trial of your journey..." << endl << endl; 
    }
    else if (player.level == 2)
    {
        cout << setw(50) << " === LEVEL 2 === " << endl;
        enemy.enemyName = "THUNDER BEAST";
        enemy.enemyHealth = 100;
        enemy.difficultyLevel = 2;
        cout << "Foe Identified: " << enemy.enemyName << endl;
        cout << "Vitality:" << enemy.enemyHealth << endl;
        cout << "Difficulty Rank: " << enemy.difficultyLevel << endl;
        Sleep(2000);
        cout << endl << endl;
        cout << "Level 2: Get Ready To Rumble!" << endl;
        cout << "A creature born from the strorm, the THUNDER BEAST roars with the fury of the sky itself. " << endl; 
        cout << "Its lightning-infused strikes will test your resilience as you venture deeper into the unknown..." << endl << endl; 

    }
    else if (player.level == 3)
    {
        cout << setw(50) << " === LEVEL 3 === " << endl << endl;
        enemy.enemyName = "BLOODVEIL SORCERER";
        enemy.enemyHealth = 130;
        enemy.difficultyLevel = 3;
        cout << "Foe Identified: " << enemy.enemyName << endl;
        cout << "Vitality: " << enemy.enemyHealth << endl;
        cout << "Difficulty Level: " << enemy.difficultyLevel << endl;
        cout << endl << endl;
        Sleep(2000);
        cout << "Level 3: Seize Glory in the Arena!" << endl;
        cout << "Once a revered scholar, the BLOODVEIL SORCERER now commands dark, forbidden magic." << endl;
        cout << "Defeat him and you may unlock the secrets of arcane powers he has embraced..." << endl;

    }
    else if (player.level == 4)
    {
        cout << setw(50) << " === LEVEL 4 === " << endl << endl;
        enemy.enemyName = "VOID PHANTOM";
        enemy.enemyHealth = 150;
        enemy.difficultyLevel = 4;
        cout << "Foe Identified: " << enemy.enemyName << endl;
        cout << "Vitality: " << enemy.enemyHealth << endl;
        cout << "Difficulty Rank: " << enemy.difficultyLevel << endl;
        cout << endl << endl;
        Sleep(2000);
        cout << "Level 4: Enter The Realm of Eternal Combat!" << endl;
        cout << "Emerging from the rift between worlds, the VOID PHANTOM is a wraith of forgotten souls." << endl;
        cout << "Only the bravest dare to face it, for its power comes from the very fabric of reality itself..." << endl;
        cout << endl << endl;
    
    }
    else if (player.level = player.levelMax)
    {
        cout << setw(50) << " === FINALE === " << endl << endl;
        enemy.enemyName = "SHADOWSTRIKE RAIDER";
        enemy.enemyHealth = 200;
        enemy.difficultyLevel = 5;
        cout << "Foe Identified: " << enemy.enemyName << endl;
        cout << "Vitality: " << enemy.enemyHealth << endl;
        cout << "Difficulty Rank: " << enemy.difficultyLevel << endl;
        cout << endl << endl;
        Sleep(2000);
        cout << "The Grand Showdown" << endl;
        cout << "A master of stealth and assassination, the SHADOWSTRIKE RAIDER is the final obstacle in your path." << endl;
        cout << "Survive its ambush, and you will prove yourself worthy of becoming a legend..." << endl;
    }

}

void displayPlayerInfo(Player& player)
{
    cout << setw(65) << "Character Information\n\n";
    cout << "Name: " << player.name << endl;
    cout << "Class: " << player.playerClass << endl;
    cout << "Health: " << player.health << endl;
    cout << "Experience Points: " << player.experiencePoints << endl;
    if (player.level > player.levelMax)
    {
        player.level = 5;
    }
    cout << "Level: " << player.level << "\n\n";
}

string Weapon(Player& player)
{
    if (player.level == 1)
    {
        player.weapon = "Crimson Petal Lance";
        player.inventory[0] = player.weapon;
        return player.weapon;
    }
    if (player.level == 2)
    {
        player.weapon = "Light Wind Blade";
        player.inventory[1] = player.weapon;
        return player.weapon;
    }
    if (player.level == 3)
    {
        player.weapon = "Thundersong Bow";
        player.inventory[2] = player.weapon;
        return player.weapon;
    }
    if (player.level == 4)
    {
        player.weapon = "Flame Sword";
        player.inventory[3] =player.weapon;
        return player.weapon;
    }
    if (player.level == 5)
    {
        player.weapon = "Phoenix Blade";
        player.inventory[4] = player.weapon;
        return player.weapon;
    }
}
 
void inventory(Player& player)
{
    player.inventory[0] = "Crimson Petal Lance";
    player.inventory[1] = "Light Wind Blade";
    player.inventory[2] = "Thundersong Bow";
    player.inventory[3] = "Flame Sword";
    player.inventory[4] = "Phoenix Blade";
    cout << "1. Crimson Petal Lance" << setw(40) << "at Level : 1" << endl;
    cout << "2. Light Wind Blade" << setw(40) << "   at Level : 2" << endl;
    cout << "3. Thundersong Bow" << setw(40) << "    at Level : 3" << endl;
    cout << "4. Flame Sword" << setw(40) << "        at Level : 4" << endl;
    cout << "5. Phoenix Blade" << setw(40) << "      at Level : 5" << endl;
}

int levelUp(Player& player)
{
    if (player.experiencePoints >= 100)
    {
        player.level++;
        if (player.level == 5)
        {
            player.level = player.levelMax;
        }
        player.health = 100; //Resets health on level up
        player.experiencePoints = 0; // Reset experience points
        if (player.level > player.levelMax)
        {
            Sleep(2000);
            cout << "The SHADOWSTRIKE RAIDER, the ultimate test of skill and perseverance, has been defeated. But with victory comes the realization: the trials were all leading to this moment. The adventurer, now empowered by the wisdom and strength gained, must confront the ancient evils in the stirring in the shadows, alone, with the fate of the realm resting in their hands.  " << endl << endl;
        }
        else 
        {
            cout << "\nWelldone, brave adventurer ! You have ascended to Level : " << player.level << "The realm trembles at your rise !" << endl;
            return player.level;
        }
    }
}

int PlayerAttack(Player& player)
{
    string ch;
    cin >> ch;
    ch = input(ch);
    ch = lowerString(ch);
    while(true)
    {
        if (!cin.eof() && !cin.fail())
        {
            if (ch == "1")
            {
                player.attack = 3;
                return player.attack;
                true;
            }
            else if (ch == "2")
            {
                player.attack = 6;
                return player.attack;
                true;
            }
            else if (ch == "3")
            {
                player.attack = 9;
                return player.attack;
                true;
            }
            else if (ch == "4")
            {
                player.attack = 12;
                return player.attack;
                true;
            }
            else if (ch == "5")
            {
                player.attack = 15;
                return player.attack;
                true;
            }
            else if (ch == "6")
            {
                player.attack = 18;
                return player.attack;
                true;
            }
            else if (ch == "7")
            {
                player.attack = 21;
                return player.attack;
                true;
            }
            else if (ch == "8")
            {
                player.attack = 24;
                return player.attack;
                true;
            }
            else if (ch == "9")
            {
                player.attack = 27; 
            }
            else if (ch == "0")
            {
                player.attack = 50;
                return player.attack;
                true;
            }
            else 
            {
                player.attack = 0;
                break;
            }
        }
        else if (cin.eof() && cin.fail())
        {
            cin.clear();
            player.attack = 0;
            break;
        }
    };
}

void battle(Player& player, Enemy& enemy)
{
    cout << "\nPlayer Weapon: " << Weapon(player) << endl << endl;
    cout << setw(40) << player.name << setw(20) << "V/S" << setw(20) << enemy.enemyName << endl;
    while (true)
    {
        int enemyAttack = rand() % 30 + 5; //Simulates enemy attack
        if (player.health > 0)
        {
            PlayerAttack(player);
            cout << "You attack the " << enemy.enemyName << " for " << "'" << player.attack << "'" << " damage." << endl;
            enemy.enemyHealth = enemy.enemyHealth - player.attack;
            if (enemy.enemyHealth > 0)
            {
                cout << enemy.enemyName << " attacks you for " << enemyAttack << " damage. " << endl;
                player.health = player.health - enemyAttack;
                if (player.health <= 0)
                {
                    player.health = 0;
                    cout << "\nYour Health: " << player.health << setw(25) << enemy.enemyName << " Health: " << enemy.enemyHealth << endl;
                    while (true)
                    {
                        cout << "You were defeated.\n\n";
                    up:
                        cout << "Do you want to play again (Y / N)...";
                        string choice;
                        choice = input(choice);
                        choice = lowerString(choice);
                        cin >> choice;
                        if (choice == "y" || choice == "Y")
                        {
                            system("cls");
                            cout << setw(50) << "LEVEL " << player.level << endl;
                            battle(player, enemy);
                        }
                        else if (choice == "n" || choice == "N")
                        {
                            cout << "Do you want to quit the game (Y / N)...";
                        jump:
                            cin >> choice;
                            choice = input(choice);
                            choice = lowerString(choice);
                            if (choice == "Y" || choice == "y")
                            {
                                system("cls");
                                Quit();
                            }
                            else if (choice == "n" || choice == "N")
                            {
                                cout << endl;
                                goto up;
                            }
                            else
                            {
                                cout << "Invalid Input ! ";
                                goto jump;
                            }
                        }
                    };
                }

                else 
                {
                    cout << "\nYour Health: " << player.health << setw(25) << enemy.enemyName << " Health: " << enemy.enemyHealth << endl;
                    true;
                }
                true;
            }
            else if (enemy.enemyHealth <= 0)
            {
                enemy.enemyHealth = 0;
                cout << "\nYour Health: " << player.health << setw(25) << enemy.enemyName << " Health: " << enemy.enemyHealth << endl;
                cout << "You defeated: " << enemy.enemyName << "You gained 100 experience points. " << endl;
                player.experiencePoints = player.experiencePoints + 100;
                levelUp(player);

                break;
            }
        }
        else if (player.health <= 0)
        {
            player.health = 100;
            true;
        }
    }
}

void gameLoop(Player& player, Enemy& enemy)
{
    levelUp(player);
    EnemyInfo(player, enemy);
    battle(player, enemy);
}
void Controls()
{
    cout << "Channel your fury: press 1 to knock 3 points off their health!" << endl;
    cout << "Channel your fury: press 2 to knock 6 points off their health!" << endl;
    cout << "Channel your fury: press 3 to knock 9 points off their health!" << endl;
    cout << "Channel your fury: press 4 to knock 12 points off their health!" << endl;
    cout << "Channel your fury: press 5 to knock 15 points off their health!" << endl;
    cout << "Channel your fury: press 6 to knock 18 points off their health!" << endl;
    cout << "Channel your fury: press 7 to knock 21 points off their health!" << endl;
    cout << "Channel your fury: press 8 to knock 24 points off their health!" << endl;
    cout << "Channel your fury: press 9 to knock 27 points off their health!" << endl;
    cout << "Channel your fury: press 10 to knock 30 points off their health!" << endl;
}

void StoryLine(Player& player)
{
    cout << endl << endl << setw(70) << "Combat Chronicles: The Battle Begins" << endl << endl << endl;
    cout << "In the heat of battle, heroes are made, and legends are written." << endl;
    cout << "Welcome to the Combat Chronicles, where the story of your might and courage unfolds..." << endl << endl;
    
    Sleep(3000);

    cout << "Level 1 - Echoes of the Forgotten Path:" << endl;
    cout << "The TWILIGHT SERPENT slithers in the murky depths, its venomous strike a silent threat in the dark." << endl;
    cout << "Face it now to prove your strength in the first trial of your journey..." << endl << endl;

    Sleep(3000);

    cout << "Level 2 - Storms of the Horizon:" << endl;
    cout << "A creature born from thr storm, the THUNDER BEAST roars with the fury of the sky itself." << endl;
    cout << "Its lightning-infused strikes will test your resilience as you venture deeper into the unknown..." << endl << endl;

    Sleep(3000);

    cout << "Level 3 - Veil of Shadows:" << endl;
    cout << "Once a revered scholar, the BLOODVEIL SORCERER now commands dark, forbidden magic." << endl;
    cout << "Defeat him and you may unlock the secrets of the arcane powers he has embraced..." << endl << endl;

    Sleep(3000);

    cout << "Level 4 - Beyond the Rift:" << endl;
    cout << "Emerging from the rift between the worlds, the VOID PHANTOM is a wraith of forgotten souls." << endl;
    cout << "Only the bravest dare face it, for its power comes from the very fabric of reality itself..." <<endl << endl;

    Sleep(3000);

    cout << "Final Showdown - The Edge of Fate:" << endl;
    cout << "A master of stealth and assassination, the SHADOWSTRIKE RAIDER is the final obstacle of your path." << endl;
    cout << "Survive its ambush, and you will prove yourself worthy of becoming a legend..." << endl << endl;

    Sleep(3000);

    cout << "Embark on this legendary journey, rewrite the Chronicles of Combat, and emerge as the hero of Valor!" << endl << endl;
}

void End(Player& player, Enemy& enemy)
{
    displayPlayerInfo(player);
    cout << endl;
    cout << player.name << "has triumphed over: " << endl << endl;
    cout << "*TWILIGHT SERPENT\n*THUNDER BEAST\n*BLOODVEIL SORCERER\n*VOID PHANTOM\n*SHADOWSTRIKE RAIDER" << endl;

}

int main()
{
    Player player;
    Enemy enemy;
    string ch;
    system("cls");
    cout << "\n\n\n\n";
    cout << setw(65) << "~ COMBAT CHRONICLES ~\n" << endl << endl;
    cout << "1. Begin the Tale." << endl << endl;
    cout << "2. Enter the Realm." << endl << endl;
    cout << "3. Browse your Treasures." << endl << endl;
    cout << "4. Tweak the Magic." << endl << endl;
    cout << "5. Escape the Journey." << endl << endl;

jump:
    cin >> ch;
    ch = input(ch);
    ch = lowerString(ch);
    while (true)
    {
        if (ch == "1")
        {
            system("cls");
            StoryLine(player);
            string choice;
            do
            {
                cout << "Press y to continue your journey....";
                cin >> choice;
                choice = input(choice);
                choice = lowerString(choice);
            } while (choice != "y");

            main;
            break;
            
        }
        else if (ch == "2")
        {
            system("cls");
            cin.ignore();
            initializePlayer(player);
            cout << endl << endl;
            displayPlayerInfo(player);
        
        play:
            cout << "Ready to embark on your quest? (Y/N): ";
            string choice;
            cin >> choice;
            choice = input(choice);
            choice = lowerString(choice);
            while(true)
            {
                if (choice == "y")
                {
                    system("cls");
                    string c;

                    do
                    {
                        gameLoop(player, enemy);

                    up:
                        if (player.level > player.levelMax)
                        {
                            string choice;

                            do
                            {
                            again:
                               cout << "\nPress y to continue... ";
                               cin >> choice;
                               choice = input(choice);
                               choice = lowerString(choice);
                               if (choice == "y")
                               {
                                   system("cls");
                                   End(player, enemy);
                                   do
                                   { 
                                    y:
                                       cout << "Press y to continue... ";
                                       string x;
                                       cin >> x;
                                       x = input(x);
                                       x = lowerString(x);
                                       if (x == "y")
                                       {
                                          system("cls");
                                          main();
                                       }
                                       else if (x != "y")
                                       {
                                          goto y;
                                       }
                                        
                                        
                                    } while (c != "y");

                                }   
                                else if (choice != "y")
                                {
                                    goto again;
                                } 
                            } while (c != "y");

                        }
                        else if (player.level <= player.levelMax)
                        {
                            cout << "Ready for next level (Y/N): ";
                            cin >> c;
                            c = input(c);
                            c = lowerString(c);
                            if (c == "n" || c == "N")
                            {
                                cout << "Do you want to quit... (y/n): ";
                            choice: 
                                string ch;
                                cin >> ch;
                                ch = input(ch);
                                ch = lowerString(ch);
                                if (ch == "Y" || ch == "y")
                                {
                                    system("cls");
                                    cout << displayPlayerInfo << endl;
                                    return 0;
                                }
                                else if (ch == "n" || ch == "N")
                                {
                                    goto up;
                                }
                                else
                                {
                                    cout << "Invalid Input !" << endl;
                                    goto choice;
                                }
                            }
                            else if  (c == "y" || c == "Y")
                            {
                                system("cls");
                                if (player.level > player.levelMax)
                                {
                                    string choice;
                                    do
                                    {
                                        cout << "\nPress y to continue....";
                                        cin >> choice;
                                        choice = input(choice);
                                        choice = lowerString(choice);
                                        if (choice == "y")
                                        {
                                            End(player, enemy);
                                        }
                                    } while (choice == "y");
                                    main();
                                    break;
                                    
                                }
                            
                                
                            }
                            else
                            {
                                cout << "Invalid Input ! " << endl;
                                goto up;
                            }
                        }        
    
                    } while (c == "y" || c == "Y");
                    true;

                }
                else if (choice == "n" || choice == "N")
                {
                    string choice;
                    cout << "\nDo you want to quit the game (Y/N): ";
                    do 
                    {
                    ch:
                        cin >> choice;
                        choice = input(choice);
                        choice = lowerString(choice);
                        if (choice == "y" || choice == "Y")
                        {
                            Quit();
                            return 0;
                        }
                        else if (choice == "n" || choice == "N")
                        {
                            cout << "Inavlid Input ! " << endl;
                            goto ch;
                        }

                    
                    } while (choice == "Y" || choice == "y" || choice == "N" || choice == "n");
                    true;
    
                    
                }
                else
                {
                    cout << "Invalid Input ! " << endl;
                    goto play;
                }

            };
            break;

        }
        else if (ch == "3")
        {
            system("cls");
            inventory(player);
            string choice;
            do
            {
                cout << "Press y to continue...";
                cin >> choice;
                choice = input(choice);
                choice = lowerString(choice);

            } while (choice != "y");
            true;
            main();
            break;
            
        }
        else if (ch == "4")
        {
            system("cls");
            Controls();
            string choice;
            do
            {
                cout << "Press y to continue...";
                cin >> choice;
                choice = input(choice);
                choice = lowerString(choice);

            } while (choice != "y");
            true;
            main();
            break;
            
            
        }
        else if (ch == "5")
        {
            system("cls");
            cout << "\n\n\n\n\n\n";
            Quit();
            break;

        }
        else
        {
            cout << "Invalid Input ! " << endl;
            goto jump;
        }

    };

}