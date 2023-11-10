#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#include "refcounter.hpp"
#include <cstring>

class my_string {
public:
    my_string(const char* str = "") : data(new char[strlen(str) + 1]) {
        strcpy(data.get(), str);
    }

    void setChar(const int& i, const char& c) {
        if (i >= 0 && i < std::strlen(data.get())) {
            data.get()[i] = c;
        }
    }

    char getChar(const int& i) const {
        if (i >= 0 && i < std::strlen(data.get())) {
            return data.get()[i];
        }
        return '\0'; // return null character for out-of-bounds access
    }

    void print() const {
        std::cout << data.get();
        data.printRefCount();
    }

private:
    RefCountedPtr<char> data;
};

#endif // MY_STRING_HPP
