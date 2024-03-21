### std::optional

- In C++, optional variables provide a way to represent values that may or may not be present. 
- This is particularly useful when dealing with situations where a value might be missing or undefined. 
- The std::optional template, introduced in C++17, allows you to wrap a value and indicate whether it's valid or not.
- Here's a basic example demonstrating the usage of std::optional:

```cpp
#include <iostream>
#include <optional>

std::optional<int> getValue(bool present) {
    if (present) {
        return 42;
    } else {
        return std::nullopt; // Indicates absence of value
    }
}

int main() {
    std::optional<int> value = getValue(true);

    if (value.has_value()) { // Check if value is present
        std::cout << "Value is present: " << value.value() << std::endl;
    } else {
        std::cout << "Value is not present" << std::endl;
    }

    // Accessing value directly (unsafe, may cause undefined behavior if value is not present)
    // int val = value.value(); 

    return 0;
}

```

In this example:

- getValue function returns an std::optional<int> containing the value 42 if present is true, otherwise, it returns an empty optional (std::nullopt).
- has_value() method is used to check whether the optional contains a value.
- value() method is used to access the value stored in the optional. It should be used only after ensuring that the optional contains a value (by using has_value()), otherwise, it results in undefined behavior. Alternatively, you can use value_or() method to provide a default value if the optional is empty.
- You can also directly assign an optional to std::nullopt to indicate that it doesn't contain a value.
- `std::optional `provides a safer and more expressive alternative to using pointers or sentinel values to represent optional values in C++. It avoids the pitfalls associated with null pointers and provides a clear indication of the absence of a value.