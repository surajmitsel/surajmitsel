## Default Argument ##
- It is useful of some argumets have the same value always as in the bank to calculate interests
- As default argument is a value provided in a function declaration that is automatically assigned by the compiler if the caller of the function does not provide a value for the argument with a default value.
```cpp
int sum(int x, int y, int z = 0 ,int w = 0){
    return x + y + z + w;
}
int main(){
    cout << sum(10,15);
    cout << sum(10,15,25);
    cout << sum(10,15,25,30);
    return 0;
}
//o/p
// 25,50,80
```
- When function overloading is done with the default value then we need to make sure it will not be ambiguous. The compiler will throw error if ambiguous.
```cpp
int sum(int x, int y, int z = 0, int w = 0); // ------(1)
int sum(int x, int y, float z = 0, float w = 0); //-------(2)

sum(10,15,20); // calles (1)
sum(10,15); // compilation error: ambiguous
```
- Default arguments are different from constant arguments as constant arguments cannot be changed whereas default arguments can be overwritten if required.
- We must add default from R->L we cannot provide the default value in b/w argument list
```cpp
// Ok
int mul(int i, int j = 5, int k = 3);
int mul(int i = 0, int j = 5, int k = 3);

// not ok
int mul(int i = 2, int j, int k = 3);
int mul(int i = 2, int j = 4, int k);
```
- Default arguments should be given in function declaration on in definition.
- variable name can be ommited from function declaration
```cpp
void init (int = 1, int = 2, float = 3.14f);
```
### default argument and virtual function ###
```cpp
class Base{
    virtual void func(int x = 0){
        cout << "Base::func(), x: "<< x <<endl;
    }
};

class Derived::public Base{
    virtual void func(int x){
        cout << "Derived::func(), x: "<< x <<endl;
    }
};

int main(){
    Derived d1;
    Base *bp = &d1;
    bp->func();
    return 0;
}
```
```cpp
//o/p
Derived::func(), x: 0
```

- Dafault value is used at compile time. when compiler sees that an argument is missing in a function call it substitues the default value given.
- Therefore default argument does not participate in signature of function so signature of fun() of Base class and derived class are considered same.

```cpp
class Base{
    virtual void func(int x = 0){
        cout << "Base::func(), x: "<< x <<endl;
    }
};

class Derived::public Base{
    virtual void func(int x = 10){
        cout << "Derived::func(), x: "<< x <<endl;
    }
};

int main(){
    Derived d1;
    Base *bp = &d1;
    bp->func();
    return 0;
}
```
```cpp
//o/p
Derived::func(), x: 0
```
- The value is still considered x = 0 at the compile time and the virtual function is resolved at run time. So the default value of the Base class is taken and function of derived class is called.