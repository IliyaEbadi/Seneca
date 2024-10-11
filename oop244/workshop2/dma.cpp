//name: Iliya Ebadi
//email: tebadi@myseneca.ca
//section:NCC
#include <iostream>
#include <limits>  // Add this line
#include "dma.h"
#include "input.h"

using namespace std;

namespace seneca {

    void reverse() {
        int count;
        cout << "Enter the number of double values:" << endl;
        cout << "> ";
        count = getInt();

        double* array = new double[count];

        for (int i = 0; i < count; ++i) {
            cout << i + 1 << "> ";
            cin >> array[i];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

        for (int i = count - 1; i >= 0; --i) {
            cout << array[i] << endl;
        }

        delete[] array;
    }

    Contact* getContact() {
        Contact* c = new Contact;

        cout << "Name: ";
        cin.getline(c->m_name, sizeof(c->m_name));

        cout << "Last name: ";
        cin.getline(c->m_lastname, sizeof(c->m_lastname));

        cout << "Phone number: ";
        cin >> c->m_phoneNumber;
        cin.ignore(1000, '\n');  // Clear the input buffer

        return c;
    }

    void display(const Contact& c) {
        cout << c.m_name << " " << c.m_lastname << ", +" << c.m_phoneNumber << endl;
    }

    void deallocate(Contact* c) {
        delete c;
    }

    void setEmpty(Contact& c) {
        c.m_name[0] = '\0';
        c.m_lastname[0] = '\0';
        c.m_phoneNumber = 0;
    }
}

