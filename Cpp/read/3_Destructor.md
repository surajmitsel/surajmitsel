## Destructor ##
- Destructor is a member function which destructs or delete an object.
- When is it called 
    - It is called automatically when the object goes out of scope.
    - The function ends.
    - The program ends.
    - A block containing local variable ends.
    - A delete operator is called.
- Destructor have same name as the class preceded by a tilde (~)
- There is only one destructor is allowed in the class so no destructor overloading is allowed.
- No return value and no parameter and overloading.
- If we do not write our own destructor in class then compiler creates default destructor for us. The default destructor works fine unless we have dynamically allocated memory or pointer in class.
- When a class contains a pointer to memory allocated in class the we should write a destructor to release memory before the class instance is destroyed. This must be done to avoid memory leak.

## Virtual destructor ##
- Destructor cannot be virtual but constructor can be, infect its good idea to make destructor virtual in base class when we have virtual function in class.
- Deleting a derived class object using a pointer to base class that has a non-virtual destructor results in undefined behaviour base class should be defined with virtual destructor.
- Making base class destructor virtual guarantees that the object of derived class is destructed properly i.e. both base class and derived class destructor are called in reverse order.
- Virtual destructor are used for the same purpose as virtual functions,
when you remove an object of subclass which is referenced by parent class pointer only destructor of base class will executed buf if the destructor is defined with the keyword virtual and both the destrcutor will be invoked in reverse order of inheritance.
```cpp
class Base{
    public:
    ~Base(){};  // In this case base class destructor is not called
};

class Base{
    public:
    ~virtual Base(){}; // In this case base class destructor is called
};

class Derived:public Base{
    public:
    ~ Derived(){}
};
```
## Pure virtual destructor ##
- Yes it's possible to have pure virtual destructor, one of the most important thing to remember is that if a class contains a pure virtual destructor then it must provide a function body for the pure virtual destructor.
- You may be wondering why pure virtual destructor required function body.
The reason is because destructor (unlike other function) not really overridden rather than they are always called in the reverse order of the inheritence. So if the definition of the pure virtual function is not provided then what function body will be called during destruction ?
Therefore the compiler and linker enforce the existance of a function body for pure virtual destructors.

```cpp
class Base{
    public:
        virtual ~ Base()=0;
};

Base :: ~Base(){
    // the linker will give error if this function not defined
    // undefined reference to Base::~Base()
    std::cout << "pure virtual destrcutor" <<endl;
}
class Derived:public Base{
    public:
        ~Derived(){
            std::cout << "Destructor called" <<endl;
        }
};
int main(){
    Base * b = new Derived();
    delete b;
    return 0;
}
```
- Its important to not that the class becomes abstract class because it contains pure virtual function.
- Its possbile to call the constructor and destructor explicitly
```cpp
class Test{
    public:
        Test(){cout <<"constructor";}
        ~Test(){cout <<"destructor";}
}
int main(){
    Test(); //explicit call to constructor
    Test t;
    t.~Test(); // explicit call to destructor
    return 0;
}
```
```
contructor
constructor
destructor
destructor
```

