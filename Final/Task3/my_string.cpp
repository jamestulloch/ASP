#include "my_string.hpp"

class my_string {
private:
    char* data;
    my_string* ptr;
    unsigned int* ref_count;
public:
    my_string(my_string* p = nullptr);
    ~my_string();
    my_string(const my_string& sp);
    my_string& operator=(const my_string& sp);
    my_string& operator*();
    my_string* operator->();
    unsigned int getRefCount() const {
        return (ref_count) ? (*ref_count) : 0;
    }
};

// Constructor
my_string::my_string(my_string* p) : ptr(p) {
    ref_count = (p) ? (new unsigned int(1)) : (nullptr);
}

// Destructor
my_string::~my_string() {
    if (ref_count && --(*ref_count) == 0) {
        delete ptr;
        delete ref_count;
    }
}

// Copy Constructor
my_string::my_string(const my_string& sp) : ptr(sp.ptr), ref_count(sp.ref_count) {
    if (ref_count) {
        (*ref_count)++;
    }
}

// Copy Assignment Operator
my_string& my_string::operator=(const my_string& sp) {
    if (this != &sp) {
        if (ref_count && --(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
        ptr = sp.ptr;
        ref_count = sp.ref_count;
        if (ref_count) {
            (*ref_count)++;
        }
    }
    return *this;
}



// Dereference Operator
my_string& my_string::operator*() {
    return *ptr;
}

// Arrow Operator
my_string* my_string::operator->() {
    return ptr;
}



