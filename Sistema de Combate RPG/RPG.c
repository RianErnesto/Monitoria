#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "RPG.h"

int PointsToSpread;
int level = 1;
int lost = 0;

void createCharacter(Character *character)
{
    printf("Character's name: ");
    scanf("%s", character->name);

    character->strength = 0;
    character->constitution = 0;
    character->agility = 0;
    character->dexterity = 0;
    PointsToSpread = 15;
}

void spreadPoints(Character *character)
{
    while (PointsToSpread > 0)
    {
        printf("\nYou have %d points to spend.\n", PointsToSpread);
        printf("\nChoose your attribute:\n");
        printf("1. Strength - %d\n", character->strength);
        printf("2. Constitution - %d\n", character->constitution);
        printf("3. Agility - %d\n", character->agility);
        printf("4. Dexterity - %d\n", character->dexterity);
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            character->strength++;
            PointsToSpread--;
            break;

        case 2:
            character->constitution++;
            PointsToSpread--;
            break;

        case 3:
            character->agility++;
            PointsToSpread--;
            break;

        case 4:
            character->dexterity++;
            PointsToSpread--;
            break;

        case 5:
            return;
        default:
            system("cls");
            printf("Invalid option.\n");
            break;
        }

        system("cls");
    }
}

void chooseWeapon(Character *character)
{
    Weapon weapon;
    printf("Choose your weapon:\n");
    printf("1. Sword\n");
    printf("2. Bow\n");
    printf("3. Staff\n");

    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        strcpy(weapon.name, "Sword");
        strcpy(weapon.category, "Heavy");
        weapon.damage = 5;
        character->weapon = weapon;
        break;

    case 2:
        strcpy(weapon.name, "Bow");
        strcpy(weapon.category, "Light");
        weapon.damage = 3;
        character->weapon = weapon;
        break;

    case 3:
        strcpy(weapon.name, "Staff");
        strcpy(weapon.category, "Light");
        weapon.damage = 2;
        character->weapon = weapon;
        break;

    default:
        system("cls");
        printf("Invalid option.\n");
        break;
    }

    system("cls");
}

void chooseArmor(Character *character)
{
    Armor armor;
    printf("Choose your armor:\n");
    printf("1. Leather\n");
    printf("2. Chain\n");
    printf("3. Plate\n");

    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        strcpy(armor.name, "Leather");
        armor.defense = 2;
        character->armor = armor;
        break;

    case 2:
        strcpy(armor.name, "Chain");
        armor.defense = 3;
        character->armor = armor;
        break;

    case 3:
        strcpy(armor.name, "Plate");
        armor.defense = 4;
        character->armor = armor;
        break;

    default:
        system("cls");
        printf("Invalid option.\n");
        break;
    }

    system("cls");
}

void calculateWeaponDamage(Character *character, int level)
{
    if (character->weapon.category == "Heavy")
    {
        character->weapon.damage = rollDice(12, 1) + 1.5 * character->strength + level * K;
    }
    else
    {
        character->weapon.damage = rollDice(6, 2) + rollDice(4, 1) + character->dexterity + level * K;
    }
}

void calculateArmorDefense(Character *character, int level)
{
    character->armor.defense = 1.5 * character->constitution + level * K;
}

void calculateLifePoints(Character *character)
{
    character->lifePoints = rollDice(6, 3) + character->constitution;
}

int rollDice(int sides, int quantityRollings)
{
    int diceRoll = 0;
    int i;
    for (i = 0; i < quantityRollings; i++)
    {
        diceRoll += rand() % sides + 1;
    }
    return diceRoll;
}

void generateEnemy(Enemy *enemy)
{
    if (level == 1)
    {
        int enemyNumber = rand() % 3 + 1;
        switch (enemyNumber)
        {
        case 1:
            strcpy(enemy->name, "Goblin");
            enemy->lifePoints = 10;
            enemy->damage = 2;
            enemy->defense = 2;
            enemy->agility = 2;
        case 2:
            strcpy(enemy->name, "Orc");
            enemy->lifePoints = 15;
            enemy->damage = 3;
            enemy->defense = 3;
            enemy->agility = 3;
        case 3:
            strcpy(enemy->name, "Troll");
            enemy->lifePoints = 20;
            enemy->damage = 4;
            enemy->defense = 4;
            enemy->agility = 4;
        }
    }
    else if (level == 2)
    {
        int enemyNumber = rand() % 2 + 1;
        switch (enemyNumber)
        {
        case 1:
            strcpy(enemy->name, "Dragon");
            enemy->lifePoints = 15;
            enemy->damage = 3;
            enemy->defense = 3;
            enemy->agility = 3;
        case 2:
            strcpy(enemy->name, "Elf");
            enemy->lifePoints = 20;
            enemy->damage = 4;
            enemy->defense = 4;
            enemy->agility = 4;
        }
    }
    else
    {
        strcpy(enemy->name, "Cesupa");
        enemy->lifePoints = 25;
        enemy->damage = 5;
        enemy->defense = 5;
        enemy->agility = 5;
    }
}

