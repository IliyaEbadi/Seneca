//Name:Iliya Ebadi
//ID: 168935237
//Email: tebadi@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include "CC.h"
#include "cstr.h" 

using namespace std;

namespace seneca {
    CC::CC() : name(nullptr), number(0), cvv(0), expMonth(0), expYear(0) {}

    CC::~CC() {
        cleanUp(); 
    }

    void CC::cleanUp() {
        freeMem(name); 
        set(); 
    }

    bool CC::isEmpty() const {
        return name == nullptr;
    }

    void CC::set() {
        name = nullptr;
        number = 0;
        cvv = 0;
        expMonth = 0;
        expYear = 0;
    }

    void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
        cleanUp(); 

        if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
            if (!alocpy(name, cc_name)) { 
                cleanUp(); 
                return; 
            }
            
            number = cc_no;
            this->cvv = cvv;
            this->expMonth = expMon;
            this->expYear = expYear;
        }
    }

    bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
        return name && strlen(name) > 2 &&
            cardNo >= 4000000000000000ull && cardNo <= 4099999999999999ull &&
            cvv >= 100 && cvv <= 999 &&
            expMon >= 1 && expMon <= 12 &&
            expYear >= 24 && expYear <= 32;
    }

    void CC::prnNumber(unsigned long long CCnum) const {
        cout << CCnum / 1000000000000ull << " ";
        CCnum %= 1000000000000ull;
        cout.fill('0');
        cout.width(4);
        cout.setf(ios::right);
        cout << CCnum / 100000000ull << " ";
        CCnum %= 100000000ull;
        cout.width(4);
        cout << CCnum / 10000ull << " ";
        CCnum %= 10000ull;
        cout.width(4);
        cout << CCnum;
        cout.unsetf(ios::right);
        cout.fill(' ');
    }

    void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const {
        char lname[31]{};  
        strncpy(lname, name, 30); 
        cout << "| ";
        cout.width(30);
        cout.fill(' ');
        cout.setf(ios::left);
        cout << lname << " | "; 
        prnNumber(number); 
        cout << " | " << cvv << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(2);
        cout << expMon << "/" << expYear << " |" << endl;
        cout.unsetf(ios::right);
    }

    void CC::display() const {
        if (isEmpty()) {
            cout << "Invalid Credit Card Record" << endl;
        }
        else {
            display(name, number, expYear, expMonth, cvv);
        }
    }
}
