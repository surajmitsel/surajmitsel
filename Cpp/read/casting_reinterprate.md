## reinterpret_cast ##
- It is used to convert a pointer of some data type into a pointer of another data type, even if the data types before and after conversion are different.
- It can convert any pointer type to any other pointer type even of unrelated classes. The operation result in a simple binary copy of the value from one pointer to the other.
- It does not check if the pointer type and data pointed by the pointer is same or not.
- It doesn’t have any return type. It simply converts the pointer type.
- All pointer conversion are allowed neither the content pointed not the pointer type itself checked.
- It can also cast pointer to and from integer type. The format in which this integer value represents a pointer is platform specific.
- It cannot strip a variable's const-ness or volatile-ness like const_cast.

```cpp
int main()
{
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
    cout << *p << endl; // 65
    cout << *ch << endl; // A
    cout << p << endl; // 0x423448
    cout << ch << endl; // A
    return 0;
}
```

### Purpose for using reinterpret_cast ###
 

- reinterpret_cast is a very special and dangerous type of casting operator. And is suggested to use it using proper data type i.e., (pointer data type should be same as original data type).
- It can typecast any pointer to any other data type.
- It is used when we want to work with bits.
- If we use this type of cast then it becomes a non-portable product. So, it is suggested not to use this concept unless required.
- It is only used to typecast any pointer to its original type.
- Boolean value will be converted into integer value i.e., 0 for false and 1 for true.

```cpp

// CPP code to illustrate using structure
#include <bits/stdc++.h>
using namespace std;
 
// creating structure mystruct
struct mystruct {
    int x;
    int y;
    char c;
    bool b;
};
 
int main()
{
    mystruct s;
 
    // Assigning values
    s.x = 5;
    s.y = 10;
    s.c = 'a';
    s.b = true;
 
    // data type must be same during casting
    // as that of original
 
    // converting the pointer of 's' to,
    // pointer of int type in 'p'.
    int* p = reinterpret_cast<int*>(&s);
 
    cout << sizeof(s) << endl; //12
 
    // printing the value currently pointed by *p
    cout << *p << endl; //5
 
    // incrementing the pointer by 1
    p++;
 
    // printing the next integer value
    cout << *p << endl; //10
 
    p++;
 
    // we are casting back char * pointed
    // by p using char *ch.
    char* ch = reinterpret_cast<char*>(p);
 
    // printing the character value
    // pointed by (*ch)
    cout << *ch << endl; //a
 
    ch++;
 
    /* since, (*ch) now points to Boolean value,
    so it is required to access the value using
    same type conversion.so, we have used
    data type of *n to be bool. */
 
    bool* n = reinterpret_cast<bool*>(ch);
    cout << *n << endl; //1
 
    // we can also use this line of code to
    // print the value pointed by (*ch).
    cout << *(reinterpret_cast<bool*>(ch)); //1
 
    return 0;
}
```
- In below example dereferencing new_a is unsafe
```cpp
class A{public: void func_a(){cout <<"func_a" << endl;}};
class B{public: void func_b(){cout <<"func_b" << endl;}};

int main(){
    B* b = new B();
    A* a = reinterpret_cast<A*> (b);
    a->func_a();
    return 0;
}

//output
func_a
```

