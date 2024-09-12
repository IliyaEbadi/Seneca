/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Iliya Ebadi
Student ID#: 168935237
Email      : tebadi@myseneca.ca
Section    : IPC144NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef CORE_H
#define CORE_H

void clearInputBuffer(void);
void suspend(void);
int inputInt(void);
int inputIntPositive(void);
int inputIntRange(int lower, int upper);
char inputCharOption(const char* validChar);
void inputCString(char* stringPtr, int lower, int upper);
void displayFormattedPhone(const char* stringPtr);

#endif // !CORE_H
