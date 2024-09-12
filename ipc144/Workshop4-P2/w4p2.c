

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int apples, oranges, pears, tomatoes, cabbages;
	int pickAmount;
	int repeat;

	do {
		printf("Grocery Shopping\n");
		printf("================\n");

		do {
			printf("How many APPLES do you need? : ");
			scanf("%d", &apples);
			if (apples < 0)
				printf("ERROR: Value must be 0 or more.\n");
		} while (apples < 0);

		do {
			printf("\nHow many ORANGES do you need? : ");
			scanf("%d", &oranges);
			
			if (oranges < 0)
				printf("ERROR: Value must be 0 or more.");
		} while (oranges < 0);

		do {
			printf("\nHow many PEARS do you need? : ");
			scanf("%d", &pears);
			if (pears < 0)
				printf("ERROR: Value must be 0 or more.");
		} while (pears < 0);

		do {
			printf("\nHow many TOMATOES do you need? : ");
			scanf("%d", &tomatoes);
			if (tomatoes < 0)
				printf("ERROR: Value must be 0 or more.");
		} while (tomatoes < 0);

		do {
			printf("\nHow many CABBAGES do you need? : ");
			scanf("%d", &cabbages);
			if (cabbages < 0)
				printf("ERROR: Value must be 0 or more.");
		} while (cabbages < 0);

		printf("\n--------------------------\n");
		printf("Time to pick the products!\n");
		printf("--------------------------\n");

		while (apples > 0) {
			printf("\nPick some APPLES... how many did you pick? : ");
			scanf("%d", &pickAmount);
			if (pickAmount <= 0) {
				printf("ERROR: You must pick at least 1!");
			}
			else if (pickAmount > apples) {
				printf("You picked too many... only %d more APPLE(S) are needed.", apples);
			}
			else {
				apples = apples - pickAmount;
				if (apples > 0) {
					printf("Looks like we still need some APPLES...");
				}
				else {
					printf("Great, that's the apples done!\n");
				}
			}
		}

		while (oranges > 0) {
			printf("\nPick some ORANGES... how many did you pick? : ");
			scanf("%d", &pickAmount);
			if (pickAmount <= 0) {
				printf("ERROR: You must pick at least 1!");
			}
			else if (pickAmount > oranges) {
				printf("You picked too many... only %d more ORANGE(S) are needed.", oranges);
			}
			else {
				oranges -= pickAmount;
				if (oranges > 0) {
					printf("Looks like we still need some ORANGES...");
				}
				else {
					printf("Great, that's the oranges done!\n");
				}
			}
		}

		while (pears > 0) {
			printf("\nPick some PEARS... how many did you pick? : ");
			scanf("%d", &pickAmount);
			if (pickAmount <= 0) {
				printf("ERROR: You must pick at least 1!");
			}
			else if (pickAmount > pears) {
				printf("You picked too many... only %d more PEAR(S) are needed.", pears);
			}
			else {
				pears -= pickAmount;
				if (pears > 0) {
					printf("Looks like we still need some PEARS...");
				}
				else {
					printf("Great, that's the pears done!\n");
				}
			}
		}

		while (tomatoes > 0) {
			printf("\nPick some TOMATOES... how many did you pick? : ");
			scanf("%d", &pickAmount);
			if (pickAmount <= 0) {
				printf("ERROR: You must pick at least 1!");
			}
			else if (pickAmount > tomatoes) {
				printf("You picked too many... only %d more TOMATO(ES) are needed.", tomatoes);
			}
			else {
				tomatoes -= pickAmount;
				if (tomatoes > 0) {
					printf("Looks like we still need some TOMATOES...");
				}
				else {
					printf("Great, that's the tomatoes done!\n");
				}
			}
		}

		while (cabbages > 0) {
			printf("\nPick some CABBAGES... how many did you pick? : ");
			scanf("%d", &pickAmount);
			if (pickAmount <= 0) {
				printf("ERROR: You must pick at least 1!");
			}
			else if (pickAmount > cabbages) {
				printf("You picked too many... only %d more CABBAGE(S) are needed.", cabbages);
			}
			else {
				cabbages -= pickAmount;
				if (cabbages > 0) {
					printf("Looks like we still need some CABBAGES...");
				}
				else {
					printf("Great, that's the cabbages done!\n");
				}
			}
		}

		printf("\nAll the items are picked!\n");
		printf("\nDo another shopping? (0=NO): ");
		scanf("%d", &repeat);
		printf("\n");
		if (repeat == 0) {
			printf("Your tasks are done for today - enjoy your free time!\n");
			break;
		}

	} while (1);

	return 0;
}
