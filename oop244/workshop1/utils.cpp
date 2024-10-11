#include "utils.h"
#include <iostream>

namespace seneca {
    void flushkeys() {
        while (std::cin.get() != '\n');
    }

    bool yes() {
        char ch = std::cin.get();
        flushkeys();
        return ch == 'y' || ch == 'Y';
    }

    void toLowerCase(char* des, const char* src) {
        int i = 0;
        while (src[i]) {
            des[i] = src[i] >= 'A' && src[i] <= 'Z' ? src[i] + ('a' - 'A') : src[i];
            i++;
        }
        des[i] = '\0';
    }
}
