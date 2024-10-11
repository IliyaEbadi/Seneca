//name: Iliya Ebadi
//email: tebadi@myseneca.ca
//section:NCC
#include <iostream>
#include <limits>
#include "input.h"

using namespace std;

namespace seneca {

    int getInt() {
        int num = 0;

        while (true) {
            cin >> num;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Bad integer entry, please try again:\n> ";
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return num;
            }
        }
    }

    int getInt(int minVal, int maxVal) {
        int num;

        while (true) {
            num = getInt(); 

            if (num >= minVal && num <= maxVal) {
                return num;
            }
            else {
                cout << "Invalid value, [" << minVal << "<ENTRY<" << maxVal << "]\n> ";
                
            }
        }
    }

    bool getInt(int& number, int minVal, int maxVal) {
        int temp;

        while (true) {
            temp = getInt();  // Reuse the basic getInt function

            if (temp >= minVal && temp <= maxVal) {
                number = temp;
                return true;  // Return true if within the valid range
            }
            else {
                cout << "Only enter values between " << minVal << " and " << maxVal << ", inclusive:\n> ";
                
            }
        }
    }

}
