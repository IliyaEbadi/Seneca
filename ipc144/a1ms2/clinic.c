/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  :Iliya Ebadi
Student ID#:168935237
Email      :tebadi@myseneca.ca
Section    :IPC144NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"
#include "clinic.h"

void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n", patient->name);
        printf("Number: %05d\n", patient->patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber, patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n");
        printf("=========================\n");
        printf("1) PATIENT     Management\n");
        printf("2) APPOINTMENT Management\n");
        printf("-------------------------\n");
        printf("0) Exit System\n");
        printf("-------------------------\n");
        printf("Selection: ");

        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n");
        printf("=========================\n");
        printf("1) VIEW   Patient Data\n");
        printf("2) SEARCH Patients\n");
        printf("3) ADD    Patient\n");
        printf("4) EDIT   Patient\n");
        printf("5) REMOVE Patient\n");
        printf("-------------------------\n");
        printf("0) Previous menu\n");
        printf("-------------------------\n");
        printf("Selection: ");

        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n", patient->patientNumber);
        printf("=========================\n");
        printf("1) NAME : %s\n", patient->name);
        printf("2) PHONE: ");

        displayFormattedPhone(patient->phone.number);

        printf("\n");
        printf("-------------------------\n");
        printf("0) Previous menu\n");
        printf("-------------------------\n");
        printf("Selection: ");

        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    int count = 0;
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            count++;
        }
    }
    putchar('\n');
    if (count == 0) {
        printf("*** No records found ***\n");
    }
}

void searchPatientData(const struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            putchar('\n');
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            putchar('\n');
            suspend();
            break;

        }


    } while (selection);
}

void addPatient(struct Patient patient[], int max)
{
    int i;
    int index = -1;
    int newPatientNum;

    for (i = 0; i < max && index == -1; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            index = i;
        }
    }

    if (index == -1)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        newPatientNum = nextPatientNumber(patient, max);
        patient[index].patientNumber = newPatientNum;
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
    }
}

void editPatient(struct Patient patient[], int max)
{
    int patientNum;
    int index;
    printf("Enter the patient number: ");
    patientNum = inputInt();
    index = findPatientIndexByPatientNum(patientNum, patient, max);
    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n");
        clearInputBuffer();
    }
    else
    {
        printf("\n");
        menuPatientEdit(&patient[index]);
    }
}

void removePatient(struct Patient patient[], int max)
{
    int patientNum;
    int index;
    char confirmDelete;
    printf("Enter the patient number: ");
    scanf("%d", &patientNum);
    index = findPatientIndexByPatientNum(patientNum, patient, max);
    if (index == -1)
    {
        printf("\n");
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();

    }
    else
    {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        confirmDelete = inputCharOption("yn");
        if (confirmDelete == 'y')
        {
            printf("Patient record has been removed!\n");
            patient[index].patientNumber = 0;
        }
        else
        {
            printf("Operation aborted.\n");
        }
        printf("\n");
    }
}

void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNumber, index;
    printf("Search by patient number: ");
    scanf("%d", &patientNumber);
    clearInputBuffer();
    index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        printf("\n*** No records found ***\n");
    }
    else
    {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
    }
}

void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i;
    int found = 0;
    char phoneNumber[PHONE_LEN + 1];
    printf("Search by phone number: ");
    inputCString(phoneNumber, 10, 10);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\n*** No records found ***\n");
    }
}

int nextPatientNumber(const struct Patient patient[], int max)
{
    int i;
    int highestNumber = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > highestNumber)
        {
            highestNumber = patient[i].patientNumber;
        }
    }
    return highestNumber + 1;
}

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }
    return -1;
}

void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
}

void inputPhoneData(struct Phone* phone)
{
    int selection;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    putchar('\n');
    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;
    }
    if (selection != 4)
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        printf("\n");
    }
    else
    {
        phone->number[0] = '\0';

    }
}
