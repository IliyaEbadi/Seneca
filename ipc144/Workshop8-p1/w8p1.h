

#ifndef W8P1_H
#define W8P1_H

#define MAX_PRODUCTS 3
#define GRAMS_SERVING 64

struct CatFoodInfo {
	int sku;
	double price;
	int calories;
	double weight;
};

int getIntPositive(int* num);
double getDoublePositive(double* num);
void openingMessage(const int numProducts);
struct CatFoodInfo getCatFoodInfo(const int index);
void displayCatFoodHeader(void);
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight);
void start(void);

#endif
