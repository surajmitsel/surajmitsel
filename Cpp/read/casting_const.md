## const_cast ##
- This type of casting manipulates the const ness of the object pointed by a pointer either to be set or to be removed.
```cpp
void print(char * str){
    cout <<str <<endll;
}
int main(){
    const char * c = "sample text";
    print(const_cast<char*>(c));
    return 0;
}
```
- const_cast can be used in program that have any object with same constant value which need to be changed occasionally at some point
```cpp
int x = 50;
const int *y = &x;
cout << "old value is: " << *y << endl;

int* z = const_cast<int*>(y);
*z = 100;
cout << "new value is: " << *z << endl;
// output
// old value is: 50
// new value is: 100
```
- const_cast can be used to change non_cast class members inside a const member function
```cpp
class student{
    int roll;
public:
    student(int rl): roll(rl){}
    void fun const(){
        (const_cast<student*>(this))->roll = 5;
    }

    int getRoll(){ return roll; }
};

int main(){
    student st(3);
    cout << st.getRoll() << endl; // 3
    st.fun();
    cout << st.getRoll() << endl; // 5
    return 0;
}
```
- const_cast can be used to pass const data to a function that does not receive const for eg.
```cpp
int main(){
    const int val = 10;
    const int *ptr1 = &val;
    int * ptr2 = const_cast <int *>(ptr);
    cout << fun(ptr1); // 20
    return 0;
}
int fun(int * ptr){
    return (*ptr + 10);
    // This works fine
}

int fun (int *ptr){
    *ptr = * ptr + 10;
    return * ptr;    
    // undefined behaviour because const pointer is modified here
}
```
- const_cast cannot cast if the type of const is not same as original object for eg (int*) is being type casted to (char*) which gives compilation error.
```cpp
int main(){
    int a = 40;
    const int * b = &a;
    char * c = const_cast<char *>(b); //compilation error
    *c = 'a';
    return 0 ;
}
```
- const_cast can also be used to cast away volatile attribute.
```cpp
int main(){
    int a = 40;
    const volatile int * b = &a;
    cout << "typeid of b" << typeid(b).name() << endl;
    
    int *c = const_cast<int*>(b);
    cout << "typeid of c" << typeid(c).name() << endl;
    return 0;
}
//output
typeid of b pvk
typeid of c pi
```

