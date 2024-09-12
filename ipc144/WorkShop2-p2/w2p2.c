
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

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

    int pattyQuantity;
    printf("\nPatty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &pattyQuantity);
    float pattySubTotal = smallShirtPrice * pattyQuantity;
    float pattyTax = pattySubTotal * TAX;
    pattyTax = ((int)(pattyTax * 100 + 0.5)) / 100.0;
    float pattyTotal = pattySubTotal + pattyTax;

    int tommyQuantity;
    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tommyQuantity);
    float tommySubTotal = largeShirtPrice * tommyQuantity;
    float tommyTax = tommySubTotal * TAX;
    tommyTax = ((int)(tommyTax * 100 + 0.5)) / 100.0;
    float tommyTotal = tommySubTotal + tommyTax;

    int sallyQuantity;
    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &sallyQuantity);
    float sallySubTotal = mediumShirtPrice * sallyQuantity;
    float sallyTax = sallySubTotal * TAX;
    sallyTax = ((int)(sallyTax * 100 + 0.5)) / 100.0;
    float sallyTotal = sallySubTotal + sallyTax;

    float grandSubTotal = pattySubTotal + tommySubTotal + sallySubTotal;
    float grandTax = pattyTax + tommyTax + sallyTax;
    float grandTotal = grandSubTotal + grandTax;

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2f %3d %9.4f %9.4f %9.4f\n", patSize, smallShirtPrice, pattyQuantity, pattySubTotal, pattyTax, pattyTotal);
    printf("Sally    %-4c %5.2f %3d %9.4f %9.4f %9.4f\n", salSize, mediumShirtPrice, sallyQuantity, sallySubTotal, sallyTax, sallyTotal);
    printf("Tommy    %-4c %5.2f %3d %9.4f %9.4f %9.4f\n", tomSize, largeShirtPrice, tommyQuantity, tommySubTotal, tommyTax, tommyTotal);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4f %9.4f %9.4f\n\n", grandSubTotal, grandTax, grandTotal);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4f\n", grandSubTotal);

    float balance = grandSubTotal;
    int toonies = (int)(balance / 2);
    balance -= toonies * 2;
    printf("Toonies  %3d %9.4f\n", toonies, balance);

    int loonies = (int)(balance / 1);
    balance -= loonies * 1;
    printf("Loonies  %3d %9.4f\n", loonies, balance);

    int quarters = (int)(balance / 0.25);
    balance -= quarters * 0.25;
    printf("Quarters %3d %9.4f\n", quarters, balance);

    int dimes = (int)(balance / 0.10);
    balance -= dimes * 0.10;
    printf("Dimes    %3d %9.4f\n", dimes, balance);

    int nickels = (int)(balance / 0.05);
    balance -= nickels * 0.05;
    printf("Nickels  %3d %9.4f\n", nickels, balance);

    int pennies = (int)(balance / 0.01);
    balance -= pennies * 0.01;
    printf("Pennies  %3d %9.4f\n", pennies, balance);

    float avgCostPerShirt = grandSubTotal / (pattyQuantity + tommyQuantity + sallyQuantity);
    printf("\nAverage cost/shirt: $%.4f\n\n", avgCostPerShirt);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4f\n", grandTotal);

    balance = grandTotal;
    toonies = (int)(balance / 2);
    balance -= toonies * 2;
    printf("Toonies  %3d %9.4f\n", toonies, balance);

    loonies = (int)(balance / 1);
    balance -= loonies * 1;
    printf("Loonies  %3d %9.4f\n", loonies, balance);


    quarters = (int)(balance / 0.25);
    balance -= quarters * 0.25;

    printf("Quarters %3d %9.4f\n", quarters, balance);

    dimes = (int)(balance / 0.10);
    balance -= dimes * 0.10;
    printf("Dimes    %3d %9.4f\n", dimes, balance);

    nickels = (int)(balance / 0.05);
    balance -= nickels * 0.05;
    printf("Nickels  %3d %9.4f\n", nickels, balance);

    pennies = (int)(balance / 0.01);
    balance -= pennies * 0.01;
    printf("Pennies  %3d %9.4f\n", pennies, balance);

    float avgCostPerShirtTax = grandTotal / (pattyQuantity + tommyQuantity + sallyQuantity);
    printf("\nAverage cost/shirt: $%.4f\n", avgCostPerShirtTax);

    return 0;
}
