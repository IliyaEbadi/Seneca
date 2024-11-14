//name: iliya Ebadi
//Email: tebadi@myseneca.ca
//id: 168935237
#include <iomanip>
#include "Professor.h"
#include "Utils.h"

namespace seneca {
    Professor::Professor(const char* name, const char* subject, int sections,
        size_t employeeNo, double salary)
        : Employee(name, employeeNo, salary) {
        m_subject = ut.alocpy(subject);
        m_sections = sections;
    }

    Professor::~Professor() {
        delete[] m_subject;
    }

    double Professor::devPay() const {
        return (salary() * 0.01) * m_sections;
    }

    std::ostream& Professor::write(std::ostream& ostr) const {
        ostr.setf(std::ios::left);
        Employee::write(ostr);
        ostr.unsetf(std::ios::left);

        char subjectBuffer[21]{};
        if (m_subject) ut.strcpy(subjectBuffer, m_subject, 20);

        ostr << " ";

        ostr.setf(std::ios::left);
        ostr.width(20);
        ostr << subjectBuffer;
        ostr.unsetf(std::ios::left);

        ostr << " | ";

        ostr.setf(std::ios::right);
        ostr.width(5);
        ostr << m_sections;
        ostr.unsetf(std::ios::right);

        ostr << " | ";

        ostr.setf(std::ios::fixed | std::ios::right);
        ostr.width(8);
        ostr.precision(2);
        ostr << devPay() << " |";
        ostr.unsetf(std::ios::right | std::ios::fixed);

        return ostr;
    }

    std::istream& Professor::read(std::istream& istr) {
        if (Employee::read(istr)) {
            char buffer[1024];
            if (istr.peek() == ',') {
                istr.ignore();
                istr.getline(buffer, 1024, ',');
                ut.alocpy(m_subject, buffer);
                istr >> m_sections;

                if (istr.eof()) {
                    istr.clear();
                }
            }
        }
        return istr;
    }

    std::ostream& Professor::title(std::ostream& ostr) const {
        Employee::title(ostr);
        ostr << " Teaching Subject     | Sec # | $Dev Pay |";
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Professor& prof) {
        return prof.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, Professor& prof) {
        return prof.read(istr);
    }
}