void menuFightActions()
{
    printf("\nChoose your action:\n");
    printf("1. Attack\n");
    printf("2. Defend\n");
    printf("3. Use Potion\n");
}

void fight(Character *character, Enemy *enemy)
{
    int damage;
    int enemyCurrentLifePoints = enemy->lifePoints;
    int characterCurrentLifePoints = character->lifePoints;
    int characterIsDefending = 0;
    int enemyIsDefending = 0;
    int quantityCharacterPotions = 3;
    int quantityEnemyPotions = 3;
    int turn = character->agility > enemy->agility ? 1 : 0;

    while (enemyCurrentLifePoints > 0 && characterCurrentLifePoints > 0)
    {

        if (turn)
        {
            int choice;
            menuFightActions();
            scanf("%d", &choice);
            system("cls");
            switch (choice)
            {
            case 1:
                if (enemyIsDefending)
                {
                    damage = character->weapon.damage - enemy->defense * 2;
                    if (damage < 0)
                    {
                        damage = 0;
                    }
                    else
                    {
                        enemyCurrentLifePoints -= damage;
                    }
                    enemyIsDefending = 0;
                }
                else
                {
                    damage = character->weapon.damage - enemy->defense;
                    if (damage < 0)
                    {
                        damage = 0;
                    }
                    else
                    {
                        enemyCurrentLifePoints -= damage;
                    }
                }
                printf("\nYou hit the enemy for %d damage.\n", damage);
                break;
            case 2:
                characterIsDefending = 1;
                printf("\nYou are defending.\n");
                break;
            case 3:
                if (quantityCharacterPotions > 0)
                {
                    int heal = rollDice(6, 3);

                    if (heal > character->lifePoints)
                    {
                        characterCurrentLifePoints = heal;
                    }
                    else
                    {
                        characterCurrentLifePoints += heal;
                    }
                    quantityCharacterPotions--;
                    printf("\nYou used a potion.\n");
                }
                else
                {
                    printf("\nYou don't have any potions.\n");
                }
                break;
            default:
                system("cls");
                printf("Invalid option.\n");
                break;
            }
            turn = 0;
        }
        else
        {
            int choice = rand() % 3 + 1;

            switch (choice)
            {
            case 1:
                if (characterIsDefending)
                {
                    damage = enemy->damage - character->armor.defense * 2;
                    if (damage < 0)
                    {
                        damage = 0;
                    }
                    else
                    {
                        characterCurrentLifePoints -= damage;
                    }
                    characterIsDefending = 0;
                }
                else
                {
                    damage = enemy->damage - character->armor.defense;
                    if (damage < 0)
                    {
                        damage = 0;
                    }
                    else
                    {
                        characterCurrentLifePoints -= damage;
                    }
                }
                printf("\nThe enemy hit you for %d damage.\n", damage);
                break;
            case 2:
                enemyIsDefending = 1;
                printf("\nThe enemy is defending.\n");
                break;
            case 3:
                if (quantityEnemyPotions > 0)
                {
                    int heal = rollDice(6, 3);

                    if (heal > enemy->lifePoints)
                    {
                        enemyCurrentLifePoints = heal;
                    }
                    else
                    {
                        enemyCurrentLifePoints += heal;
                    }
                    quantityEnemyPotions--;
                    printf("\nThe enemy used a potion.\n");
                }
                else
                {
                    printf("\nThe enemy doesn't have any potions.\n");
                }
                break;
            }
            turn = 1;
        }
    }

    if (enemyCurrentLifePoints <= 0)
    {
        printf("You won!\n");
        playerWinsBattle(character);
    }
    else
    {
        printf("You lost!\n");
        enemyWinsBattle();
    }
}

void playerWinsBattle(Character *character)
{
    level++;
    switch (level)
    {
    case 2:
        PointsToSpread += 5;
        spreadPoints(character);
        chooseWeapon(character);
        calculateWeaponDamage(character, level);
        break;
    case 3:
        PointsToSpread += 10;
        spreadPoints(character);
        chooseArmor(character);
        calculateArmorDefense(character, level);
        break;
    }
    character->lifePoints += character->constitution;
}

void enemyWinsBattle()
{
    lost = 1;
    level = 1;
}

