## Delete function c++11 ##
- `delete` operator is used in c++11 to disable the uses of a member function this is done by applying `= delete` specifier to the end of the function declaration. Although this is not limited to special function but this is usually done to implicit functions.
```cpp
class test{
    int m;
public: 
    test(int x):m(x) {}
    //delete copy constructor
    test(const test & test ) = delete;

    //delete copy assignment 
    test& operator = (const & test) = delete;
};

int main(){
    test t1(1), t2(2), t3(3);
    t1 = t2;       // error
    t3 = test(t2); //error
    return 0;
}
```
- We can also disable undesirable argument conversion
```cpp
class test{
public:
    test(int x){}
    test(double) = delete;
};
int main(){
    test t1(1);
    test t2(123.6); 
    return 0;
}
// output
// Error as default argument double is desirable for auto conversion
```

```cpp
struct myType{
void * operator new(size_t) = delete;
void * operator new[](size_t) = delete;
};

int main(){
    myType * ptr = new myType; //error attempt to call delete
    return 0;
}
```

