/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  :Iliya Ebadi
Student ID#:168935237
Email      :tebadi@myseneca.ca
Section    :ipc144cnn

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "core.h"


void clearInputBuffer(void) {
    while (getchar() != '\n') {
        ; // do nothing!
    }
}

void suspend(void) {
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void) {
    int value, scanfResult;
    int isValidInput = 0;
    char newLine;

    while (!isValidInput) {
        scanfResult = scanf("%d%c", &value, &newLine);
        if (scanfResult == 2 && newLine == '\n') {
            isValidInput = 1;
        }
        else {
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
    int flag = 0;

    do {
        scanf(" %c", &option);
        clearInputBuffer();

        const char* chars = validChars;
        flag = 0;

        while (*chars != '\0' && flag == 0) {
            if (option == *chars) {
                flag = 1;
            }
            chars++;
        }
        if (flag == 0) {
            printf("ERROR: Character must be one of [%s]: ", validChars);
        }
    } while (flag == 0);

    return option;
}

void inputCString(char* str, int minLength, int maxLength) {
    int lengthCount;
    char temp[100];

    do {
        scanf("%99[^\n]%*c", temp);
        lengthCount = strlen(temp);

        if (lengthCount > maxLength || lengthCount < minLength) {
            if (minLength == maxLength && lengthCount != minLength) {
                printf("ERROR: String length must be exactly %d chars: ", minLength);
            }
            else if (lengthCount > maxLength) {
                printf("ERROR: String length must be no more than %d chars: ", maxLength);
            }
            else if (lengthCount < minLength) {
                printf("ERROR: String length must be between %d and %d chars: ", minLength, maxLength);
            }
        }
    } while (lengthCount > maxLength || lengthCount < minLength);

    strncpy(str, temp, maxLength);
    str[maxLength] = '\0';
}

void displayFormattedPhone(const char* phone) {
    int isValid = 1;
    int i;

    if (phone == NULL || strlen(phone) != 10) {
        isValid = 0;
    }
    else {
        for (i = 0; i < 10; i++) {
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
