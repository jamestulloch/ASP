#include <iostream>
#include <cstring>
using namespace std;

class my_string {
private:
    char* data;
    mutable unsigned int* ref_count; // mutable allows modification in const functions
public:
    // Default Constructor
    my_string() : data(nullptr), ref_count(new unsigned int(1)) {}

    // Parameterized Constructor
    my_string(const char* str) : ref_count(new unsigned int(1)) {
        if (str) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = nullptr;
        }
    }

    // Copy Constructor
    my_string(my_string const& s) : data(s.data), ref_count(s.ref_count) {
        ++(*ref_count);
    }

    // Copy Assignment Operator
    my_string& operator=(my_string const& s) {
        if (this != &s) { // prevent self-assignment
            --(*ref_count);
            if (*ref_count == 0) {
                delete[] data;
                delete ref_count;
            }
            data = s.data;
            ref_count = s.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    // Destructor
    ~my_string() {
        if (--(*ref_count) == 0) {
            cout << "Reference count is now 0, freeing memory." << endl;
            delete[] data;
            delete ref_count;
        }
    }

    // Access a character
    char getChar(const int& i) const {
        if (i >= 0 && i < strlen(data)) {
            return data[i];
        } else {
            return '\0'; // return null character for out-of-bounds access
        }
    }

    // Modify a character
    void setChar(const int& i, const char& c) {
        if (i >= 0 && i < strlen(data)) {
            if (*ref_count > 1) {
                --(*ref_count);
                data = strdup(data); // copy-on-write
                ref_count = new unsigned int(1);
            }
            data[i] = c;
        }
    }

    // Get reference count
    unsigned int getRefCount() const {
        return (ref_count) ? (*ref_count) : 0;
    }

    void decreaseRefCount() {
        if (ref_count && --(*ref_count) == 0) {
            delete[] data;
            delete ref_count;
            data = nullptr;
            ref_count = nullptr;
            cout << "Reference count is now 0, freeing memory." << endl;
        }
    }

    // Print the string
    void print() const {
        if (data) {
            cout << data << " [" << getRefCount() << "]" << endl;
        }
    }
};

// Reference OPENAI CHATGPT, 2023.  ChatGPT response to James Tulloch, (personal communication, 1st November)
