## Destructor ##
- Destructor is a member function which destructs or delete an object.
- When is it called 
    - It is called automatically when the object goes out of scope.
    - The function ends.
    - The program ends.
    - A block containing local variable ends.
    - A delete operator is called.
- Destructor have same name as the class precoded by a tilde (~)
- There is only one destructor is allowed in the class so no destructor overlaoding is allowed.
- No return value and no parameter and overlaoding.
- If we do not write our own destructor in class then compiler creates default destructor for us. The default destructor works fine unless we have dynamically allocated memory or pointer in class.
- When a class contains a pointer to memory allocated in class the we should write a destrcutor to release memory before the class instance is destroyed. This must be done to avoid memory leak.

## Virtual destructor ##
- Destructor can not be virtual but constructor can not be, infact its good idea to make destructor vitual in base class when we have virtual function in class.
- Deleting a derived class object using a pointer to base class that has a non-virtual destructor results in undefined behaviour base class should be defined with virtual destructor.
- Making base class destructor virtual guarantees that the object of derived class is destructed properly i.e. both base class and derived class destructor are called in reverse order.


