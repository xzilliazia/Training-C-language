#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <windows.h>
#include <time.h>

#define PROFILE_DIR "profiles"

typedef struct {
    char name[50];
    int hp;
    int maxHp;
    int stamina;
    int maxStamina;
    int attack;
    int defense;
    int level;
    int potions;
    int superPotions;
    int hyperPotions;
} Character;

void resetPotions(Character *player);
void setDifficulty(Character *enemy, int choice);
void saveProfile(Character *player);

void resetPotions(Character *player) {
    player->potions = 3;
    player->superPotions = 2;
    player->hyperPotions = 1;
    printf("Potion stocks have been replenished for this battle.\n");
}

void createProfileDirectory() {             // User create Profile and store inside /profile directory
    if (CreateDirectory(PROFILE_DIR, NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
        printf("Profiles directory exists or created.\n");
    } else {
        printf("Failed to create profiles directory.\n");
    }
}

// User save profile
void saveProfile(Character *player) {
    char filePath[100];
    snprintf(filePath, sizeof(filePath), "%s\\%s.txt", PROFILE_DIR, player->name);
    FILE *file = fopen(filePath, "w");
    if (file) {
        fprintf(file, "name: %s\n", player->name);
        fprintf(file, "hp: %d\n", player->hp);
        fprintf(file, "maxHp: %d\n", player->maxHp);
        fprintf(file, "stamina: %d\n", player->stamina);
        fprintf(file, "maxStamina: %d\n", player->maxStamina);
        fprintf(file, "attack: %d\n", player->attack);
        fprintf(file, "defense: %d\n", player->defense);
        fprintf(file, "level: %d\n", player->level);
        fprintf(file, "potions: %d\n", player->potions);
        fprintf(file, "superPotions: %d\n", player->superPotions);
        fprintf(file, "hyperPotions: %d\n", player->hyperPotions);
        fclose(file);
        printf("Your progress has been saved.\n");
    } else {
        printf("Failed to save your progress.\n");
    }
}

int listAndSelectProfile(Character *player) {           // User list and Select their Profile
    DIR *dir;
    struct dirent *entry;
    char profiles[100][100];
    int profileCount = 0;

    dir = opendir(PROFILE_DIR);
    if (dir == NULL) {
        printf("No profiles found.\n");
        return 0;
    }

    printf("\nAvailable profiles:\n");
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".txt")) {
            printf("%d. %s\n", profileCount + 1, entry->d_name);
            strcpy(profiles[profileCount], entry->d_name);
            profileCount++;
        }
    }
    closedir(dir);

    if (profileCount == 0) {
        printf("No profiles found.\n");
        return 0;
    }

    int choice;
    printf("Select a profile by number: ");
    if (scanf("%d", &choice) != 1) {
    printf("Invalid input. Exiting.\n");
    return 0;
}

    if (choice < 1 || choice > profileCount) {
        printf("Invalid choice.\n");
        return 0;
    }

    char filePath[100];
    snprintf(filePath, sizeof(filePath), "%s/%s", PROFILE_DIR, profiles[choice - 1]);
    FILE *file = fopen(filePath, "r");
    if (file) {
        fscanf(file, "name: %49[^\n]\n", player->name);
        fscanf(file, "hp: %d\n", &player->hp);
        fscanf(file, "maxHp: %d\n", &player->maxHp);
        fscanf(file, "stamina: %d\n", &player->stamina);
        fscanf(file, "maxStamina: %d\n", &player->maxStamina);
        fscanf(file, "attack: %d\n", &player->attack);
        fscanf(file, "defense: %d\n", &player->defense);
        fscanf(file, "level: %d\n", &player->level);
        fscanf(file, "potions: %d\n", &player->potions);
        fscanf(file, "superPotions: %d\n", &player->superPotions);
        fscanf(file, "hyperPotions: %d\n", &player->hyperPotions);
        fclose(file);
        printf("\nProfile '%s' loaded successfully.\n", player->name);
        return 1;
    } else {
        printf("Failed to load profile.\n");
        return 0;
    }
}

void createProfile(Character *player) {             // User create a new profile
    printf("Enter your name: ");
    scanf(" %49[^\n]", player->name);

    // Player Default stats
    player->level = 1;
    player->hp = 100;
    player->maxHp = 100;
    player->stamina = 50;
    player->maxStamina = 50;
    player->attack = 20;
    player->defense = 10;
    player->potions = 3;
    player->superPotions = 2;
    player->hyperPotions = 1;

    printf("Welcome, %s! Your profile has been created.\n", player->name);
    saveProfile(player);
}

