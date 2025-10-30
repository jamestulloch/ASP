#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#include "refcount.hpp"
#include <iostream>
#include <cstring>

class my_string {
private:
    RefCount<char> data; // Use RefCount to manage the char array

public:
    // Constructors
    my_string(); // Default constructor
    my_string(const char* str); // Constructor from C-style string
    my_string(const my_string& s); // Copy constructor

    // Destructor
    ~my_string();

    // Operators
    my_string& operator=(const my_string& s); // Copy assignment operator

    // Utility functions
    char getChar(const int& i) const; // Get a character at a given index
    void setChar(const int& i, const char& c); // Set a character at a given index
    void print() const; // Print the string with reference count
};

#endif // MY_STRING_HPP
// Reference OPENAI CHATGPT, 2023.  ChatGPT response to James Tulloch, (personal communication, 6th November)
