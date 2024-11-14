//name: iliya Ebadi
//Email: tebadi@myseneca.ca
//id: 168935237
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include "Employee.h"

namespace seneca {
    class Professor : public Employee {
        char* m_subject{};
        int m_sections{};

        double devPay() const;

    public:
        Professor() = default;
        Professor(const char* name, const char* subject, int sections,
            size_t employeeNo, double salary);
        ~Professor();

        Professor(const Professor&) = delete;
        Professor& operator=(const Professor&) = delete;

        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& title(std::ostream& ostr = std::cout) const;
    };

    std::ostream& operator<<(std::ostream& ostr, const Professor& prof);
    std::istream& operator>>(std::istream& istr, Professor& prof);
}
#endif
