#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    float smallShirtPrice;
    float mediumShirtPrice;
    float largeShirtPrice;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &smallShirtPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &mediumShirtPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &largeShirtPrice);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", smallShirtPrice);
    printf("MEDIUM : $%.2f\n", mediumShirtPrice);
    printf("LARGE  : $%.2f\n", largeShirtPrice);

    printf("\nPatty's shirt size is 'S'\n");
    int numberOfShirts;
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numberOfShirts);

    float subTotal = smallShirtPrice * numberOfShirts;

    const float TAX = 0.13;
    float taxes = subTotal * TAX;
    taxes = ((int)(taxes * 100 + 0.5)) / 100.0;

    float total = subTotal + taxes;
    total = ((int)(total * 100 + 0.5)) / 100.0;

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", numberOfShirts);
    printf("Sub-total: $%.4f\n", subTotal);
    printf("Taxes    : $ %.4f\n", taxes);
    printf("Total    : $%.4f\n", total);

    return 0;
}