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
- A constructor which does not accept any parameter called a default constructor eg. `A::A()`
- When no Constructor is defined compiler supply `default constructor`.
- There is no return type not even a void so constructor cannot return any value.
- They cannot be inherited by derived class
- An object with Constructor-destructor cannot be a member of union
- when Constructor is parameterized then we must pass the argument to the constructor when object is created
- Constructor is a member function of a class which initialize object.
- Constructor cannot be `virtual` because at the time when the constructor is invoked the `virtual table` may not be available in the memory.
- The concept of `virtual constructor` can be achieved by `factory method` pattern.
- Constructor cannot be `static` because it's an member function to a class but `static` functions are not part of the class.
- Constructor can be a `friend function` to other class 
- You can declare constructor as `protected` or `private`.
- It can be declare as `inline`, `explicit`, `friend` or `constexpr`. 

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

## Default constructor ##
- Default constructor is the constructor which does not take any argument, it has no parameter.

``` cpp
 class Test{
    int a,b;
    Test(){
        a = 10;
        b = 20;
    }
 }
```
- Compiler creates default constructor implicitly  if its not defined by user.

## Parameterized constructor ##
- It is possible to pass the parameter to a constructor. It can be called explicitly or implicitly.
``` cpp
    Example e = Example(0,50); // Explicitly
    Example e(0,50);  // implicitly  
```
- Class can have more than one parameterized constructor this is also called `constructor overloading`.
- Parameter of a constructor can be of any type except that of the class to which it belongs to.
- constructor can be defined as an inline function.
- Whenever we define one or more non-default constructor i.e parameterized constructor so in that case we also need to define default constructor.
- Constructor can be private generally for the `singleton` design patterns.


## Copy constructor ##
- A Copy constructor is a member function which initialize an object using another object of the same class.

``` cpp
    ClassName (const ClassName& obj);
    A(const A&);
```
- Constructor can expect a reference of its own class as a parameter in such case it is called a copy constructor.

``` cpp
class student{
    private:

    public:
        student(student); // invalid
        student(const student &); //valid
}
```
``` cpp
class Integer{
    int m,n;
    public:
        Integer(){m=0;n=0;}
        Integer(int a, int b){ m = a; n = b;}
        Integer(Integer & x) {m = x.a; n= x.b;}
}
int main(){
    Integer I;          // invoke constructor 1
    Integer I(20,40);   // invoke constructor 2
    Integer K(I);       // invoke copy constructor
    Integer L = K;      // invoke copy constructor
}
```
### When copy constructor is called ###
- When we do not define copy constructor compiler create a default copy constructor and which does member wise copy of between objects
- When object of the class is passed by value to a function.
- When object is constructed based on another object of the same class.
- When compiler generates temporary objects.
- It's not guaranteed that a copy constructor will be called in all these cases bcz the c++ standard compiler also optimize the code for eg. return value.

### When is user defined copy constructor is needed ###
- When we do not define copy constructor compiler create a default copy constructor and which does member wise copy of between objects.
- The compiler created copy constructor works fine in general.
- We need not to define our own copy constructor only if the object has pointers or any runtime allocation of the resources like file handler, n/w resources etc.
- Default copy constructor does only `shallow copy`.
- `Deep copy` is possible only with user defined copy constructor so that we can make sure the pointer or references can point to new memory location.

## Move Constructor ##
- `c++11` defines two new function to serve `move semantic` a move constructor and move assignment operator. 
- Whereas the goal of copy constructor or copy assignment operator is to make a copy of the one object to other object.
- The goal of move constructor and move assignment is to `move the ownership` of the resource from one object to another object, which is much less expensive then making a copy.
- Whereas copy flavour of these function take a `const l-value reference`, and move flavour if these function takes a `non-const r-value reference`
- It does not allocate new resources instead it `pilfer` new resource with the old resource and it sets old resource to default state.

``` cpp
    // Move
    className(className &&); // non const r-value reference
    // Move assignemt
    className& operator=(className &&); // non const r-value reference

    // copy
    className(const className &); // const l-value reference

    // copy assignment
    className& operator=(const className &); // const l-value reference
```
- A move constructor allows the resources owned by an `r-value` object to be moved into an `l-value` without creating its copy.
- An `r-value` is an expression which dose not have any memory address and `l-value` is an expression with a memory address
- A move constructor can be called explicitly with the `move()` function for already create object

```cpp
    class memoryPage{
        size_t size{0};
        char *buf{nullptr};
        
        public:
            explicit memoryPage(int size = 512){
                size = sz;
                buf = new char[size];
            }
            memoryPage(memoryPage&&); // move 
            memoryPage& operator = (memoryPage &&); // move assignment
    };
    memoryPage::memoryPage(memoryPage && other){
        this->size = other.size;
        this->buf = other.buf;

        other.size = 0;    //reset
        other.buf = nullptr;
    }

    memoryPage& memoryPage::operator= (memoryPage && other){
        if(this != other){
            delete[] buf;

            this->size = other.size;
            this->buf = other.  ;

            other.size = 0;    //reset
            other.buf = nullptr;
        }
        return *this;
    }
```

