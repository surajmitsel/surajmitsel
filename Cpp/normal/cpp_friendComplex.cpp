#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload the + operator for complex number addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the += operator for in-place addition
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // Getter functions
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

// Overload the << operator for printing complex numbers
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.getReal() << " + " << c.getImag() << "i";
    return os;
}

int main() {
    Complex a(2.0, 3.0);
    Complex b(1.5, 2.5);

    Complex c = a + b;  // Add two complex numbers using operator overloading
    std::cout << "Result of addition: " << c << std::endl;

    return 0;
}
