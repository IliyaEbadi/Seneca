
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_LIVES 1
#define MAX_LIVES 10
#define MULTI_OF 5
#define MIN_PATHLENGTH 10
#define MAX_PATHLENGTH 70

struct PlayerInfo {
    int lives;
    char symbol;
    int num_treasures;
    int history[MAX_PATHLENGTH];
};

struct GameInfo {
    int pathlength;
    int moves;
    int bombs[MAX_PATHLENGTH];
    int treasures[MAX_PATHLENGTH];
};

int main(void) {
    int next_move;
    int i, j;;
    struct PlayerInfo player;
    struct GameInfo game;
    int first_time = 1;

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
            printf("     Must be between 1 and 10!\n");
        }
    } while (player.lives < MIN_LIVES || player.lives > MAX_LIVES);

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");
    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathlength);
        if (game.pathlength < MIN_PATHLENGTH || game.pathlength > MAX_PATHLENGTH || game.pathlength % MULTI_OF != 0) {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (game.pathlength < MIN_PATHLENGTH || game.pathlength > MAX_PATHLENGTH || game.pathlength % MULTI_OF != 0);

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
        if (game.moves < player.lives || game.moves >(int)(game.pathlength * 0.75)) {
            printf("    Value must be between %d and %d\n", player.lives, (int)(game.pathlength * 0.75));
        }
    } while (game.moves < player.lives || game.moves >(int)(game.pathlength * 0.75));
    printf("\n");

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathlength);
    for (i = 0; i < game.pathlength; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for (j = i; j < i + 5; j++) {
            scanf("%d", &game.bombs[j]);
        }
    }
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathlength);
    for (i = 0; i < game.pathlength; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for (j = i; j < i + 5; j++) {
            scanf("%d", &game.treasures[j]);
        }
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathlength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathlength; i++) {
        printf("%d", game.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathlength; i++) {
        printf("%d", game.treasures[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================");

    player.num_treasures = 0;
    for (i = 0; i < game.pathlength; i++) {
        player.history[i] = 0;
    }
    while (player.lives >= 0 && game.moves > 0) {
        if (first_time) {
            printf("\n");
            first_time = 0;
        }
        else {
            for (i = 0; i < game.pathlength; i++) {
                if (player.history[i] == 1 && i == (next_move - 1)) {
                    printf("  %c", player.symbol);
                    break;
                }
                else {
                    printf(" ");
                }
            }
        }

        printf("\n  ");
        for (i = 0; i < game.pathlength; i++) {
            if (player.history[i] == 0) {
                printf("-");
            }
            else if (game.bombs[i] == 1 && game.treasures[i] == 1) {
                printf("&");
            }
            else if (game.bombs[i] == 1) {
                printf("!");
            }
            else if (game.treasures[i] == 1) {
                printf("$");
            }
            else {
                printf(".");
            }
        }
        printf("\n  ");
        for (i = 0; i < game.pathlength; i++) {
            if ((i + 1) % 10 == 0) {
                printf("%d", (i + 1) / 10);
            }
            else {
                printf("|");
            }
        }
        printf("\n  ");
        for (i = 0; i < game.pathlength; i++) {
            if ((i + 1) % 10 == 0) {
                printf("0");
            }
            else {
                printf("%d", (i + 1) % 10);
            }
        }
        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.num_treasures, game.moves);
        printf("+---------------------------------------------------+\n");

        if (player.lives == 0 || game.moves == 0) {
            break;
        }

        while (1) {
            printf("Next Move [1-%d]: ", game.pathlength);
            scanf("%d", &next_move);
            if (next_move < 1 || next_move > game.pathlength) {
                printf("  Out of Range!!!\n");
            }
            else {
                break;
            }
        }

        if (player.history[next_move - 1] == 1) {
            printf("\n===============> Dope! You've been here before!\n\n");
        }
        else {
            player.history[next_move - 1] = 1;
            game.moves--;
            if (game.bombs[next_move - 1] == 1 && game.treasures[next_move - 1] == 1) {
                player.lives--;
                player.num_treasures++;
                printf("\n===============> [&] !!! BOOOOOM !!! [&]");
                printf("\n===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                if (player.lives == 0) {
                    printf("\nNo more LIVES remaining!\n\n");
                }
                else if (game.moves == 0) {
                    printf("\nNo more MOVES remaining!\n");
                }
            }
            else if (game.bombs[next_move - 1] == 1) {
                player.lives--;
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
                if (player.lives == 0) {
                    printf("No more LIVES remaining!\n\n");
                }
            }
            else if (game.treasures[next_move - 1] == 1) {
                player.num_treasures++;
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            }
            else {
                printf("\n===============> [.] ...Nothing found here... [.]\n\n");
            }
        }


    }
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\nYou should play again and try to beat your score!\n");

    return 0;
}
