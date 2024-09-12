
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define MIN_LIVES 1
#define MAX_LIVES 10
#define MIN_MOVES 3

struct PlayerInfo {
    int lives;
    char symbol;
    int treasureCount;
    int history[MAX_PATH_LENGTH];
};

struct GameInfo {
    int maxMoves;
    int pathLength;
    int bombs[MAX_PATH_LENGTH];
    int treasures[MAX_PATH_LENGTH];
};

int main() {
    struct PlayerInfo player;
    struct GameInfo game;
    int i, j;

   
    for (i = 0; i < MAX_PATH_LENGTH; i++) {
        player.history[i] = 0;
    }

    
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < MIN_LIVES || player.lives > MAX_LIVES) {
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
        }
    } while (player.lives < MIN_LIVES || player.lives > MAX_LIVES);

    printf("Player configuration set-up is complete\n\n");

    
    printf("GAME Configuration\n");
    printf("------------------\n");

    
    do {
        printf("Set the path length (a multiple of 5 between %d-%d): ", MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &game.pathLength);
        if (game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH || game.pathLength % 5 != 0) {
            printf("     Must be a multiple of 5 and between %d-%d!!!\n", MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
    } while (game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH || game.pathLength % 5 != 0);

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxMoves);
        if (game.maxMoves < player.lives || game.maxMoves >(game.pathLength * 3 / 4)) {
            printf("    Value must be between %d and %d\n", player.lives, game.pathLength * 3 / 4);
        }
    } while (game.maxMoves < player.lives || game.maxMoves >(game.pathLength * 3 / 4));

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    for (i = 0; i < game.pathLength; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for (j = 0; j < 5; j++) {
            scanf("%d", &game.bombs[i + j]);
        }
    }
    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    for (i = 0; i < game.pathLength; i += 5) {

        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for (j = 0; j < 5; j++) {
            scanf("%d", &game.treasures[i + j]);
        }
    }
    printf("TREASURE placement set\n");

    printf("\nGAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.treasures[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}