void startFight(Character *player) {
    Character enemy = {"Wild Pokemon", 0, 0, 0, 0};
    int difficulty;

    printf("Choose a difficulty level:\n");
    printf("1. Easy\n2. Medium\n3. Hard\n4. Random\nEnter your choice: ");
    scanf("%d", &difficulty);

    if (difficulty < 1 || difficulty > 4) {
        printf("Invalid choice. Defaulting to Random difficulty.\n");
        difficulty = 4;
    }

    resetPotions(player);
    setDifficulty(&enemy, difficulty);

    printf("A wild %s appeared with %d HP, %d Attack, and %d Defense!\n",
           enemy.name, enemy.hp, enemy.attack, enemy.defense);

    while (enemy.hp > 0 && player->hp > 0) {
    }
}

void resetCharacter(Character *player) {            // Character stats reset to default if user lost
    player->level = 1;
    player->hp = 100;
    player->maxHp = 100;
    player->stamina = 50;
    player->maxStamina = 50;
    player->attack = 10;
    player->defense = 5;
    resetPotions(player);
}

void levelUp(Character *player) {           // Profile Level up
    player->level++;
    player->maxHp += 20;
    player->hp = player->maxHp;
    player->maxStamina += 10;
    player->stamina = player->maxStamina;
    player->attack += 5;

    printf("Congratulations! You've leveled up to Level %d!\n", player->level);
    printf("Stats upgraded: HP: %d, Stamina: %d, Attack: %d.\n",
           player->maxHp, player->maxStamina, player->attack);
}

void setDifficulty(Character *enemy, int choice) {          // Difficulty set according user choices
    if (choice == 1) { // Easy
        enemy->hp = rand() % 21 + 30;
        enemy->attack = 10;
        enemy->defense = 5;
    } else if (choice == 2) { // Medium
        enemy->hp = rand() % 31 + 60;
        enemy->attack = 20;
        enemy->defense = 10;
    } else if (choice == 3) { // Hard
        enemy->hp = rand() % 51 + 100;
        enemy->attack = 30;
        enemy->defense = 20;
    } else if (choice == 4) { // Random
        enemy->hp = rand() % 201 + 30;
        enemy->attack = rand() % 31 + 10;
        enemy->defense = rand() % 21 + 5;
    }
    enemy->maxHp = enemy->hp;
}

void attack(Character *player, Character *enemy) {          // Feature for user to attack (Quick Attack & Heavy Attack)
    int attackChoice, damage;
    printf("Choose attack type:\n");
    printf("1. Quick Attack (low stamina, low damage)\n");
    printf("2. Heavy Attack (high stamina, high damage)\n");
    printf("Enter your choice: ");
    scanf("%d", &attackChoice);

    if (attackChoice == 1 && player->stamina >= 5) {
        damage = (player->attack / 2) - enemy->defense;
        player->stamina -= 5;
    } else if (attackChoice == 2 && player->stamina >= 15) {
        damage = (player->attack * 2) - enemy->defense;
        player->stamina -= 15;
    } else {
        printf("Not enough stamina or invalid choice. Attack failed.\n");
        return;
    }

    if (damage < 0) damage = 0;
    enemy->hp -= damage;
    printf("You dealt %d damage! Enemy HP: %d\n", damage, enemy->hp);
}

