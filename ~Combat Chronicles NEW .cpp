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
        cout << "Wrong Input! please USE only alphabets for name" << endl;
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
    cout << setw(50) << "~ GOODBYE! ~" << endl;
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
            cout << "Invalid Input." << endl;
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
        cout << "\n\n* WARRIOR\n\n* MAGE\n\n* ROGUE" << endl;
        cout << "\nChoose your class: ";

        getline(cin, player.playerClass);
        player.playerClass = input(player.playerClass);
        player.playerClass = upperString(player.playerClass);
        if (player.playerClass == "WARRIOR" || player.playerClass == "MAGE" || player.playerClass == "ROGUE")
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
        cout << setw(50) << "=== LEVEL 1 ===" << endl << endl;
        enemy.enemyName = "DOCTOR";
        enemy.enemyHealth = 50;
        enemy.difficultyLevel = 1;
        cout << "Foe Identified: " << enemy.enemyName << endl;
        cout << "Vitality: " << enemy.enemyHealth << endl;
        cout << "Difficulty Rank: " << enemy.difficultyLevel << endl;
        cout << endl << endl;
        Sleep(2000)
        cout << endl << endl;
        cout << "Level 1: The Arena Awaits Your Courage!"
        cout << "Doctor story " << endl; //New enemy name and new story
        cout << "Continuing the story" << endl << endl; //Continuing the story
    }
    else if (player.level == 2)
    {
        cout << setw(50) << "=== LEVEL 2 ===" << endl;
        enemy.enemyName = "SARA";
        enemy.enemyHealth = 100;
        enemy.difficultyLevel = 2;
        cout << "Foe Identified: " << enemy.enemyName << endl;
        cout << "Vitality:" << enemy.enemyHealth << endl;
        cout << "Difficulty Rank: " << enemy.difficultyLevel << endl;
        Sleep(2000);
        cout << endl << endl;
        cout << "Level 2: Get Ready To Rumble!" << endl;
        cout << "SARA story" << endl; //New enemy name and new story
        cout << "continuing the story" << endl << endl; //Continuing the story

    }
    else if (player.level == 3)
    {
        cout << setw(50) << "=== LEVEL 3 ===" << endl << endl;
        enemy.enemyName = "ANNA";
        enemy.enemyHealth = 130;
        enemy.difficultyLevel = 3;
        cout << "Foe Identified: " << enemy.enemyName << endl;
        cout << "Vitality: " << enemy.enemyHealth << endl;
        cout << "Difficulty Level: " << enemy.difficultyLevel << endl;
        cout << endl << endl;
        Sleep(2000)
        cout << "Level 3: Seize Glory in the Arena!" << endl;
        cout << "ANNA story" << endl;//New enemy name and new story
        cout << "continuing the story" << endl;//Continuing the story

    }
    else if (player.level == 4)
    {
        cout << setw(50) << "=== LEVEL 4 ===" << endl << endl;
        enemy.enemyName = "CARLO";
        enemy.enemyHealth = 150;
        enemy.difficultyLevel = 4;
        cout << "Foe Identified: " << enemy.enemyName << endl;
        cout << "Vitality: " << enemy.enemyHealth << endl;
        cout << "Difficulty Rank: " << enemy.difficultyLevel << endl;
        cout << endl << endl;
        Sleep(2000)
        cout << "Level 4: Enter The Realm of Eternal Combat!" << endl;
        cout << "CARLO story" << endl;//New enemy name and new story
        cout << "continuing the story" << endl;//Continuing the story
        cout << endl << endl;
    
    }
    else if (player.level = player.levelMax)
    {
        cout << setw(50) << "=== FINALE ===" << endl << endl;
        enemy.enemyName = "ANDY";
        enemy.enemyHealth = 200;
        enemy.difficultyLevel = 5;
        cout << "Foe Identified: " << enemy.enemyName << endl;
        cout << "Vitality: " << enemy.enemyHealth << endl;
        cout << "Difficulty Rank: " << enemy.difficultyLevel << endl;
        cout << endl << endl;
        Sleep(2000)
        cout << "The Grand Showdown" << endl;
        cout << "ANDY story" << endl;//New enemy name and new story
        cout << "continuing the story" << endl;//Continuing the story
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
    if (player.weapon == 4)
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
            Sleep(2000)
            cout << "After Andy's defeat, the truth emerges: the trials were humanity's last stand against an imminent alien invasion. Each character's role in shaping the simulation becomes clear. With Andy's fall, a new chapter begins. United by purpose, they harness the simulation's power, preparing to confront the looming threat. Their mission: defend humanity, using the simulation's depths to ensure unity against the impending extraterrestrial onslaught." << endl << endl;
        }
        else 
        {
            cout << "\nCongratulations! You've leveled up to Level " << player.level << "!" << endl;
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
                player.attack = 12
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
                                system("cls")
                                Quit();
                            }
                            else if (choice == "n" || choice == "N")
                            {
                                cout << endl;
                                goto up;
                            }
                            else
                            {
                                cout << "Invalid Input.";
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