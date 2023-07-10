## Constructor ##
- Constructor are special class members which are called by the compiler every time when object of that class is instantiated.
- Constructor has the same name as the class name and may defined inside or outside of the class.
- There are four type of constructor
  - Default 
  - Parameterized
  - Copy
  - Move
- It enables the object to initialize itself.
- It invokes automatically when object is created
- A construtor which does not accept any parameter called adefault constructor eg. `A::A()`
- When no Constructor is defined compiler supply `default constructor`.
- There is no return type not even a void so constructor can not return any value.
- They cannot be inherited by derived class
- They cannot be virtual but it can be achieved by `factory method`
- An object with Constructor-destructor cannot be a member of union
- when Constructor is parameterized then we must pass the argument to the constructor when object is created
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

## default constructor ##
- Default constructor is the constructor which does not take any argument, it has no parameter

``` cpp
 class Test{
    int a,b;
    Test(){
        a = 10;
        b = 20;
    }
 }
```
- Compiler creates default constructor implicitly  if its not defined by user

## Parameterized constrctor ##
- It is possible to pass the parameter to a constructor. It can be called explicitly or implicitly
``` cpp
    Example e = Example(0,50); // Explicitly
    Example e(0,50);  // implicitly  
```
- Class can have more than one parameterized constructor this is also called `constructor overloading`
- Parameter of a constructor can be of anytype except that of the class to which it belongs to
- constructor can be defined as an inline function
- Whenever we define one or more non-default constructor i.e parameterized constructor so in that case we also need to define default constructor
- Constructor can be private generally for the `singleton` design patterns