void useItem(Character *player) {           // Feature for use to be able use 3 items 
    int itemChoice;
    printf("Choose an item to use:\n");
    printf("1. Potion (Restores 10 HP and 5 Stamina)\n");
    printf("2. Super Potion (Restores 25 HP and 15 Stamina)\n");
    printf("3. Hyper Potion (Restores 50 HP and 30 Stamina)\n");
    printf("4. Cancel\n");
    printf("Enter your choice: ");
    scanf("%d", &itemChoice);

    if (itemChoice == 1 && player->potions > 0) {
        player->hp += 10;
        player->stamina += 5;
        if (player->hp > player->maxHp) player->hp = player->maxHp;
        if (player->stamina > player->maxStamina) player->stamina = player->maxStamina;
        player->potions--;
        printf("You used a Potion! Your HP: %d, Stamina: %d\n", player->hp, player->stamina);
    } else if (itemChoice == 2 && player->superPotions > 0) {
        player->hp += 25;
        player->stamina += 15;
        if (player->hp > player->maxHp) player->hp = player->maxHp;
        if (player->stamina > player->maxStamina) player->stamina = player->maxStamina;
        player->superPotions--;
        printf("You used a Super Potion! Your HP: %d, Stamina: %d\n", player->hp, player->stamina);
    } else if (itemChoice == 3 && player->hyperPotions > 0) {
        player->hp += 50;
        player->stamina += 30;
        if (player->hp > player->maxHp) player->hp = player->maxHp;
        if (player->stamina > player->maxStamina) player->stamina = player->maxStamina;
        player->hyperPotions--;
        printf("You used a Hyper Potion! Your HP: %d, Stamina: %d\n", player->hp, player->stamina);
    } else if (itemChoice == 4) {
        printf("You canceled the item usage.\n");
    } else {
        printf("Invalid choice or insufficient items.\n");
    }
}

int main() {
    Character player;
    Character enemy = {"Wild Pokemon", 0, 0, 0, 0};
    int choice, difficulty;

    srand(time(0));
    createProfileDirectory(); 

    printf("1. Load existing profile\n2. Create a new profile\nChoose an option: ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (!listAndSelectProfile(&player)) {
            printf("No valid profile loaded. Exiting.\n");
            return 0;
        }
    } else if (choice == 2) {
        createProfile(&player);
    } else {
        printf("Invalid choice. Exiting.\n");
        return 0;
    }

    printf("Choose a difficulty level:\n");
    printf("1. Easy\n2. Medium\n3. Hard\n4. Random\nEnter your choice: ");
    scanf("%d", &difficulty);

    if (difficulty < 1 || difficulty > 4) {
        printf("Invalid choice. Defaulting to Random difficulty.\n");
        difficulty = 4;
    }

    resetPotions(&player);

    setDifficulty(&enemy, difficulty);

    printf("A wild %s appeared with %d HP, %d Attack, and %d Defense!\n",
           enemy.name, enemy.hp, enemy.attack, enemy.defense);

    while (enemy.hp > 0 && player.hp > 0) {
        printf("\nPlayer Level: %d, HP: %d, Stamina: %d, Potions: %d | Super Potions: %d | Hyper Potions: %d\n",
               player.level, player.hp, player.stamina, player.potions, player.superPotions, player.hyperPotions);
        printf("Enemy HP: %d\n", enemy.hp);
        printf("1. Attack\n2. Use Item\n3. Run\nChoose an action: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Turn skipped.\n");
            continue;
        }

        if (choice == 1) {
            attack(&player, &enemy);
        } else if (choice == 2) {
            useItem(&player);
        } else if (choice == 3) {
            printf("\nYou ran away!\n");
            break;
        } else {
            printf("Invalid choice. Turn skipped.\n");
            continue;
        }

        if (enemy.hp <= 0) {
            printf("\nYou defeated the enemy!\n");
            levelUp(&player);
            saveProfile(&player);
            break;
        }

        int crit = rand() % 10 == 0;
        int damage = enemy.attack - player.defense;
        if (crit) {
            damage *= 2;
            printf("Critical hit! ");
        }
        if (damage < 0) damage = 0;
        player.hp -= damage;
        printf("The enemy attacked! Your HP: %d\n", player.hp);

        if (player.hp <= 0) {
            printf("\nYou were defeated. Game over.\n");
            printf("Do you want to start over? (1: Yes, 2: No): ");
            int restart;
            if (scanf("%d", &restart) != 1 || (restart != 1 && restart != 2)) {
                printf("Invalid input. Exiting.\n");
                return 0;
            }
            if (restart == 1) {
                resetCharacter(&player);
            } else {
                return 0;
            }
        }
    }

    while (1) { 
        printf("Do you want to fight again? (1: Yes, 2: No): ");
        int fightAgain;
        if (scanf("%d", &fightAgain) != 1 || (fightAgain != 1 && fightAgain != 2)) {
            printf("Invalid input. Exiting.\n");
            return 0;
        }
        if (fightAgain == 1) {
            startFight(&player); 
        } else {
            break; 
        }
    }
    return 0;
}