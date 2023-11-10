#include "my_string.hpp"

// Constructor implementations
my_string::my_string() : data(new char[1]), reference_count(new int(1)) {
    data[0] = '\0';
}

my_string::my_string(const char* str) : data(new char[strlen(str) + 1]), reference_count(new int(1)) {
    strcpy(data, str);
}

// Copy constructor
my_string::my_string(const my_string& s) : data(s.data), reference_count(s.reference_count) {
    // Increment the reference count as we are creating a new reference
    ++(*reference_count);
}

// Destructor
my_string::~my_string() {
    // Decrement the reference count as we are removing a reference
    if (--(*reference_count) == 0) {
        delete[] data; // Delete the data if this was the last reference
        delete reference_count; // Delete the reference count itself
    }
}

// Copy assignment operator
my_string& my_string::operator=(const my_string& s) {
    if (this != &s) {
        // Release the current object's memory if this is not a self-assignment
        if (--(*reference_count) == 0) {
            delete[] data;
            delete reference_count;
        }

        // Copy the data and reference count pointer from the source object
        data = s.data;
        reference_count = s.reference_count;
        ++(*reference_count); // Increment the reference count
    }
    return *this;
}

// Get character at index
char my_string::getChar(const int& i) const {
    if (i >= 0 && i < strlen(data)) { // Bounds check for safety
        return data[i];
    } else {
        throw std::out_of_range("Index out of range"); // Throw an exception if index is out of range
    }
}

// Set character at index
void my_string::setChar(const int& i, const char& c) {
    if (i >= 0 && i < strlen(data)) { // Bounds check for safety
        data[i] = c;
    } else {
        throw std::out_of_range("Index out of range"); // Throw an exception if index is out of range
    }
}

// Print the string
void my_string::print() const {
    std::cout << data << std::endl;
}
