#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "core.h"
#include "clinic.h"

void displayPatientTableHeader(void) {
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

void displayPatientData(const struct Patient* patient, int fmt) {
    if (fmt == FMT_FORM) {
        printf("Name  : %s\n", patient->name);
        printf("Number: %05d\n", patient->patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else {
        printf("%05d %-15s ", patient->patientNumber, patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


void menuMain(struct ClinicData* data) {
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
        switch (selection) {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection) {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

void menuPatient(struct Patient patient[], int max) {
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
        switch (selection) {
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

void menuPatientEdit(struct Patient* patient) {
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

        if (selection == 1) {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2) {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    int i;
    int count = 0;
    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            count++;
        }
    }
    putchar('\n');
    if (count == 0) {
        printf("*** No records found ***\n");
    }
}

void searchPatientData(const struct Patient patient[], int max) {
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
        switch (selection) {
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

void addPatient(struct Patient patient[], int max) {
    int i;
    int index = -1;
    int newPatientNum;

    for (i = 0; i < max && index == -1; i++) {
        if (patient[i].patientNumber == 0) {
            index = i;
        }
    }

    if (index == -1) {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else {
        newPatientNum = nextPatientNumber(patient, max);
        patient[index].patientNumber = newPatientNum;
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
    }
}

void editPatient(struct Patient patient[], int max) {
    int patientNum;
    int index;
    printf("Enter the patient number: ");
    patientNum = inputInt();
    index = findPatientIndexByPatientNum(patientNum, patient, max);
    if (index == -1) {
        printf("ERROR: Patient record not found!\n");
        clearInputBuffer();
    }
    else {
        printf("\n");
        menuPatientEdit(&patient[index]);
    }
}

void removePatient(struct Patient patient[], int max) {
    int patientNum;
    int index;
    char confirmDelete;
    printf("Enter the patient number: ");
    patientNum = inputInt();
    index = findPatientIndexByPatientNum(patientNum, patient, max);
    if (index == -1) {
        printf("\n");
        printf("ERROR: Patient record not found!\n");
        clearInputBuffer();
    }
    else {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        confirmDelete = inputCharOption("yn");
        if (confirmDelete == 'y') {
            printf("Patient record has been removed!\n");
            patient[index].patientNumber = 0;
        }
        else {
            printf("Operation aborted.\n");
        }
        printf("\n");
    }
}

void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int patientNumber, index;
    printf("Search by patient number: ");
    patientNumber = inputInt();
    clearInputBuffer();
    index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1) {
        printf("*** No records found ***\n");
    }
    else {
        displayPatientData(&patient[index], FMT_FORM);
    }
}

void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    int i;
    int found = 0;
    char phoneNumber[PHONE_LEN + 1];
    printf("Search by phone number: ");
    inputCString(phoneNumber, PHONE_LEN, PHONE_LEN);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0) {
            displayPatientData(&patient[i], FMT_TABLE);
            found = 1;
        }
    }
    if (!found) {
        printf("\n*** No records found ***\n");
    }
}

int nextPatientNumber(const struct Patient patient[], int max) {
    int i;
    int highestNumber = 0;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > highestNumber) {
            highestNumber = patient[i].patientNumber;
        }
    }
    return highestNumber + 1;
}

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == patientNumber) {
            return i;
        }
    }
    return -1;
}

void inputPatient(struct Patient* patient) {
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
}

void inputPhoneData(struct Phone* phone) {
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
    switch (selection) {
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
    if (selection != 4) {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, PHONE_LEN, PHONE_LEN);
        printf("\n");
    }
    else {
        phone->number[0] = '\0';
    }
}


void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}

void viewAllAppointments(const struct ClinicData* data)
{
    int i, j;
    sortAppointments(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }

    printf("\n");

}

void viewAppointmentSchedule(const struct ClinicData* data) {
    int i, j, maxD;
    struct Date date;

    printf("Year        : ");
    date.year = inputIntPositive();
    printf("Month (%d-%d): ", MIN_MONTH, MAX_MONTH);
    date.month = inputIntRange(MIN_MONTH, MAX_MONTH);
    maxD = daysOfMonth(date.year, date.month);
    printf("Day (%d-%d)  : ", MIN_DAY, maxD);
    date.day = inputIntRange(MIN_DAY, maxD);

    sortAppointments(data->appointments, data->maxAppointments);
    printf("\n");

    // Display data
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++) {
        for (j = 0; j < data->maxPatient; j++) {
            if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {
                if (data->appointments[i].date.year == date.year &&
                    data->appointments[i].date.month == date.month &&
                    data->appointments[i].date.day == date.day) {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                }
            }
        }
    }
    printf("\n");
}


