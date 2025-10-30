#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#include <iostream>
#include <cstring>

// my_string class declaration
class my_string {
private:
    char* data; // The data pointer for the string's characters
    int* reference_count; // The pointer to this string's reference count

public:
    // Constructors
    my_string(); // Default constructor
    my_string(const char* str); // Parameterized constructor for C-string
    my_string(const my_string& s); // Copy constructor

    // Destructor
    ~my_string();

    // Operators
    my_string& operator=(const my_string& s); // Copy assignment operator

    // Utility functions
    char getChar(const int& i) const; // Get a character at a given index
    void setChar(const int& i, const char& c); // Set a character at a given index
    void print() const; // Print the string
};

#endif // MY_STRING_HPP

// Reference OPENAI CHATGPT, 2023.  ChatGPT response to James Tulloch, (personal communication, 1st November)
