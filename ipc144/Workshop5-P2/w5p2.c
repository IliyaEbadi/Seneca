/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  : Iliya Ebadi
Student ID#: 168935237
Email      : tbeadi@myseneca.ca
Section    : IPC144NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void) {
    const int JAN = 1;
    const int DEC = 12;
    int year, month;
    double morningRating, eveningRating;
    double morningTotal = 0.0, eveningTotal = 0.0;
    int i;

    printf("General Well-being Log\n");
    printf("======================\n");

    while (1) {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (month < JAN || month > DEC) {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        if (year >= MIN_YEAR && year <= MAX_YEAR && month >= JAN && month <= DEC) {
            break;
        }
    }

    printf("\n*** Log date set! ***\n");

    for (i = 1; i <= LOG_DAYS; i++) {
        printf("\n%d-", year);
        switch (month) {
        case 1:  printf("JAN"); break;
        case 2:  printf("FEB"); break;
        case 3:  printf("MAR"); break;
        case 4:  printf("APR"); break;
        case 5:  printf("MAY"); break;
        case 6:  printf("JUN"); break;
        case 7:  printf("JUL"); break;
        case 8:  printf("AUG"); break;
        case 9:  printf("SEP"); break;
        case 10: printf("OCT"); break;
        case 11: printf("NOV"); break;
        case 12: printf("DEC"); break;
        }
        printf("-%02d\n", i);

       
        while (1) {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);
            if (morningRating >= 0.0 && morningRating <= 5.0) {
                morningTotal = morningTotal+  morningRating;
                break;
            }
            else {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }


        while (1) {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);
            if (eveningRating >= 0.0 && eveningRating <= 5.0) {
                eveningTotal += eveningRating;
                break;
            }
            else {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }
    }

    double overallTotal = morningTotal + eveningTotal;
    double morningAvg = morningTotal / LOG_DAYS;
    double eveningAvg = eveningTotal / LOG_DAYS;
    double overallAvg = overallTotal / (LOG_DAYS * 2);

    
    printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", morningTotal);
    printf("Evening total rating:  %.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", overallTotal);
    printf("\nAverage morning rating:  %.1lf\n", morningAvg);
    printf("Average evening rating:  %.1lf\n", eveningAvg);
    printf("----------------------------\n");
    printf("Average overall rating:%.1lf\n", overallAvg);

    return 0;
}
