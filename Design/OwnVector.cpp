#include <iostream>
#include <stdexcept>

template<typename T>
class MyVector {
private:
    T* data{nullptr};
    size_t capacity{0};
    size_t size{0};

public:
    // Constructor
    MyVector() : data(nullptr), capacity(0), size(0) {}

    // Destructor
    ~MyVector() {
        delete[] data;
    }

    // Copy constructor
    MyVector(const MyVector& other) : capacity(other.capacity), size(other.size) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment operator
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data; // delete old data
            capacity = other.capacity;
            size = other.size;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Push back
    void push_back(const T& value) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }

    // Pop back
    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        --size;
    }

    // Size
    size_t getSize() const {
        return size;
    }

    // Capacity
    size_t getCapacity() const {
        return capacity;
    }

    // Operator[]
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

private:
    // Resize
    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
};

int main() {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Size: " << vec.getSize() << std::endl; // Output: Size: 3
    std::cout << "Capacity: " << vec.getCapacity() << std::endl; // Output: Capacity: 4

    vec.pop_back();
    std::cout << "Size after pop_back(): " << vec.getSize() << std::endl; // Output: Size after pop_back(): 2

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl; // Output: Vector elements: 1 2

    return 0;
}
