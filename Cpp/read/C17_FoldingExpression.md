
### folding Expression
- A folding expression in C++ is a feature introduced in C++17 
that allows compile-time evaluation of binary operations over a parameter pack. 
It enables concise and expressive code for operations like folding or 
reducing a parameter pack using binary operators.

```cpp
template<typename... Args>
auto sum(Args... args) {
    return (... + args); // Folding expression: adds all arguments together
}

int main() {
    int result = sum(1, 2, 3, 4, 5); // Evaluates to 15
    return 0;
}

```
- In this example, (... + args) is a folding expression that sums up all the arguments in the parameter pack args. It expands to (1 + (2 + (3 + (4 + 5)))), resulting in the sum of all arguments.

```cpp
#include <iostream>

template<typename... Args>
auto product(Args... args) {
    return (... * args); // Folding expression: multiplies all arguments together
}

int main() {
    int result = product(1, 2, 3, 4, 5); // Evaluates to 120 (1 * 2 * 3 * 4 * 5)
    std::cout << "Product: " << result << std::endl;
    return 0;
}

```

### unary right fold:

```cpp
#include <iostream>

template<typename... Args>
auto sum(Args... args) {
    return (args + ...); // Unary right fold: sums all arguments together
}

int main() {
    int result = sum(1, 2, 3, 4, 5); // Evaluates to 15 (1 + (2 + (3 + (4 + 5))))
    std::cout << "Sum: " << result << std::endl;
    return 0;
}

```

### unary left fold:
```cpp
#include <iostream>

template<typename... Args>
auto sum(Args... args) {
    return (... + args); // Unary left fold: sums all arguments together
}

int main() {
    int result = sum(1, 2, 3, 4, 5); // Evaluates to 15 ((1 + 2) + 3) + 4) + 5)
    std::cout << "Sum: " << result << std::endl;
    return 0;
}


```