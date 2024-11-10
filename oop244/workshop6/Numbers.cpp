//name: Iliya Ebadi
//Email:tebadi@myseneca.ca
//ID: 168935237
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>

#include "Numbers.h"

using namespace std;

namespace seneca {

    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else {
            sort();
        }
    }

    Numbers::Numbers(const Numbers& src) {
        setEmpty();
        m_isOriginal = false; 
        *this = src;
    }
    Numbers& Numbers::operator=(const Numbers& src) {
        if (this != &src) {
            delete[] m_numbers;
            delete[] m_filename;

            m_numCount = src.m_numCount;

            if (src.m_filename) {
                m_filename = new char[strlen(src.m_filename) + 1];
                strcpy(m_filename, src.m_filename);
            }
            else {
                m_filename = nullptr;
            }

            if (src.m_numbers) {
                m_numbers = new double[m_numCount];
                for (size_t i = 0; i < m_numCount; ++i) {
                    m_numbers[i] = src.m_numbers[i];
                }
            }
            else {
                m_numbers = nullptr;
            }
        }
        return *this;
    }

    
    Numbers::~Numbers() {
        if (m_isOriginal) {
            save();
        }
        delete[] m_numbers;
        delete[] m_filename;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        if (filename && filename[0] != '\0') {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
        }
        else {
            m_filename = nullptr;
        }
    }

    size_t Numbers::numberCount() const {
        if (!m_filename) return 0;

        ifstream file(m_filename);
        if (!file) return 0;

        size_t count = 0;
        double temp;
        while (file >> temp) {
            count++;
        }
        return count;
    }

    bool Numbers::load() {
        if (!m_filename || m_numCount == 0) return false;

        ifstream file(m_filename);
        if (!file) return false;

        delete[] m_numbers;
        m_numbers = new double[m_numCount];
        size_t count = 0;

        while (count < m_numCount && file >> m_numbers[count]) {
            count++;
        }

        if (count != m_numCount) {
            delete[] m_numbers;
            m_numbers = nullptr;
            return false;
        }

        return true;
    }

    void Numbers::save() const {
        if (m_isOriginal && !isEmpty() && m_filename) {
            ofstream file(m_filename);
            if (file) {
                for (size_t i = 0; i < m_numCount; ++i) {
                    stringstream ss;
                    ss << m_numbers[i];
                    string str = ss.str();
                    if (str.find('.') != string::npos && str.back() == '0') {
                        str.pop_back();
                    }

                    if (str.back() == '.') {
                        str.pop_back();
                    }

                    file << str << endl;
                }
            }
        }
    }

    void Numbers::sort() {
        if (!isEmpty() && m_numCount > 1) {
            for (size_t i = 0; i < m_numCount - 1; ++i) {
                for (size_t j = 0; j < m_numCount - 1 - i; ++j) {
                    if (m_numbers[j] > m_numbers[j + 1]) {
                        double temp = m_numbers[j];
                        m_numbers[j] = m_numbers[j + 1];
                        m_numbers[j + 1] = temp;
                    }
                }
            }
        }
    }

    double Numbers::average() const {
        if (isEmpty() || m_numCount == 0) return 0.0;

        double sum = 0.0;
        for (size_t i = 0; i < m_numCount; ++i) {
            sum += m_numbers[i];
        }
        return sum / m_numCount;
    }

    double Numbers::min() const {
        if (isEmpty() || m_numCount == 0) return 0.0;
        return m_numbers[0];
    }

    double Numbers::max() const {
        if (isEmpty() || m_numCount == 0) return 0.0;
        return m_numbers[m_numCount - 1];
    }

    Numbers& Numbers::operator+=(double value) {
        if (!isEmpty()) {
            double* temp = new double[m_numCount + 1];
            for (size_t i = 0; i < m_numCount; ++i) {
                temp[i] = m_numbers[i];
            }
            temp[m_numCount] = value;
            delete[] m_numbers;
            m_numbers = temp;
            m_numCount++;
            sort();
        }
        return *this;
    }

    ostream& operator<<(ostream& os, const Numbers& N) {
        if (N.isEmpty()) {
            os << "Empty list";
        }
        else {
            os << "=========================\n";
            if (N.m_isOriginal && N.m_filename) {
                os << N.m_filename << "\n";
            }
            else {
                os << "*** COPY ***\n";
            }

            os << fixed << setprecision(2);  
            for (size_t i = 0; i < N.m_numCount; ++i) {
                os << N.m_numbers[i];
                if (i < N.m_numCount - 1) os << ", ";
            }

            os << "\n-------------------------\n";
            os << "Total of " << N.m_numCount << " number(s)\n";
            os << "Largest number:  " << N.max() << "\n";
            os << "Smallest number: " << N.min() << "\n";
            os << "Average:         " << N.average() << "\n";
            os << "=========================";
        }
        return os;
    }

    istream& operator>>(istream& is, Numbers& N) {
        double value;
        if (is >> value) {
            N += value;
        }
        return is;
    }
}