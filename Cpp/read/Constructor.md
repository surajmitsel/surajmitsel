## Constructor ##
- Constructor are specical class members which are called by the compiler every time when object of that class is instantiated.
- Constuctor has the same name as the class name and may defined inside or outside of the class.
- There are four type of constructor
  - Default 
  - Parameterized
  - Copy
  - Move
- It enables the object to initialize itself.
- It invokes automatically when object is created
- A construtor which does not accept any parameter called adefault constructor eg. `A::A()`
- When no constuctor is defined compiler supply `default constructor`.
- There is no return type not even a void so constructor can not return any value.
- They can not be inherited by derived class
- They can not be virtual but it can be achived by `factory method`
- An object with constuctor-destructor can not be a member of union
- when constructor is parameterized then we must pass the argument to the constructor when object is created
- Constructor is a member function of a class which initialize object.

```
                        Constructor
                            |
                            |
  ----------------------------------------------------------
  |                         |                              |
  |                         |                              |
  default              Parameterized                     copy
 className()           classname(param)          classname(const classname&) 

 ```
