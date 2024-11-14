//name: iliya Ebadi
//Email: tebadi@myseneca.ca
//id: 168935237
#include <iostream>
#include "Menu.h"
using namespace std;

namespace seneca {
    MenuItem::MenuItem(const char* content, unsigned int indent, unsigned int indentSize, int rowNum) {
        // Validate content
        if (content == nullptr || ut.isspace(content)) {
            m_content = nullptr;
            return;
        }

        // Validate indentation values
        if (indent > 4 || indentSize > 4) {
            m_content = nullptr;
            return;
        }

        // Validate row number
        if (rowNum >= static_cast<int>(MaximumNumberOfMenuItems)) {
            m_content = nullptr;
            return;
        }

        // Set member variables
        ut.alocpy(m_content, content);
        m_indentation = indent;
        m_indentSize = indentSize;
        m_rowNum = rowNum;
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
    }

    MenuItem::operator bool() const {
        return m_content != nullptr;
    }

    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (!(*this)) {
            ostr << "??????????";
            return ostr;
        }

        // Add indentation
        for (unsigned int i = 0; i < m_indentation * m_indentSize; i++) {
            ostr << " ";
        }

        // Add row number if applicable
        if (m_rowNum >= 0) {
            ostr.width(2);
            ostr << m_rowNum << "- ";
        }

        // Skip leading whitespace in content
        const char* content = m_content;
        while (*content && ut.isspace(*content)) {
            content++;
        }

        // Output the content
        ostr << content;
        return ostr;
    }
}
