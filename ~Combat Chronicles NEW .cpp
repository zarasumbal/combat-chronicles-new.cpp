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
    string inverntory[5];
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