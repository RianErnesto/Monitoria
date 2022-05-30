#define K 5

typedef struct Weapon
{
    char name[50];

    // Heavy or Light
    char category[50];

    int damage;
} Weapon;

typedef struct Armor
{
    char name[50];

    int defense;
} Armor;

typedef struct Character
{
    // Basic Stats
    char name[50];
    int lifePoints;

    // Atributs
    int strength;
    int constitution;
    int agility;
    int dexterity;

    // Equipment
    Weapon weapon;
    Armor armor;

} Character;

typedef struct Enemy
{
    char name[50];
    int lifePoints;
    int damage;
    int defense;
    int agility;
} Enemy;

void createCharacter(Character *character);
void spreadPoints(Character *character);
void chooseWeapon(Character *character);
void chooseArmor(Character *character);
void calculateWeaponDamage(Character *character, int level);
void calculateArmorDefense(Character *character, int level);
void calculateLifePoints(Character *character);
int rollDice(int sides, int quantityRollings);
void generateEnemy(Enemy *enemy);
void menuFightActions();
void fight(Character *character, Enemy *enemy);
void playerWinsBattle(Character *character);
void enemyWinsBattle();
void printCharacter(Character *character);
void printEnemy(Enemy *enemy);
void printWinGame(Character *character);
void gameHistory();
void mainMenu();
void startGame();

