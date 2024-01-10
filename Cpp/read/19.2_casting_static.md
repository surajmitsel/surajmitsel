## static_cast ##
- This is used for normal/ ordinary type conversion
- This is also the cast responsible for implicit conversion and can also be called explicitly
- You should use in case like converting `float to int` `char to int` etc.
- It is compile time type casting and does strict type checking.
- static_cast can perform conversion b/w pointers to related class.
- static_cast cannot cast away `const` or `volatile`

```cpp
// Example 1
int main(){
    float f = 3.5;
    int a = f; // this is what you do in `c`
    int b = static_cast<int> (f); // this is how we need to do in c++
    cout << b; // 3
    return 0;
}

// Example 2
int main(){
    int a = 10;
    char c = 'a';

    int * ptr1 = (int*) & c; // This passes at compile time but may fail at runtime
    int * ptr2 = static_cast<int*> (&c); // Compile error
    return 0;
}
``` 
- If you compile the code you will get an error: `invalid static_cast from char* to int*` So this means even somehow you type cast a particular object into another but it’s illegal then static_cast will not allow you to do this.

### conversion operator ###
```cpp
class Integer{
    int x;
public:
    Integer(int x_in = 0) : x(x_in){
        cout <<"coversion constructor" << endl;
    }

    //conversion operator for string (int to string)
    operator string(){
        cout << "conversion operator" << endl;
        return to_string(x);
    }
};

int main(){
    Integer obj(3);     // conversion constructor
    string str1 = obj;  // conversion operator
    obj = 30;           // conversion constructor
    string str2 = static_cast<string>(obj);  // conversion operator
    obj = static_cast<Integer>(50);          // conversion constructor
    return 0;
}
```
### Example ##
- use static_cast to and from `void *`
```cpp
int main(){
    int i = 0;
    void * v = static_cast <void *>(& i);
    int * ip = static_cast <int *> (v);
    return 0;
}
```
- Derived class to base class conversion: the below code will compile without error
but line (2) static_cast do tight checking.
```cpp
class Base{};
class Derived:public Base{}; // public inheritance

int main(){
    Derived d1;
    Base * b1 = (Base*) &d1; // (1) allowed
    Base * b2 = static_cast<Base*>(*d1); // (2) allowed by checking
    return 0;
}
```
- Now if we change the code slightly then static_cast gives the error. Line 2 gives error `Base is an inaccessible base to derived`.
```cpp
class Base{};
class Derived:private Base{}; // private Or protected not public inheritance

int main(){
    Derived d1;
    Base * b1 = (Base*) &d1; // (1) allowed
    Base * b2 = static_cast<Base*>(*d1); // (2) error
    return 0;
}
```

- No checks are performed during runtime to guarantee to the object being converted is infect a full object of the destination type. Therefore its up to the programmer to ensure that the conversion is safe. On the other side it does not incur the overhead of the type safely check of `dynamic_cast`.
```cpp
class Base{};
class Derived:public Base{}; // private Or protected not public inheritance
Base * a = new Base;
Derived * b = static_cast<Derived *> (a);    
// base class pointer is converted to derived class pointer
```
- This would be valid code although it would point to an incomplete object and it can lead to runtime error.

### Aditionally static_cast can also perform the following ###
- Explicitly call a single-argument constructor or a conversion operator.
- Convert to `r-value` references.
- Convert enum class value into integer or floating point values.
- Convert any type to void, evaluating and discarding the value.