### Performance improvement with move ###
```cpp
class Test{
    int *ptr;
    public:
    Test(){
        cout << "default constructor" << endl;
        ptr = new int;    
    }
    Test(const Test& obj){ 
        this->ptr = new int;
        cout << "copy constructor" << endl;
    }
    ~Test(){
        delete ptr;
    }
    Test(Test && obj){
        // it will simply sift the resources without creating a copy
        cout << "move constructor" <<endl;
        this->ptr = obj.ptr;
        obj.ptr = nullptr;
    }
};
int main(){
    vector<Test> vec;
    vec.push_back(Test());
    return 0;
}
```
- Now when the above code is executed the default constructor is called at the time that the temporary object of Test is pushed back in the vector.
- So in above code there is a serious performance overhead as temporary object Test is created first then its copied using copy constructor, which can be solve using move without performance overhead. So for a large number of push_back() statement better to use move constructor.

## explicit keyword for constructor ##
- It tells compiler that a certain constructor many not be used to implicitly case an expression to its class Type.
- The explicit keyword is an optional declaration for constructor that takes exactly `one argument`.
- It only applies to single argument constructor since those are the constructor can be used in type casting.

``` cpp
    class foo{
        public: 
            foo(int x);
    };

    class bar{
        public:
        bar(double x);
    };
    
    int main()
    {
        // all of these will be calling foo::foo(int);
        foo a = 42;
        foo b(42);
        foo c = foo(42);
        foo d = (foo) 42;

        // all of these will be calling bar::bar(double);
        bar x = 3.14;
        bar y(3.14);
        bar z = bar(3.14);
        bar w = (bar) 3.14;
    }
```
- But sometime we want to prevent this sort of implicit parameter or implicit type conversion

```cpp
    class foo{
        public:
        explicit foo(int x);
    };

    class bar{
        public:
        explicit bar(double x);
    };

    int main() {
        foo a = 42;         // compiler error
        foo b(42);          // calls foo::foo(int)
        foo c = foo(42);    // calls foo::foo(int)

        bar x = 3.14;       // compiler error
        bar y(3.14);        // calls bar::bar(double)
        bar z = bar(3.14);  // calls bar::bar(double)
    }
```
- You can mix explicit and non-explicit constructor in same class

```cpp
    class foo{
        public:
            foo(double x);
            explicit foo (bool x);
    };

    void yourCode() {
        foo a = true;      // calls foo(double x)
        foo b = foo(true); // calls foo (bool x)
    }
```

## Constructor delegation ##
- Sometime it is useful for a constructor to be able to call another constructor of the same class this feature is called a constructor delegation it was introduce in `c++11`.
``` cpp
    // Example without delegation
    class A{
        private:
            int x,y,z;
        public:
            A(){
                x = y = z = 0;
            }
            A(int z) {
                x = y = 0;
                this z = z;
            }
            void show(){
                std::cout << x << "," << y << "," << z << endl;
            }
        };

    int main(){
        A obj(3);
        obj.show();
        return 0;
    }

    // Example with delegation
    class A{
        private:
            int x,y,z;
        public:
            A(){
                x = y = z = 0;
            }
            A(int z):A() {  // delegation
                this->z = z;
            }
            void show(){
                std::cout << x << "," << y << "," << z << endl;
            }
        };

    int main(){
        A obj(3);
        obj.show();
        return 0;
    }
```

## Constructor initialization list ##
- Initialization list is used to initialize the data member of class.

```cpp
class Point{
    private:
    int x,y;
    public:
    Point(int i=0, int j=0):x(i),y(j){}
    int getX()const{return x;}
    int getY()const{return y;}
};

int main(){
    Point t1(10,15);
    cout << "x = " << t1.getX() << endl;
    cout << "y = " << t1.getY() << endl;
    return 0;
}
```
In the following situation we must do the initialization of data member using initializer list
- For initialization of non-static const data members.
- For initializtion of reference members.
```cpp
class Test{
    const int x; // const member
    int & y;     // reference member

    public:
        Test(int m, int &n): x(m),y(n){} // initializer
        int getX()const {return x;}
        int getY()const {return y;}
}
```
- For initialization of member object which does not have default constructor.
- Like above point, parameterized constructor of a base class can only be called using initializer list.
```cpp
class Test{
    int i;
public:
    Test(int x) {i = x;}
};

class drv:public Test{
    int j;
public:
    drv::dev(int y) : Test(y){
        j = y;
    }
};
```
- When constructor parameter is having same name as data members or else `this` pointer is required to initialize data member.
- For better performance reasons.

```cpp
class Test{
    // Type is already a class which is having its own constructor and operator
    Type var;
    public:
        Test(Type a){
            var = a;
        }
};
```
- Here compiler follows steps to create an object of type Test
    - Type object constructor is called first for `a`
    - The assignment operator `Type` is called inside body of Test() constructor to assign
    - And then finally destructor of `Type` is called for `a` since it goes out of scope.
    - 3 calls[Constructor + destructor + assignment operator]

```cpp
//with initialization list
class Test{
    Type var;
public:
    Test(Type a): var(a){}
};
```
- The copy constructor of `Type` class is called to initialize variable `a`
- 2 calls [copy constructor + destructor] 





