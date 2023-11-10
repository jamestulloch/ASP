#include <stdio.h>
#include "my_string.hpp"
#include "refcount.hpp"

// Default constructor
my_string::my_string() : data(new char[1]) { 
    data[0] = '\0'; // Initialize with an empty string
}

// Constructor from C-style string
my_string::my_string(const char* str) : data(new char[std::strlen(str) + 1]) {
    // Ensure that 'data' is not const when passed to strcpy by using the non-const 'get' method.
    std::strcpy(data.get(), str); // Copy the string into 'data'
}

// Copy constructor
my_string::my_string(const my_string& s) : data(s.data) {
    // No action required since the RefCount copy constructor increments the count
}

// Destructor - The allocated data is automatically deleted when the last RefCount is destroyed
my_string::~my_string() {
    // RefCount's destructor handles deletion
}

// Copy assignment operator
my_string& my_string::operator=(const my_string& s) {
    if (this != &s) { // Protect against self-assignment
        data = s.data; // RefCount's assignment operator handles reference counting
    }
    return *this;
}

// Get character at specified index
char my_string::getChar(const int& i) const {
    // Ensure index is within bounds and `data` is accessed correctly in a const context
    if (i < 0 || static_cast<size_t>(i) >= std::strlen(data.get())) {
        throw std::out_of_range("Index out of bounds");
    }
    return data.get()[i];  // Use get() to safely provide a const char* 
}

// Set character at specified index
void my_string::setChar(const int& i, const char& c) {
    if (i < 0 || static_cast<size_t>(i) >= std::strlen(data.get())) { // Use get() here
        throw std::out_of_range("Index out of bounds");
    }

    // Make sure to modify a copy if this is a shared instance
    if (data.getCount() > 1) {
        size_t length = std::strlen(data.get()); // Use get() here
        char* new_data = new char[length + 1];
        std::strcpy(new_data, data.get()); // Use get() here
        data.decrement(); // Decrement the old reference count
        data = RefCount<char>(new_data); // Assign the new array to RefCount
    }

    data.get()[i] = c; // Set the character at index i, use get() to obtain the non-const pointer
}


// Print the string with its reference count
void my_string::print() const {
    std::cout << data.get() << " [" << data.getCount() << "]" << std::endl;
}
