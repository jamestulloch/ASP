#ifndef REF_COUNT_HPP
#define REF_COUNT_HPP

#include <cstddef> // For size_t type

template <typename T>
class RefCount {
private:
    T* object;          // Pointer to the object or array being managed
    size_t* count;      // Pointer to the reference count

public:
    // Constructor
    explicit RefCount(T* obj = nullptr) : object(obj), count(new size_t(1)) {
        // The constructor is initializing the count to 1
    }

    // Copy constructor
    RefCount(const RefCount& other) : object(other.object), count(other.count) {
        // Increment the reference count for the new reference
        ++(*count);
    }

    // Destructor
     void decrement() {
        if (--(*count) == 0) {
            delete[] object;
            delete count;
        }
    }

    // Copy assignment operator
    RefCount& operator=(const RefCount& other) {
        if (this != &other) {
            // Decrement the current reference count and delete if it's the last reference
            if (--(*count) == 0) {
                delete[] object; // Use delete[] because we are managing an array
                delete count;
            }
            // Assign the new object and count
            object = other.object;
            count = other.count;
            ++(*count); // Increment the reference count
        }
        return *this;
    }

    // Access the underlying object
    T& operator[](size_t index) const {
        return object[index];
    }

    // Get the current reference count
    size_t getCount() const {
        return *count;
    }
    T* get() {
        return object; // Return as non-const T* to allow modifications
    }
    const T* get() const {
        return object;  // Return as const T* to ensure the data cannot be modified
    }
     
};

#endif // REF_COUNT_HPP
