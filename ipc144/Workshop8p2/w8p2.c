
#define _CRT_SECURE_NO_WARNINGS
#include "w8p2.h"

int getIntPositive(int* intValue) {
    int value;
    do {
        scanf("%d", &value);
        if (value <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
    } while (value <= 0);

    if (intValue != NULL) {
        *intValue = value;
    }

    return value;
}

double getDoublePositive(double* doubleValue) {
    double value;
    do {
        scanf("%lf", &value);
        if (value <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
    } while (value <= 0);

    if (doubleValue != NULL) {
        *doubleValue = value;
    }

    return value;
}

void openingMessage(const int numProducts) {
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", numProducts);
    printf("NOTE: A 'serving' is %dg\n", SUGGESTED_SERVING);
}

struct CatFoodInfo getCatFoodInfo(const int sequenceNumber) {
    struct CatFoodInfo catFood;
    printf("\nCat Food Product #%d\n", sequenceNumber);
    printf("--------------------\n");

    printf("SKU           : ");
    getIntPositive(&catFood.sku);

    printf("PRICE         : $");
    getDoublePositive(&catFood.price);

    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&catFood.weightLbs);

    printf("CALORIES/SERV.: ");
    getIntPositive(&catFood.calories);

    return catFood;
}

void displayCatFoodHeader(void) {
    printf("\n\nSKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(const int sku, const double* price, const double* weightLbs, const int calories) {
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weightLbs, calories);
}

void start(void) {
    struct CatFoodInfo catFoods[MAX_PRODUCTS] = { {0} };
    struct ReportData reports[MAX_PRODUCTS] = { {0} };
    int i, cheapestIndex = 0;

    openingMessage(MAX_PRODUCTS);

  
    for (i = 0; i < MAX_PRODUCTS; i++) {
        catFoods[i] = getCatFoodInfo(i + 1);
    }

    displayCatFoodHeader();
    for (i = 0; i < MAX_PRODUCTS; i++) {
        displayCatFoodData(catFoods[i].sku, &catFoods[i].price, &catFoods[i].weightLbs, catFoods[i].calories);
    }

   
    for (i = 0; i < MAX_PRODUCTS; i++) {
        reports[i] = calculateReportData(catFoods[i]);
    }

    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (reports[i].costPerCal < reports[cheapestIndex].costPerCal) {
            cheapestIndex = i;
        }
    }

    
    displayReportHeader();
   
    for (i = 0; i < MAX_PRODUCTS; i++) {
        displayReportData(reports[i], i == cheapestIndex);
    }

  
    displayFinalAnalysis(&catFoods[cheapestIndex]);
}



double convertLbsKg(const double* lbs, double* kg) {
    double result = *lbs / LBS_IN_KG;
    if (kg != NULL) {
        *kg = result;
    }
    return result;
}

int convertLbsG(const double* lbs, int* grams) {
    int result = (int)(*lbs * 453.59237);
    if (grams != NULL) {
        *grams = result;
    }
    return result;
}

void convertLbs(const double* lbs, double* kg, int* grams) {
    if (kg != NULL) {
        *kg = convertLbsKg(lbs, kg);
    }
    if (grams != NULL) {
        *grams = convertLbsG(lbs, grams);
    }
}

double calculateServings(const int servingSizeG, const int totalWeightG, double* totalServings) {
    double result = (double)totalWeightG / servingSizeG;
    if (totalServings != NULL) {
        *totalServings = result;
    }
    return result;
}

double calculateCostPerServing(const double* price, const double* totalServings, double* costPerServing) {
    double result = *price / *totalServings;
    if (costPerServing != NULL) {
        *costPerServing = result;
    }
    return result;
}

double calculateCostPerCal(const double* price, const double* totalCalories, double* costPerCal) {
    double result = *price / *totalCalories;
    if (costPerCal != NULL) {
        *costPerCal = result;
    }
    return result;
}

struct ReportData calculateReportData(const struct CatFoodInfo catFood) {
    struct ReportData report;
    report.sku = catFood.sku;
    report.price = catFood.price;
    report.calories = catFood.calories;
    report.weightLbs = catFood.weightLbs;

   
    convertLbs(&catFood.weightLbs, &report.weightKg, &report.weightG);

   
    calculateServings(SUGGESTED_SERVING, report.weightG, &report.totalServings);

   
    calculateCostPerServing(&report.price, &report.totalServings, &report.costPerServing);

    
    double totalCalories = report.totalServings * catFood.calories;
    calculateCostPerCal(&report.price, &totalCalories, &report.costPerCal);

    return report;
}

void displayReportHeader(void) {
    printf("\nAnalysis Report (Note: Serving = %dg)\n", SUGGESTED_SERVING);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

void displayReportData(const struct ReportData reportData, int isCheapest) {
    printf("%07d %10.2lf %10.1lf %10.4lf    %6d %8d %8.1lf %7.2lf %7.5lf",
        reportData.sku, reportData.price, reportData.weightLbs,
        reportData.weightKg, reportData.weightG, reportData.calories,
        reportData.totalServings, reportData.costPerServing, reportData.costPerCal);

    if (isCheapest) {
        printf(" ***");
    }
    printf("\n");
}

void displayFinalAnalysis(const struct CatFoodInfo* catFood) {
    printf("\nFinal Analysis\n");
    printf("--------------\n");
    printf("Based on the analysis, the cheapest product is:\n");
    printf("SKU:%07d Price: $%.2lf\n", catFood->sku, catFood->price);
    printf("\nHappy shopping!\n");
}