void printCharacter(Character *character)
{
    printf("\nName: %s\n", character->name);
    printf("Level: %d\n", level);
    printf("Strength: %d\n", character->strength);
    printf("Dexterity: %d\n", character->dexterity);
    printf("Constitution: %d\n", character->constitution);
    printf("Agility: %d\n", character->agility);
    printf("Armor: %s\n", character->armor.name);
    printf("Defense: %d\n", character->armor.defense);
    printf("Weapon: %s\n", character->weapon.name);
    printf("Damage: %d\n", character->weapon.damage);
    printf("Life Points: %d\n", character->lifePoints);
}

void printEnemy(Enemy *enemy)
{
    printf("\nName: %s\n", enemy->name);
    printf("Life Points: %d\n", enemy->lifePoints);
}

void printWinGame(Character *character)
{
    printf("\nCongratulations! You won the game!\n");
    printf("\nName: %s\n", character->name);
    printf("Level: %d\n", level);
    printf("Strength: %d\n", character->strength);
    printf("Dexterity: %d\n", character->dexterity);
    printf("Constitution: %d\n", character->constitution);
    printf("Agility: %d\n", character->agility);
    printf("Armor: %s\n", character->armor.name);
    printf("Weapon: %s\n", character->weapon.name);
    printf("Life Points: %d\n", character->lifePoints);
}

void gameHistory()
{
    printf("\nGame History:\n");
    printf("Velit amet cillum culpa magna laborum. Eiusmod proident mollit id dolore nulla do adipisicing non. Officia excepteur nulla amet aliquip duis aliqua ea ullamco minim officia. Tempor non ea ad ad pariatur. Ea irure proident dolore nostrud in sint esse esse et. Culpa elit duis irure culpa enim anim dolor in mollit. Exercitation anim ex consequat ipsum laboris.");
    printf("Nostrud esse veniam ut esse culpa veniam officia id velit. Elit elit incididunt exercitation Lorem. Nulla eiusmod amet est mollit laboris eiusmod sit sit fugiat labore adipisicing eu nulla sit. Est id ut fugiat minim cillum occaecat velit commodo ex veniam. Amet nostrud ullamco commodo dolor minim. Ex exercitation adipisicing amet est eiusmod ut velit magna nisi cupidatat. Dolor consequat pariatur exercitation exercitation ullamco id enim.");
    printf("Duis sunt ad amet pariatur adipisicing duis pariatur. Ullamco et ex ut incididunt in qui labore ut anim labore consectetur incididunt ex. Minim commodo do id ut ut ullamco cillum in mollit est. Id tempor deserunt ex nostrud exercitation sint ullamco. Aliqua velit do ut consectetur proident commodo occaecat.");
    printf("Excepteur ipsum ad cillum exercitation est nisi ullamco ullamco quis incididunt occaecat. Anim dolore eiusmod qui voluptate dolore laboris dolor cupidatat nulla id enim anim ipsum. Aliquip dolore excepteur Lorem et ea tempor elit exercitation consequat. Anim sunt aliquip eiusmod laboris elit tempor ad duis enim. Lorem do id sint sit quis esse ea proident incididunt. Laborum deserunt dolor eu magna ad adipisicing cupidatat quis quis exercitation id elit. Qui dolore nostrud velit consectetur dolore consectetur aliquip consequat consequat.");
}

void mainMenu()
{
    printf("\nMain Menu:\n");
    printf("1. Start Game\n");
    printf("2. Game History\n");
    printf("3. Exit\n");
}

void secondaryMenu()
{
    printf("\nSecondary Menu:\n");
    printf("1. Continue\n");
    printf("2. Print Character\n");
    printf("3. Exit\n");
}

void startGame()
{
    Character character;
    Enemy enemy;
    createCharacter(&character);
    spreadPoints(&character);
    calculateLifePoints(&character);
    chooseWeapon(&character);
    calculateWeaponDamage(&character, level);
    chooseArmor(&character);
    calculateArmorDefense(&character, level);

    int choice;
    do
    {
        secondaryMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            generateEnemy(&enemy);
            fight(&character, &enemy);
            break;
        case 2:
            system("cls");
            printCharacter(&character);
            break;
        case 3:
            break;
        default:
            printf("\nInvalid option.\n");
            break;
        }
    } while (choice != 3 && lost == 0 && level < 4);

    if(level == 4) {
        printWinGame(&character);
    }
    lost = 0;
}

void main()
{
    int choice;

    do
    {
        mainMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            startGame();
            break;
        case 2:
            system("cls");
            gameHistory();
            break;
        case 3:
            system("cls");
            printf("\nGoodbye!\n");
            break;
        default:
            system("cls");
            printf("\nInvalid choice.\n");
            break;
        }
    } while (choice != 3);
}





