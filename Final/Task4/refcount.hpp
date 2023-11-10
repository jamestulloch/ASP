#ifndef REF_COUNTED_PTR_HPP
#define REF_COUNTED_PTR_HPP

#include <iostream>

template <typename T>
class RefCountedPtr {
public:
    RefCountedPtr(T* ptr = nullptr) : ptr(ptr), ref_count(new unsigned int(1)) {
        if (ptr == nullptr) {
            *ref_count = 0;
        }
    }

    RefCountedPtr(const RefCountedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        ++(*ref_count);
    }

    RefCountedPtr& operator=(const RefCountedPtr& other) {
        if (this != &other) {
            decrementRefCount();
            ptr = other.ptr;
            ref_count = other.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    ~RefCountedPtr() {
        decrementRefCount();
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    void printRefCount() const {
        std::cout << "[" << *ref_count << "]" << std::endl;
    }

private:
    T* ptr;
    unsigned int* ref_count;

    void decrementRefCount() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }
};

#endif // REF_COUNTED_PTR_HPP
