## Static in C++ ##
- if we define the data member as static then we must define the member outside of the class because it is stored seperately rather than as a part of an object. But static method can be defined inside the class.

```cpp
class Item{
    static int count;
    int mumber;
public:
    static void getCount();
    void int getNum();
};
int item::count=0;
```
- It is called by the class name instead of its object.
```cpp
classname::functionName();
```
- Static member function is not having implicit `this` argument.
- They cannot have same name as non static member function is have with same arguments.
- Static member function supports function overlaoding with other static function not with normal member functions
- Static member function cannot be delcared as virtual.
- Static member function does not support overridding of function.
- It is used in singleton, factory, abstract factory design patterns.
- Static member function can access only static variables it can not access non static variable of a class. However non-static member function can access both static and non static member functions.
- Every object has its own copy of non static member variable, since static member function does not know about object so it is impossible for a static function to know on which class object or class instance it is being called. So because of this whenever we try to call non-static variable from a static function the compiler gives error.


```cpp
class Item{
    static int count;
    int number;
public:
    //static int getCount(const int a){return count;}; //--1
    static int getCount(const int* a){return count;}; //--2
    
    static string getname(int a, int b){return "first";}; //--3
    static string getname(int a, char b){return "second";}; //--4

    static int getCount(const int* a){return count;}; 

    //static int my_func() const {return 10;}; ---- 5

    int getCount(int a){return 30;}
    int getNum(){return 20;};
};
int Item::count=10;

int main(){
    int *x;
    cout << Item::getCount(&x);
}
// line 3,4 static function overloading is allowed
// line 5 gives error: error: static member function cannot have 'const' qualifier
// if line 1 is enabled then it is not allowed
// error: static and non-static member functions with the same parameter types cannot be overloaded
```

```cpp
class empty{
    static int i;
};

static int empty:: i = 0;
int main(){
    sizeof(empty); //1 becaue static is not considered as part of class object
}
```
- Overloaded new and delete oprator function are by default static member functions. Therefore they cannot have access to `this` pointer.
- static member function cannot be virtual and const and volatile. It gives compilation error.
- static member function does not support overloading and overriding.
- c++ class can have an object of self type if the object is static or else it will be error for non-static object of the class can contain the pointer only.

```cpp
class test{
    static test self; // this is ok
};

class test{
    test self;  // this is not ok
};

class test{
    test *self; // this is ok
};
```

