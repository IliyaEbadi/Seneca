
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    char loopType;
    int iterations;
    int i;  

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    do {
        printf("\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &iterations);

        if (loopType == 'Q') {
            if (iterations != 0) {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            }
            else {
                break;
            }
            continue;
        }

        if ((loopType != 'D' && loopType != 'W' && loopType != 'F') || iterations < 0) {
            printf("ERROR: Invalid entered value(s)!\n");
            continue;
        }

        if (iterations < 3 || iterations > 20) {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            continue;
        }

        switch (loopType) {
        case 'D':
            printf("DO-WHILE: ");
            for (i = 0; i < iterations; i++) {
                printf("D");
            }
            printf("\n");
            break;
        case 'W':
            printf("WHILE   : ");
            for (i = 1; i < 11; i++) {
                printf("W");
            }
            printf("\n");
            break;
        case 'F':
            printf("FOR     : ");
            for (i = 0; i < iterations; i++) {
                printf("F");
            }
            printf("\n");
            break;
        default:
            break;
        }
    } while (1);

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    return 0;
}
