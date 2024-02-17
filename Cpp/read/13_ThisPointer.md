## this pointer ##
- `this` pointer is a constant pointer that holds the memory address of the current object.
- `this` pointer is passed as a hidden argument to all non-static member function calls and is available as a local variable whithin the body of all non-static function.
- `this` pointer is not available in static member function because static function can be called without any object (with class name)
- friend function will not have reference to `this` pointer
- `delete this` should not be used ideally but if it is used then following point must be remember otherwise the behaviour is undefined. once delete is done then any member should not be accessed.

```cpp
class A{
    public:
    void fun(){
        delete this;
    }
};
int main(){
    // this is valid
    A *ptr = new A();
    ptr->func();
    ptr = null;

    //this is invalid undefined behaviour
    A a;
    a.func();
    
    return 0;
}
```
Following are the situation where `this` pointer is used
- When local variable is having same name as member name.

- When reference to a local object is returned and the returned object is used in `chain-function-call`.

```cpp
class Test{
private:
    int x,y;
public:
    Test(int x=0, int y=0){this->x = x; this->y = y;}
    Test & setX(int a){ x = a; return *this;}
    Test & setY(int b) {y = b; return *this;}
    void print(){cout <<"x:" << x << ", y:" << y << endl;}
};

int main(){
    Test obj1 (5,5);
    obj1.setX(10).setY(20);
    obj1.print();
    return 0;
}
```
- `this` pointer is a pointer accessible only within the non-static member functions of a class, struct or union type. It points to the object for which the member function is called.
- An object `this` pointer is not the part of the object itself it is not reflected in the sizeof() statement on the object. 
- `this` pointer is not used to calculate the size of object but `vptr` is used.
- `this` pointer is not modifiable assignment to this is not allowed.
- When a non-static member function is called for an object the address of the object is passed by a compiler as a hidden argument to the function for eg.

```cpp
mydate.setMonth(3);
// it looks like this
setMonth(&mydate,3);
```
```cpp
/*All the statements are same in function*/
void Date::setMonth(int mn){
    month = mn;
    this->month = mn;
    (*this).month = mn;
}
```
- it is used for returning the reference to the calling object.
```cpp
Test & Test::func(){
    return *this;
}
```
- Type of `this` pointer in C++
    - the type of `this` pointer depends upon function declration
    - if member function of a class X is declared as `const` then type of `this` pointer is `const X*`
    - if the member function is declared as `volatile` then type of `this` pointer is `volatile x *` 
    - if the member function is declared as `const volatile` then type of `this` pointer is `const volatile x *`
    ```cpp
    class X{
        void fun()const{} 
        //OR
        void fun()volatile{}
        //OR
        void fun()const volatile{}
    };
    ```

