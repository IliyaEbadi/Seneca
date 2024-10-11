//Name: Iliya Ebadi
//Email: tebadi@myseneca.ca
//ID:168935237
#include <iostream>
#include "Account.h"

using namespace std;

namespace seneca {

    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }

    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999 && balance >= 0) {
            m_number = number;
            m_balance = balance;
        }
    }

    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const {
        return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
    }

    Account::operator int() const {
        return m_number;
    }

    Account::operator double() const {
        return m_balance;
    }

    bool Account::operator~() const {
        return (m_number == 0);
    }

    Account& Account::operator=(int input) {
        if (~*this) {
            if (input < 10000 || input > 99999) {
                setEmpty();
            }
            else {
                m_number = input;
            }
        }
        return *this;
    }

    Account& Account::operator =(Account& dst) {
        if (dst && this->m_number == 0 && this->m_balance == 0) {
            this->m_number = dst.m_number;
            this->m_balance = dst.m_balance;
            dst.m_number = 0;
            dst.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator+=(double amount) {
        if (amount >= 0 && *this) {
            m_balance += amount;
        }
        return *this;
    }

    Account& Account::operator-=(double amount) {
        if (amount >= 0 && *this && m_balance >= amount) {
            m_balance -= amount;
        }
        return *this;
    }

    Account& Account::operator<<(Account& dst) {
        if (*this && dst && this->m_number != dst.m_number) {
            this->m_balance += dst.m_balance;
            dst.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator>>(Account& dst) {
        if (*this && dst && this->m_number != dst.m_number) {
            dst.m_balance += this->m_balance;
            this->m_balance = 0.0;
        }
        return *this;
    }

    double operator+(const Account& src, const Account& dst) {
        return (src && dst) ? (double(src) + double(dst)) : 0.0;
    }

    double& operator+=(double& left, const Account& dst) {
        if (dst) {
            left += double(dst);
        }
        return left;
    }

}
