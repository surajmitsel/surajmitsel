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
- Static member function cannot be delcared as virtual.
- Static member function does not support overloading and overridding of function.
- It is used in singleton, factory, abstract factory design patterns.
- Static member function can access only static variables it can not access non static variable of a class. However non-static member function can access both static and non static member functions.
- Every object has it own copy of non static member variable, since static member function does not know about object so it is impossible for a static function to know on which class object or class instance it is being called. So because of this whenever we try to call non-static variable from a static function the compiler gives error.

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

