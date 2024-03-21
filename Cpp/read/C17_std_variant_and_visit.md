### std::variant 
- It is a C++17 feature that provides a `type-safe union`, allowing you to store values of different types in a single variable. 
- It ensures that only one value is active at a time, preventing undefined behavior often associated with traditional unions. Here's an example demonstrating the usage of std::variant:

```cpp
#include <iostream>
#include <variant>
#include <string>

int main() {
    // Define a variant that can hold either an integer, a double, or a string
    std::variant<int, double, std::string> myVariant;

    // Assigning different types of values to the variant
    myVariant = 42;                     // Assigning an integer
    std::cout << "Value: " << std::get<int>(myVariant) << std::endl;

    myVariant = 3.14;                   // Assigning a double
    std::cout << "Value: " << std::get<double>(myVariant) << std::endl;

    myVariant = "Hello, variant!";    // Assigning a string
    std::cout << "Value: " << std::get<std::string>(myVariant) << std::endl;

    // Accessing the value of the variant using std::visit
    std::visit([](const auto& value) {
        std::cout << "Value: " << value << std::endl;
    }, myVariant);

    //-----------------------------------
    std::variant<int, float> w;
    w = 10;
    try {
        std::get<float>(w); // w contains int, not float: will throw
    }
    catch (const std::bad_variant_access& ex) {
        std::cout << ex.what() << '\n';  // std::get: wrong index for variant
    }

    return 0;
}
/* O/P
Value: 42
Value: 3.14
Value: Hello, variant!
Value: Hello, variant!
*/
```

### std::visit 
- It is a utility function introduced in C++17, designed to work with std::variant. 
- It allows you to apply a callable object (such as a function, function object, or lambda) to the value stored in a std::variant in a type-safe and efficient manner. 
- The benefit of std::visit is that it handles the type checking for you, ensuring that the appropriate operation is performed on the active alternative of the variant.

```cpp
#include <iostream>
#include <variant>
#include <string>

// Define a visitor function object
struct Visitor {
    void operator()(int value) const {
        std::cout << "Integer value: " << value << std::endl;
    }

    void operator()(double value) const {
        std::cout << "Double value: " << value << std::endl;
    }

    void operator()(const std::string& value) const {
        std::cout << "String value: " << value << std::endl;
    }
};

int main() {
    // Define a variant that can hold either an integer, a double, or a string
    std::variant<int, double, std::string> myVariant;

    // Assign different types of values to the variant
    myVariant = 42;
    std::visit(Visitor{}, myVariant);

    myVariant = 3.14;
    std::visit(Visitor{}, myVariant);

    myVariant = "Hello, variant!";
    std::visit(Visitor{}, myVariant);

    return 0;
}
```
