#include <iostream>

// Template class for the array iterator
template<typename T>
class ArrayIterator {
private:
    T* ptr; // Internal pointer to the current element
public:
    // Constructor
    ArrayIterator(T* p) : ptr(p) {}

    // Dereferencing operator
    T& operator*() const { return *ptr; }

    // Increment operator (prefix)
    ArrayIterator& operator++() {
        ++ptr;
        return *this;
    }

    // Equality comparison operator
    bool operator==(const ArrayIterator& other) const {
        return ptr == other.ptr;
    }

    // Inequality comparison operator
    bool operator!=(const ArrayIterator& other) const {
        return !(*this == other);
    }
};

int main() {
    // Example array
    int arr[] = {1, 2, 3, 4, 5};

    // Create iterators for the beginning and end of the array
    ArrayIterator<int> beginIter(arr);
    ArrayIterator<int> endIter(arr + 5); // One past the end

    // Iterate over the array using the iterators
    for (ArrayIterator<int> it = beginIter; it != endIter; ++it) {
        std::cout << *it << " "; // Print each element
    }
    std::cout << std::endl;

    return 0;
}
