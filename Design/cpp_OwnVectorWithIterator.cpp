#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    // Iterator class
    class Iterator {
    private:
        T* ptr;

    public:
        Iterator(T* p) : ptr(p) {}

        // Overload operators for iterator
        T& operator*() const { return *ptr; }
        Iterator& operator++() { ++ptr; return *this; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    // Constructor
    MyVector() : data(nullptr), size(0), capacity(0) {}

    // Destructor
    ~MyVector() { delete[] data; }

    // Iterator methods
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }

    // Other methods
    void push_back(const T& value) {
        if (size >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }

    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }

    // Reserve memory
    void reserve(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        capacity = newCapacity;
        delete[] data;
        data = newData;
    }

    // Access operator
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

int main() {
    MyVector<int> vec;
    
    // Push elements into the vector
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    // Iterate through the vector using iterator
    std::cout << "Vector elements: ";
    for (MyVector<int>::Iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
