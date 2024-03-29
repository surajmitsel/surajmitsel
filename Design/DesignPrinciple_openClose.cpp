#include <iostream>
#include <vector>

/*

The Open-Closed Principle (OCP) states that software entities (classes, modules, functions, etc.) 
should be open for extension but closed for modification. 
This means that you should be able to extend the behavior of a class without modifying its source code.

In this example, the Shape class is an abstract base class representing a geometric shape. 
It has a pure virtual function area() which must be overridden by derived classes. 
The Rectangle and Circle classes are concrete implementations of Shape.

The totalArea() function calculates the total area of a collection of shapes without needing 
to modify its implementation when new shapes are added. 
This demonstrates the Open-Closed Principle because the function is open for extension 
(new shapes can be added) but closed for modification (the function's code does not need to change).
*/

// Abstract base class representing a shape
class Shape {
public:
    virtual double area() const = 0;
};

// Concrete implementation of Shape representing a rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

// Concrete implementation of Shape representing a circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }
};

// Function to calculate the total area of shapes
double totalArea(const std::vector<Shape*>& shapes) {
    double total = 0;
    for (const auto& shape : shapes) {
        total += shape->area();
    }
    return total;
}

int main() {
    Rectangle r(5, 4);
    Circle c(3);

    std::vector<Shape*> shapes = {&r, &c};

    std::cout << "Total area: " << totalArea(shapes) << std::endl;

    return 0;
}