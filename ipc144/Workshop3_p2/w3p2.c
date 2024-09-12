#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    const double GRAMS_IN_LBS = 453.5924;
    char type1, type2, type3;
    int weight1, weight2, weight3;
    char cream1, cream2, cream3;
    


    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type1);
    printf("Bag weight (g): ");
    scanf("%d", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type2);
    printf("Bag weight (g): ");
    scanf("%d", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type3);
    printf("Bag weight (g): ");
    scanf("%d", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);


    char prefType1;
    int servings1;
    char prefCream1;


    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        (type1 == 'L') || (type1 == 'l'), (type1 == 'M') || (type1 == 'm'), (type1 == 'R') || (type1 == 'r'), weight1, weight1 / GRAMS_IN_LBS, (cream1 == 'Y') || (cream1 == 'y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        (type2 == 'L') || (type2 == 'l'), (type2 == 'M') || (type2 == 'm'), (type2 == 'R') || (type2 == 'r'), weight2, weight2 / GRAMS_IN_LBS, (cream2 == 'Y') || (cream2 == 'y'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        (type3 == 'L') || (type3 == 'l'), (type3 == 'M') || (type3 == 'm'), (type3 == 'R') || (type3 == 'r'), weight3, weight3 / GRAMS_IN_LBS, (cream2 == 'Y') || (cream2 == 'y'));


    printf("\nEnter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &prefType1);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &prefCream1);
    printf("Typical number of daily servings: ");
    scanf("%d", &servings1);


    printf("\nThe below table shows how your preferences align to the available products:\n");
    printf("\n--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
        (prefType1 == 'L' || prefType1 == 'l'), (servings1 >= 1 && servings1 <= 4) && (weight1 == 250), (prefCream1 == 'Y' || prefCream1 == 'y'));
    printf(" 2|       %d         |      %d      |   %d   |\n",
        (prefType1 == 'R' || prefType1 == 'r'), (servings1 >= 5 && servings1 <= 9) && (weight2 == 500), (prefCream1 == 'N' || prefCream1 == 'n'));
    printf(" 3|       %d         |      %d      |   %d   |\n",
        (prefType1 == 'M' || prefType1 == 'm'), (servings1 >= 10) && (weight3 == 1000), (prefCream1 == 'N' || prefCream1 == 'n'));
    char prefType2;
    int servings2;
    char prefCream2;

    printf("\nEnter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &prefType2);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &prefCream2);
    printf("Typical number of daily servings: ");
    scanf("%d", &servings2);

   

    printf("\nThe below table shows how your preferences align to the available products:\n");
    printf("\n--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
        (prefType2 == 'L' || prefType2 == 'l'), (servings2 >= 1 && servings2 <= 4) && (weight1 == 250), (prefCream2 == 'Y' || prefCream2 == 'y'));
    printf(" 2|       %d         |      %d      |   %d   |\n",
        (prefType2 == 'R' || prefType2 == 'r'), (servings2 >= 5 && servings2 <= 9) && (weight2 == 500), (prefCream2 == 'N' || prefCream2 == 'n'));
    printf(" 3|       %d         |      %d      |   %d   |\n",
        (prefType2 == 'M' || prefType2 == 'm'), (servings2 >= 10) && (weight3 == 1000), (prefCream2 == 'N' || prefCream2 == 'n'));

    printf("\nHope you found a product that suits your likes!\n");



    return 0;
}





