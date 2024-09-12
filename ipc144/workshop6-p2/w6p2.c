
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_ITEMS 10
#define MIN_INCOME 500.0
#define MAX_INCOME 400000.0
#define MIN_COST 100.0

int main() {
    double monthlyIncome;
    int numItems, i;
    double itemCosts[MAX_ITEMS];
    int itemPriorities[MAX_ITEMS];
    char itemFinanced[MAX_ITEMS];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");


    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthlyIncome);

        if (monthlyIncome < MIN_INCOME) {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        else if (monthlyIncome > MAX_INCOME) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
    } while (monthlyIncome < MIN_INCOME || monthlyIncome > MAX_INCOME);


    do {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &numItems);

        if (numItems < 1 || numItems > MAX_ITEMS) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    } while (numItems < 1 || numItems > MAX_ITEMS);


    for (i = 0; i < numItems; ++i) {
        printf("\nItem-%d Details:\n", i + 1);


        do {
            printf("   Item cost: $");
            scanf("%lf", &itemCosts[i]);

            if (itemCosts[i] < MIN_COST) {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (itemCosts[i] < MIN_COST); 


        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemPriorities[i]);

            if (itemPriorities[i] < 1 || itemPriorities[i] > 3) {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (itemPriorities[i] < 1 || itemPriorities[i] > 3);


        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &itemFinanced[i]);

            if (itemFinanced[i] != 'y' && itemFinanced[i] != 'n') {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (itemFinanced[i] != 'y' && itemFinanced[i] != 'n');
    }


    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    double totalCost = 0.0;
    for (i = 0; i < numItems; ++i) {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, itemPriorities[i], itemFinanced[i], itemCosts[i]);
        totalCost += itemCosts[i];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);


    int forecastOption;
    do {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &forecastOption);

        if (forecastOption < 0 || forecastOption > 2) {
            printf("\nERROR: Invalid menu selection.\n\n");
            continue;
        }

        if (forecastOption == 1) {

            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", totalCost);
            int totalMonths = (int)(totalCost / monthlyIncome) + ((int)(totalCost) % (int)(monthlyIncome) != 0);
            printf("Forecast: %d years, %d months\n", totalMonths / 12, totalMonths % 12);
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            printf("====================================================\n\n");
        }
        else if (forecastOption == 2) {

            int priority;
            do {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf("%d", &priority);

                if (priority < 1 || priority > 3) {
                    printf("ERROR: Value must be between 1 and 3\n");
                }
            } while (priority < 1 || priority > 3);

            double priorityCost = 0.0;
            for (i = 0; i < numItems; ++i) {
                if (itemPriorities[i] == priority) {
                    priorityCost += itemCosts[i];
                }
            }

            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", priority);
            printf("Amount:   $%.2lf\n", priorityCost);
            int priorityMonths = (int)(priorityCost / monthlyIncome) + ((int)(priorityCost) % (int)(monthlyIncome) != 0);
            printf("Forecast: %d years, %d months\n", priorityMonths / 12, priorityMonths % 12);
            if (priority != 2) {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
                
            }
            printf("====================================================\n\n");
        }
    } while (forecastOption != 0);


    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}
