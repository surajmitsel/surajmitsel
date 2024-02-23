#include <iostream>
#include <string>

// Abstract Product
class Product {
public:
    virtual void use() const = 0;
};

// Concrete Products
class ConcreteProductA : public Product {
public:
    void use() const override {
        std::cout << "Using Concrete Product A" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() const override {
        std::cout << "Using Concrete Product B" << std::endl;
    }
};

// Abstract Factory
class Factory {
public:
    virtual Product* createProduct() const = 0;
};

// Concrete Factories
class ConcreteFactoryA : public Factory {
public:
    Product* createProduct() const override {
        return new ConcreteProductA();
    }
};

class ConcreteFactoryB : public Factory {
public:
    Product* createProduct() const override {
        return new ConcreteProductB();
    }
};

int main() {
    // Create a factory
    Factory* factoryA = new ConcreteFactoryA();
    Factory* factoryB = new ConcreteFactoryB();

    // Use products created by factory A
    Product* productA = factoryA->createProduct();
    productA->use();

    // Use products created by factory B
    Product* productB = factoryB->createProduct();
    productB->use();

    delete factoryA;
    delete factoryB;
    delete productA;
    delete productB;

    return 0;
}
