### Tupple
- std::tuple is a part of the C++ Standard Library and was introduced in C++11.

- std::tuple is a template class that allows you to store a fixed-size collection of heterogeneous values. Each value in the tuple can have a different type. It's similar to a struct or a class, but it doesn't have named members. Instead, you access the elements of a tuple using their index.


```cpp
#include <iostream>
#include <tuple>
#include <string>

int main() {
    // Creating a tuple with an integer, a double, and a string
    std::tuple<int, double, std::string> myTuple(42, 3.14, "Hello");

    // Accessing elements of the tuple using std::get
    int intValue = std::get<0>(myTuple);
    double doubleValue = std::get<1>(myTuple);
    std::string stringValue = std::get<2>(myTuple);

    std::cout << "Values: " << intValue << ", " << doubleValue << ", " << stringValue << std::endl;

    return 0;
}

```