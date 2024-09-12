

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "w8p1.h"

int getIntPositive(int* num) {
    int value;
    do {
        scanf("%d", &value);
        if (value <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
    } while (value <= 0);

    if (num != NULL) {
        *num = value;
    }

    return value;
}

double getDoublePositive(double* num) {
    double value;
    do {
        scanf("%lf", &value);
        if (value <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
    } while (value <= 0);

    if (num != NULL) {
        *num = value;
    }

    return value;
}

void openingMessage(const int numProducts) {
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", numProducts);
    printf("NOTE: A 'serving' is 64g\n\n");
}

struct CatFoodInfo getCatFoodInfo(const int index) {
    struct CatFoodInfo info;
    printf("Cat Food Product #%d\n", index + 1);
    printf("--------------------\n");
    printf("SKU           : ");
    info.sku = getIntPositive(NULL);
    printf("PRICE         : $");
    info.price = getDoublePositive(NULL);
    printf("WEIGHT (LBS)  : ");
    info.weight = getDoublePositive(NULL);
    printf("CALORIES/SERV.: ");
    info.calories = getIntPositive(NULL);
    printf("\n");

    return info;
}

void displayCatFoodHeader(void) {
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight) {
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

void start(void) {
    struct CatFoodInfo products[MAX_PRODUCTS];
    int i;

    openingMessage(MAX_PRODUCTS);
    for (i = 0; i < MAX_PRODUCTS; i++) {
        products[i] = getCatFoodInfo(i);
    }

    displayCatFoodHeader();
    for (i = 0; i < MAX_PRODUCTS; i++) {
        displayCatFoodData(products[i].sku, &products[i].price, products[i].calories, &products[i].weight);
    }
}
