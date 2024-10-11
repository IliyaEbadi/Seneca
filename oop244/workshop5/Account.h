//Name: Iliya Ebadi
//Email: tebadi@myseneca.ca
//ID:168935237
#pragma once
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_

#include <iostream>

namespace seneca {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();

    public:
        Account();
        Account(int number, double balance);

        std::ostream& display() const;

        operator bool() const;
        operator int() const;
        operator double() const;

        bool operator ~() const;

        Account& operator=(int number);
        Account& operator=(Account& dst);

        Account& operator+=(double amount);
        Account& operator-=(double amount);
        Account& operator>>(Account& dst);
        Account& operator<<(Account& dst);
    };

    double operator+(const Account& src, const Account& dst);
    double& operator+=(double& value, const Account& srcAcc);
}

#endif // SENECA_ACCOUNT_H_
