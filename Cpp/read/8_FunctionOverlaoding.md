## Function Overlaoding ##
- It is a function in c++ where two or more function can have the same name but different parameters
- Function overloading can be considered as an example of polymorphism feature c++.

```cpp
void print(int i){
    cout << "this is int" << i << endl;
}

void print(float f){
    cout << "this is float" << f << endl;
}

void print(char const * c){
    cout << "this is const char *"<< endl;
}

int main(){
    print(10);
    print(10.10);
    print("ten");
    return 0;
}
```
```cpp
this is int 10
this is float 10.10
this is char* ten
```
- The definition of the function must differ from each other by types or by number of arguments in the argument list.
- You cannot overload function which differ only by return type.
- So for overloading function it should follow
    - Parameter types
    - Number of parameters
    - Order of parameters
    - return type + (any of the above)
- return type alone is not sufficient for function overloading in that case compiler give error 
but in case of if its overloaded based on const type then it is allows to have same parames and return type.

## Const Overloading ##
- C++ allows member methods to be overloaded on the basis if const type.
- Overloading on the basis of const type can be useful when a function return reference or pointer.
- We can make one function const that returns a const reference or const pointer other non-const function that returns non-const reference or pointer
```cpp
class Test{
protected:
    int x;
public:
    Test(int i):x(i){}
    void func() const{
        cout << "function const is called" << endl;
    }

    void func(){
        cout << "function non-const is called" << endl;
    }
};
int main(){
    Test t1(10);
    const Test t2(20);

    t1.func(); // o/p function non-const is called
    t2.func();// o/p function const is called
    return 0;
}
```
- Rule related to const parameters are interesting c++ allows function to be overloaded basis of const ness of parameters only if the const parameter is a reference or a pointer.
- This rule make sense because pass by value cannot modify the actual variable therefore it does not matter whether it is received as a const parameter or normal parameter. When we pass variable by reference or pointer we can modify the value refered or pointed. So we can have two version of a function one which can modify the referred or pointer value other which cannot.

```cpp
// this will be a compilation error
void fun(const int i){
    cout << "fun(const int i)"<<endl;
}

void fun(int i){
    cout << "fun(int i)"<<endl;
}
int main(){
    const int i = 0;
    fun(i);
    return 0;
}
```

```cpp
// this is allowed and no compilation error
// error: redefinition of ‘void fun(int)’

void fun(const int &i){
    cout << "fun(const int i)"<<endl;
}

void fun(int &i){
    cout << "fun(int i)"<<endl;
}
int main(){
    const int i = 0;
    fun(i);
    return 0;
}
```
- Some example for the function overloading
```cpp
// valid for Overloading 
int sum(int a, int b){return a + b;}
int sum(char a, char b) {return a + b;}
int sum(char a, char b, char c) {return a+b+c;}
```
```cpp
// valid for Overloading (order of params)
int sum(int a, char b){return a + b;}
int sum(char a, int b) {return a + b;}
```
```cpp
// valid for Overloading 
int func(const int &a);
int func(int &a);
```
```cpp
// valid for Overloading 
int func(char * a);
int func(const char * a);
```

```cpp
// valid for Overloading 
int func() const;
int func();
```

```cpp
// valid for Overloading
int func(int * a);
int func(int a);
```

```cpp
// Invalid for Overloading
int func(const int a);
int func(int a);
```



## function overloading and float ##
```cpp
void test(float s, float t) {} // ---1
void test(int s, int t) {} // ----2
int main(){
    test(3.5,5.6); // compile time error
    test(3.5f, 5.6f) // no error
    return 0;
}

```
- It seems that it will call function 1 but the code gives compilation error there is a ambiguity in function overloading because 3.4,5.6 is considered double by the compiler. Because as per c++ standard, floating points literals(compile time constant) are treated as double unless explicitly specified by suffix.

## Name mangling ##
C++ support function overloading i.e. there can be more than one function with the same name and defers in parameters how does c++ compiler distinguish b/w different functions. So when compiler generates the code it appends information about arguments, this technique is called name mangling. C++ standard does not specify any particular technique for name mangling so different compiler may add different information to function names.

```cpp
int f(void){return;}
int f(int) {return;}
int g(void) {int i = f(0);, j=f(0);}
// compiler adds the names like
int _f_v_(int) {return;}
int _f_i_(int) {return;}
int _g_v(void) {int i = f(0);, j=f(0);}
```
- c function does not support name mangling and function overloading. So c++ provide `extern "c"` block to define the c function. Compiler confirm the names are unmingled.

```cpp
extern "c"{
    int function(int x,int y);
}
```



