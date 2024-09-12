#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "core.h"

void clearInputBuffer(void) {
    while (getchar() != '\n') {
        ;
    }
}


void suspend(void) {
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


int inputInt(void) {
    int value;
    char newLine = 'x';
    while (newLine != '\n') {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    return value;
}


int inputIntPositive(void) {
    int value;
    do {
        value = inputInt();
        if (value <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value <= 0);
    return value;
}


int inputIntRange(int lower, int upper) {
    int value;
    do {
        value = inputInt();
        if (value < lower || value > upper) {
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
        }
    } while (value < lower || value > upper);
    return value;
}


char inputCharOption(const char* validChars) {
    char option;
    int isValid = 0;
    int i;
    do {
        scanf(" %c", &option);
        clearInputBuffer();
        for ( i = 0; validChars[i] != '\0'; i++) {
            if (option == validChars[i]) {
                isValid = 1;
                break;
            }
        }
        if (!isValid) {
            printf("ERROR: Character must be one of [%s]: ", validChars);
        }
    } while (!isValid);
    return option;
}

void inputCString(char* str, int minLength, int maxLength) {
    int length;
    int done = 0;
    while (!done) {
        if (fgets(str, maxLength + 2, stdin) == NULL) {
            clearInputBuffer();
            continue;
        }

        length = strlen(str);
        if (str[length - 1] == '\n') {
            str[length - 1] = '\0';
            length--;
        }
        else {
            clearInputBuffer();
        }

        if (length < minLength || length > maxLength) {
            if (minLength == maxLength) {
                printf("ERROR: String length must be exactly %d chars: ", minLength);
            }
            else if (length > maxLength) {
                printf("ERROR: String length must be no more than %d chars: ", maxLength);
            }
            else {
                printf("ERROR: String length must be between %d and %d chars: ", minLength, maxLength);
            }
        }
        else {
            done = 1;
        }
    }
}

void displayFormattedPhone(const char* phone) {
    int isValid = 1;
    int i;
    if (phone == NULL || strlen(phone) != 10) {
        isValid = 0;
    }
    
    else {
        for ( i = 0; i < 10; i++) {
            if (phone[i] < '0' || phone[i] > '9') {
                isValid = 0;
                break;
            }
        }
    }

    if (isValid) {
        printf("(%c%c%c)%c%c%c-%c%c%c%c", phone[0], phone[1], phone[2], phone[3], phone[4], phone[5], phone[6], phone[7], phone[8], phone[9]);
    }
    else {
        printf("(___)___-____");
    }
}
