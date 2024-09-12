#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "core.h"


void clearInputBuffer(void)
{
    
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}


void suspend(void)
{
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


char inputCharOption(const char* charList) {
    char inputChar, nextChar;
    int i, match = 0, validInput = 1;

    do {
        inputChar = getchar();
        nextChar = getchar(); 

        
        if (inputChar != '\n' && nextChar == '\n') {
         
            i = 0, match = 0, validInput = 1;

           
            while (*(charList + i) != '\0' && !match) {
                if (inputChar == *(charList + i)) {
                    match = 1; 
                }
                i++;
            }
        }
        else {
            validInput = 0; 
            clearInputBuffer(); 
        }

       
        if (!match || !validInput) {
            printf("ERROR: Character must be one of [%s]: ", charList);
        }

    } while (!match || !validInput);

    return inputChar;
}


void inputCString(char* cString, int minChar, int maxChar) {
    char input[100] = { '\0' };
    int length;

    do {
    
        fgets(input, sizeof(input), stdin);

        length = strlen(input);
        if (input[length - 1] == '\n') {
            input[--length] = '\0'; 
        }
        else {
           
            clearInputBuffer();
        }

       
        if ((minChar == maxChar) && (length != minChar)) {
            printf("Invalid %d-digit number! Number: ", minChar);
        }
        else if (length < minChar) {
            printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
        }
        else if (length > maxChar) {
            printf("ERROR: String length must be no more than %d chars: ", maxChar);
        }

    } while (length < minChar || length > maxChar);

    
    strcpy(cString, input);
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

