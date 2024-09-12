/*###########################################################################

Reflection
Workshop - #1
Full Name : Iliya Ebadi
Student ID# :168935237
    Email :tebadi@myseneca.ca
    Section :IPC144NCC.02493.2244

    Authenticity Declaration :

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
###########################################################################*/

#include <stdio.h>

int main() {
    char first_name[] = "Iliya";
    char last_name[] = "Ebadi";
    int studentID = 168935237;

    printf("Workshop 1 Part-1\n");
    printf("=================\n\n");

    printf("I'm displaying this using the 'printf' stdio\n");
    printf("(standard input output) library function!\n\n");

    printf("Dear teacher,\n\n");

    printf("  I promise I will work hard from this day onward.\n");
    printf("  I acknowledge that practice is extremely important,\n");
    printf("  so I will do all workshops, quizzes, and assignments.\n\n");

    printf("Sincerely,\n\n");

    printf("%s %s\n", first_name, last_name);  
    printf("Student ID# %d", studentID);      

    return 0;
}
