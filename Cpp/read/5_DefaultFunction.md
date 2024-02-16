## default function ##
- A defaulted function needs to be a special member function eg. default copy constructor, default constructor, default destructor etc. or has no default arguments.
- Non-special member function cannot be defaulted.
- For eg. whenever we declare a parameterized constructor, the compiler will not create default constructor. In such case we can use the default specifier in order to create a default one.
```cpp
class test{
public:
    test(int x){cout << "parameterized constructor" << endl;}
    test() = default;
    ~test() = default;
    test(const test& test);
};

int main(){
    test t1;    //default constructor
    test t2(5); //use parameterized constructor
    return 0;
}
```
- In above case we did not have to specify the body of the constructor test() because by appending the specifer `= default` the compiler will create a default implemenation of this function.
```cpp
class test{
public:
    int test() = default; //error func is not a special function
    test(int,int) = default;  // error it is not a default constructor
    test(int=0) = default; // error it is having argument
};
```

