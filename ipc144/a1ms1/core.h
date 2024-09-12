#ifndef CORE_H
#define CORE_H

void clearInputBuffer(void);
void suspend(void);
int inputInt(void);
int inputIntPositive(void);
int inputIntRange(int lower, int upper);
char inputCharOption(const char* validChars);
void inputCString(char* str, int minLength, int maxLength);
void displayFormattedPhone(const char* phone);

#endif
