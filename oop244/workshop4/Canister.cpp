#include <iostream>
#include "cstr.h"
#include "Canister.h"
using namespace std;

namespace seneca {

    const double PI = 3.14159265;

    Canister::Canister() : m_height(13.0), m_diameter(10.0), m_contentVolume(0.0), m_contentName(nullptr) {}

    Canister::Canister(const char* contentName) : m_height(13.0), m_diameter(10.0), m_contentVolume(0.0), m_contentName(nullptr) {
        alocpy(m_contentName, contentName);
    }

    Canister::Canister(double height, double diameter, const char* contentName) : m_contentVolume(0.0), m_contentName(nullptr), m_height(height), m_diameter(diameter) {
        if (usable()) {
            alocpy(m_contentName, contentName);
        }
    }

    Canister::~Canister() {
        freeMem(m_contentName);
    }

    double Canister::capacity() const {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    bool Canister::isEmpty() const {
        return m_contentVolume < 0.00001;
    }

    bool Canister::usable() const {
        return m_height >= 10 && m_height <= 40 && m_diameter >= 10 && m_diameter <= 30;
    }

    void Canister::setToUnusable() {
        freeMem(m_contentName);
        m_height = m_diameter = -1.0;
    }

    double Canister::volume() const {
        return m_contentVolume;
    }

    bool Canister::hasSameContent(const Canister& C) const {
        return m_contentName && C.m_contentName && strcmp(m_contentName, C.m_contentName) == 0;
    }

    Canister& Canister::clear() {
        freeMem(m_contentName);
        m_contentVolume = 0.0;
        return *this;
    }

    Canister& Canister::setContent(const char* contentName) {
        if (contentName && usable()) {
            if (!m_contentName || isEmpty()) {
                alocpy(m_contentName, contentName);
            }
            else if (!hasSameContent(contentName)) {
                setToUnusable();
            }
        }
        return *this;
    }

    Canister& Canister::pour(double quantity) {
        if (usable()) {
            if (quantity > 0 && (volume() + quantity) < capacity()) {
                m_contentVolume += quantity;
            }
            else {
                setToUnusable();
            }
        }
        return *this;
    }

    Canister& Canister::pour(Canister& can) {
        if (usable()) {
            double spaceAvailable = capacity() - volume();
            if (can.volume() > spaceAvailable) {
                can.m_contentVolume -= spaceAvailable;
                m_contentVolume = capacity();
            }
            else {
                pour(can.m_contentVolume);
                can.m_contentVolume = 0;
            }
            setContent(can.m_contentName);
        }
        return *this;
    }

    std::ostream& Canister::display() const {
        cout.setf(ios::fixed);
        cout.precision(1);
        cout.width(7);
        cout << capacity() << "cc (";
        cout.width(4);
        cout << m_height << "x";
        cout.width(4);
        cout << m_diameter << ") Canister";
        if (!usable()) {
            cout << " is   Unusable   recycle!";
        }
        else {
            cout << " of ";
            cout.width(7);
            cout << volume() << "cc   " << (m_contentName ? m_contentName : "Sanetized and Empty");
        }
        return cout;
    }
}
