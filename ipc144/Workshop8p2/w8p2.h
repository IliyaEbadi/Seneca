
#ifndef W8P2_H
#define W8P2_H

#include <stdio.h>
#define MAX_PRODUCTS 3
#define SUGGESTED_SERVING 64
#define LBS_IN_KG 2.20462

struct CatFoodInfo {
    int sku;
    double price;
    int calories;
    double weightLbs;
};

struct ReportData {
    int sku;
    double price;
    int calories;
    double weightLbs;
    double weightKg;
    int weightG;
    double totalServings;
    double costPerServing;
    double costPerCal;
};

int getIntPositive(int* intValue);
double getDoublePositive(double* doubleValue);
void openingMessage(const int numProducts);
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber);
void displayCatFoodHeader(void);
void displayCatFoodData(const int sku, const double* price, const double* weightLbs, const int calories);
void start(void);

double convertLbsKg(const double* lbs, double* kg);
int convertLbsG(const double* lbs, int* grams);
void convertLbs(const double* lbs, double* kg, int* grams);
double calculateServings(const int servingSizeG, const int totalWeightG, double* totalServings);
double calculateCostPerServing(const double* price, const double* totalServings, double* costPerServing);
double calculateCostPerCal(const double* price, const double* totalCalories, double* costPerCal);
struct ReportData calculateReportData(const struct CatFoodInfo catFood);
void displayReportHeader(void);
void displayReportData(const struct ReportData reportData, int isCheapest);
void displayFinalAnalysis(const struct CatFoodInfo* catFood);

#endif