void addAppointment(struct Appointment appointment[], int maxAppointments, struct Patient* patient, int maxPatients)
{
    int patientNum, maxDay, patientSearch = 0, newSlot, valid = 0;
    struct Time tempTime;
    struct Date tempDate;

    newSlot = newAppointment(appointment, maxAppointments);


    printf("Patient Number: ");
    patientNum = inputIntPositive();

    patientSearch = findPatientIndexByPatientNum(patientNum, patient, maxPatients);

    if (patientSearch != -1)
    {
        do
        {
            printf("Year        : ");
            tempDate.year = inputIntPositive();
            printf("Month (%d-%d): ", MIN_MONTH, MAX_MONTH);
            tempDate.month = inputIntRange(MIN_MONTH, MAX_MONTH);
            maxDay = daysOfMonth(tempDate.year, tempDate.month);
            printf("Day (%d-%d)  : ", MIN_DAY, maxDay);
            tempDate.day = inputIntRange(MIN_DAY, maxDay);

            printf("Hour (%d-%d)  : ", MIN_HOUR_ADD, MAX_HOUR_ADD);
            tempTime.hour = inputIntRange(MIN_HOUR_ADD, MAX_HOUR_ADD);
            printf("Minute (%d-%d): ", MIN_MIN, MAX_MIN);
            tempTime.min = inputIntRange(MIN_MIN, MAX_MIN);

            while (tempTime.hour < MIN_HOUR || tempTime.hour > MAX_HOUR || tempTime.min % MIN_INTERVAL != 0 || (tempTime.hour == MAX_HOUR && tempTime.min > 0))
            {
                printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");

                printf("Hour (%d-%d)  : ", MIN_HOUR_ADD, MAX_HOUR_ADD);
                tempTime.hour = inputIntRange(MIN_HOUR_ADD, MAX_HOUR_ADD);
                printf("Minute (%d-%d): ", MIN_MIN, MAX_MIN);
                tempTime.min = inputIntRange(MIN_MIN, MAX_MIN);
            }

            if (timeSlot(tempDate, tempTime, appointment, maxAppointments))
            {
                appointment[newSlot].patientNumber = patientNum;
                appointment[newSlot].time = tempTime;
                appointment[newSlot].date = tempDate;
                printf("\n*** Appointment scheduled! ***\n\n");
                valid = 1;
            }
            else
            {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
        } while (!valid);

    }
    else
    {
        printf("\n*** No records found ***\n\n");
    }

}

void removeAppointment(struct Appointment appointment[], int maxAppointments, struct Patient* patient, int maxPatients)
{
    int patientNum, patientInd, maxDay, appointmentInd;
    struct Date temp;

    printf("Patient Number: ");
    patientNum = inputIntPositive();

    patientInd = findPatientIndexByPatientNum(patientNum, patient, maxPatients);

    if (patientInd > 0)
    {
        printf("Year        : ");
        temp.year = inputIntPositive();
        printf("Month (%d-%d): ", MIN_MONTH, MAX_MONTH);
        temp.month = inputIntRange(MIN_MONTH, MAX_MONTH);
        maxDay = daysOfMonth(temp.year, temp.month);
        printf("Day (%d-%d)  : ", MIN_DAY, maxDay);
        temp.day = inputIntRange(MIN_DAY, maxDay);

        appointmentInd = findRecordIndex(patientNum, temp, appointment, maxAppointments);
        printf("\n");
        if (appointmentInd != -1)
        {
            displayPatientData(&patient[patientInd], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y')
            {
                appointment[appointmentInd].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");

            }
            else
            {
                printf("\nAppointemnt record was not removed!\n\n");
            }
        }
        else
        {
            printf("\nAppointment record not found!\n\n");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }

}

void sortAppointments(struct Appointment appointments[], int max)
{
    int i, j;
    struct Appointment temporary;

    for (i = 0; i < max; i++)
    {
        appointments[i].time.min = (appointments[i].date.year * 12 * 30 * 24 * 60) + (appointments[i].date.month * 30 * 24 * 60) + (appointments[i].date.day * 24 * 60) + (appointments[i].time.hour * 60) + appointments[i].time.min;
    }

    for (i = max - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appointments[j].time.min > appointments[j + 1].time.min)
            {
                temporary = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temporary;
            }

        }
    }
    for (i = 0; i < max; i++) {
        appointments[i].time.min = appointments[i].time.min - (appointments[i].date.year * 12 * 30 * 24 * 60) - (appointments[i].date.month * 30 * 24 * 60) - (appointments[i].date.day * 24 * 60) - (appointments[i].time.hour * 60);
    }
}


int timeSlot(struct Date date, struct Time time, struct Appointment* appointment, int max)
{
    int i;
    for (i = 0; i < max; i++)
    {
        if (appointment[i].time.min == time.min && appointment[i].time.hour == time.hour && appointment[i].date.day == date.day && appointment[i].date.month == date.month && appointment[i].date.year == date.year)
        {
            return 0;
        }
    }
    return 1;
}

int daysOfMonth(int year, int month)
{
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29; 
        }
        else {
            return 28; 
        }
    }
    
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    
    else {
        return 31;
    }
}
void menuAppointment(struct ClinicData* data) {
    int selection;

    do {
        printf("Appointment Management\n");
        printf("==============================\n");
        printf("1) VIEW   ALL Appointments\n");
        printf("2) VIEW   Appointments by DATE\n");
        printf("3) ADD    Appointment\n");
        printf("4) REMOVE Appointment\n");
        printf("------------------------------\n");
        printf("0) Previous menu\n");
        printf("------------------------------\n");
        printf("Selection: ");

        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection) {
        case 1:
            viewAllAppointments(data);
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);
            suspend();
            break;
        }
    } while (selection);
}

