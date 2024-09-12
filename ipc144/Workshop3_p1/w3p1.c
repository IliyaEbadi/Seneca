#include <stdio.h>

int main() {
    const double testValue = 330.99;
    const int productID1 = 111;
    const int productID2 = 222;
    const int productID3 = 111;

    const float price1 = 111.49;
    const float price2 = 222.99;
    const float price3 = 334.49;

    const char taxed1 = 'Y';
    const char taxed2 = 'N';
    const char taxed3 = 'N';

    float averagePrice = (price1 + price2 + price3) / 3;

    
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", productID1);
    printf("  Taxed: %c\n", taxed1);
    printf("  Price: $%.4f\n\n", price1);
    printf("Product-2 (ID:%d)\n", productID2);
    printf("  Taxed: %c\n", taxed2);
    printf("  Price: $%.4f\n\n", price2);
    printf("Product-3 (ID:%d)\n", productID3);
    printf("  Taxed: %c\n", taxed3);
    printf("  Price: $%.4f\n", price3);

    
    printf("\nThe average of all prices is: $%.4f\n", averagePrice);

  
    printf("\nAbout Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");

    
    printf("\nSome Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", taxed1 != 'N');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", taxed2 == 'N' && taxed3 == 'N');
    printf("3. Is product 3 less than testValue ($330.99)? -> %d\n\n", price3 < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", price3 > (price1 + price2));
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2f)\n\n", price1 >= (price3 - price2), (price3 - price2));
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", price2 >= averagePrice);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", productID1 != productID2 && productID1 != productID3);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", productID2 != productID1 && productID2 != productID3);
    printf("9. Based on product ID, product 3 is unique -> %d\n", productID3 != productID1 && productID3 != productID2);

    return 0;
}