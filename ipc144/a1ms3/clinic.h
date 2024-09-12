#ifndef CLINIC_H
#define CLINIC_H

// Format identifiers for displaying patient data
#define FMT_FORM 1
#define FMT_TABLE 2

#define NAME_LEN 15
#define PHONE_LEN 10

#define MIN_MIN 0
#define MAX_MIN 59
#define MIN_HOUR 10
#define MAX_HOUR 14
#define MIN_DAY 1
#define MAX_DAY 29
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_INTERVAL 30
#define MIN_HOUR_ADD 0
#define MAX_HOUR_ADD 23

struct Phone {
    char description[5];
    char number[PHONE_LEN + 1];
};

struct Patient {
    int patientNumber;
    char name[NAME_LEN + 1];
    struct Phone phone;
};

struct Time {
    int hour;
    int min;
};

struct Date {
    int year;
    int month;
    int day;
};

struct Appointment {
    int patientNumber;
    struct Date date;
    struct Time time;
};

struct ClinicData {
    struct Patient* patients;
    int maxPatient;
    struct Appointment* appointments;
    int maxAppointments;
};

// Function prototypes
void menuMain(struct ClinicData* data);
void menuPatient(struct Patient patient[], int max);
void menuPatientEdit(struct Patient* patient);
void displayAllPatients(const struct Patient patient[], int max, int fmt);
void searchPatientData(const struct Patient patient[], int max);
void addPatient(struct Patient patient[], int max);
void editPatient(struct Patient patient[], int max);
void removePatient(struct Patient patient[], int max);
void inputPatient(struct Patient* patient);
void inputPhoneData(struct Phone* phone);
int importPatients(const char* datafile, struct Patient patients[], int max);
int importAppointments(const char* filename, struct Appointment appointments[], int max);

// Additional function prototypes for Milestone 3
void viewAllAppointments(const struct ClinicData* data);
void viewAppointmentSchedule(const struct ClinicData* data);
void addAppointment(struct Appointment appointment[], int maxAppointments, struct Patient* patient, int maxPatients);
void removeAppointment(struct Appointment appointment[], int maxAppointments, struct Patient* patient, int maxPatients);
void displayScheduleHeader(const struct Date* date, int isAllRecords);
void displayScheduleData(const struct Patient* patient,const struct Appointment* appoint, int includeDateField);
void menuAppointment(struct ClinicData* data);
int nextPatientNumber(const struct Patient patient[], int max);
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max);
void searchPatientByPatientNumber(const struct Patient patient[], int max);
void searchPatientByPhoneNumber(const struct Patient patient[], int max);


int daysOfMonth(int year, int month);
void sortAppointments(struct Appointment appointments[], int max);
int timeSlot(struct Date date, struct Time time, struct Appointment* appointment, int max);
int findRecordIndex(int patientNumber, struct Date date, struct Appointment* app, int maxAppointments);

int newAppointment(struct Appointment* appointment, int max);

#endif // CLINIC_H
