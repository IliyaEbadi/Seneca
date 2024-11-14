//name: iliya Ebadi
//Email: tebadi@myseneca.ca
//id: 168935237

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
#include "Utils.h"

namespace seneca {
    const unsigned int MaximumNumberOfMenuItems = 20;

    class MenuItem {
        char* m_content{};
        unsigned int m_indentation{};
        unsigned int m_indentSize{};
        int m_rowNum{};

        // Rule of three - prevent copying
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;

    public:
        MenuItem(const char* content, unsigned int indent, unsigned int indentSize, int rowNum);
        ~MenuItem();

        // Type conversion to bool
        operator bool() const;

        // Display function
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };
}
#endif // !SENECA_MENU_H
