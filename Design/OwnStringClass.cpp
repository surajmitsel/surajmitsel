#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;
    size_t length;

public:
    // Iterator class
    class iterator {
    private:
        char* ptr;

    public:
        iterator(char* p) : ptr(p) {}

        char& operator*() const {
            return *ptr;
        }

        iterator& operator++() {
            ++ptr;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++ptr;
            return temp;
        }

        bool operator==(const iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const iterator& other) const {
            return ptr != other.ptr;
        }
    };

    // Default constructor
    MyString() : data(nullptr), length(0) {}

    // Constructor with char array
    MyString(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    // Destructor
    ~MyString() {
        delete[] data;
        data = nullptr;
    }

    // Copy constructor
    MyString(const MyString& other) : length(other.length) {
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Copy assignment operator
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Move constructor
    MyString(MyString&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    // Move assignment operator
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }

    // Method to get the length of the string
    size_t size() const {
        return length;
    }

    // Method to check if the string is empty
    bool empty() const {
        return length == 0;
    }

    // Method to get C-style string
    const char* c_str() const {
        return data;
    }

    // Method to get begin iterator
    iterator begin() {
        return iterator(data);
    }

    // Method to get end iterator
    iterator end() {
        return iterator(data + length);
    }

    // Overloaded + operator for concatenation
    MyString operator+(const MyString& other) const {
        MyString result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    // Overloaded += operator for concatenation
    MyString& operator+=(const MyString& other) {
        char* temp = new char[length + other.length + 1];
        strcpy(temp, data);
        strcat(temp, other.data);
        delete[] data;
        data = temp;
        length += other.length;
        return *this;
    }

    // Overloaded [] operator for accessing characters
    char& operator[](size_t index) {
        return data[index];
    }

    // Overloaded [] operator for accessing characters (const version)
    const char& operator[](size_t index) const {
        return data[index];
    }

    // Method to clear the string
    void clear() {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    // Method to extract a substring from the string
    MyString substr(size_t pos, size_t len) const {
        if (pos > length)
            throw std::out_of_range("pos is out of range");
        return MyString(data + pos, len);
    }

private:
    // Constructor with char array and length
    MyString(const char* str, size_t len) : length(len) {
        data = new char[length + 1];
        strncpy(data, str, len);
        data[len] = '\0';
    }
};

int main() {
    MyString str("Hello, World!");

    // Iterate over the characters using iterators
    std::cout << "Characters of the string:" << std::endl;
    for (auto it = str.begin(); it != str.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
