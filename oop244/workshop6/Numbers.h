//name: Iliya Ebadi
//Email:tebadi@myseneca.ca
//ID: 168935237
#ifndef SENECA_NUMBERS_H
#define SENECA_NUMBERS_H

#include <iostream>

namespace seneca {
    class Numbers {
        double* m_numbers;
        char* m_filename;
        bool m_isOriginal;
        size_t m_numCount;

        void setEmpty();
        void setFilename(const char* filename);
        size_t numberCount() const;
        bool load();
        void save() const;

    public:
        Numbers();
        Numbers(const char* filename);
        Numbers(const Numbers& src);
        Numbers& operator=(const Numbers& src);
        ~Numbers();

        bool isEmpty() const;
        void sort();
        double average() const;
        double max() const;
        double min() const;
        Numbers& operator+=(double value);

        friend std::ostream& operator<<(std::ostream& os, const Numbers& N);
        friend std::istream& operator>>(std::istream& is, Numbers& N);
    };
}
#endif