int findRecordIndex(int patientNumber, struct Date date, struct Appointment* app, int maxAppointments)
{
    int i = 0, valid = 0;

    while (valid == 0 && i < maxAppointments)
    {
        if ((app[i].patientNumber == patientNumber) && (app[i].date.day == date.day) && (app[i].date.month == date.month) && (app[i].date.year == date.year)) {
            valid = 1;
        }

        i++;
    }
    return i - 1;
}

int newAppointment(struct Appointment* appointment, int max)
{
    int i = 0, valid = 0;
    while (valid == 0 && i < max)
    {
        if (appointment[i].patientNumber < 1)
        {
            valid = 1;
        }
        i++;
    }
    return i;
}



int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int counter = 0;
    FILE* fp = NULL;
    fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        while ((fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[counter].patientNumber, patients[counter].name, patients[counter].phone.description, patients[counter].phone.number) != EOF && counter < max))
        {
            counter++;
        }
        fclose(fp);
    }
    else
    {
        printf("Failed to open file\n");
    }

    return counter;
}


int importAppointments(const char* filename, struct Appointment appointments[], int max) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        return 0;
    }

    int count = 0;
    while (count < max && fscanf(fp, "%d,%d,%d,%d,%d,%d\n",
        &appointments[count].patientNumber,
        &appointments[count].date.year,
        &appointments[count].date.month,
        &appointments[count].date.day,
        &appointments[count].time.hour,
        &appointments[count].time.min) == 6) {
        count++;
    }

    fclose(fp);
    return count;
}
