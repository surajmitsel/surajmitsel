## Operator Overlaoding ##
- It allows you to redefine the way operator works for user-defined types only (objects,structure).It cannot be used for build-in datatypes.
- Two operator `=` and `&` are already overloaded by default on c++.
- Operator functions are same a normal functions. The only difference are name, the name of a operator function is always followed by symbols of operator and operator functions are called when the corresponding operator is used. 
- Although overloaded operators are usally called implicitly by the compiler when they are encountered in the code. But they can also be called explicitly as same way as any member or non-member function is called.
- Operator function must be either member function (non-static) or fried-function the only difference b/w is that a friend function will have only one argument for unary operator and two argument for binary operator while a member function will have no argument for unary operator and one for binary operator.

```cpp
friend function                         operator function                 
one argument --- [unary-operator]  ---- No argument
two argument --- [binary-operator] ---- one argument

return_type classname::operator op(arg-list)

// return type and arg-list is user defined it can be anything
```
- The operator which cannot be overloaded
    - .(dot), ::, ?:, sizeof(), #, ##
    - .* (member selection through pointer to function)
- operator overloading should not be used to change the way operator works built-in type.
- It is the job of the programmer to redefine operator in consistance and understandable manner.
```cpp
void operator ++()
{
    count = count - 1;
}
void operator ++()
{
    count = count -1; // possible but wrong design
}
```
- You can write the function instead of operator overloading but operator overloading makes a program clear for eg. you can replace the code like.
```cpp
calc = add(mul(a,b),div(a,b))
calc = a*b + a/b
```
- Pre-Post increament operator overloading
```cpp
class sample{
private:
    int value1, value2;
public:
    sample operator++();
    sample operator++(int);
    sample(){
        value1 = 0;
        value2 = 0;
    }
};
//pre-increament
sample& sample::operator++(){
    value1 = value1+1; // ++(this->value1);
    value2 = value2+1; // ++(this->value2);
    return *this;
}
//post-increament
sample& sample::operator++(int){
    const sample old(*this);
    value1 = value1+1; //++(this->value1);
    value2 = value2+1; //++(this->value2);
    return old;
}
```
## Overload `+` operator ##
```cpp
class complex{
private:
    int real, image;
public:
    complex(int r=0, int i=0){
        real = r;
        image = i;
    }
    complex operator + (const complex & obj); // ------(1)
    friend complex operator+(const complex & obj1, const complex & obj2); // ------(2)
    
    void print(){
        cout << "real:" << real << endl;
        cout << "image:" << image << endl;
    }
};
complex complex:: operator + (const complex & obj){
    cout << "class operator called" << endl;
    complex res;
    res.real = real + obj.real;
    res.image = image + obj.image;
    return res;
}

complex operator + (const complex & obj1, const complex & obj2){
    cout << "friend operator called" << endl;
    return complex(obj1.real + obj2.real, obj1.image + obj2.image);
}

int main(){
    complex c1(10,5), c2(2,4);
    complex c3 = c1+c2;
    c3.print();
    return 0;
}
/*
class operator called
real:12
image:9

Note: If class operator overloading take first priority then friend function
*/
```
## Overload `pointer` operators ##
```cpp
class smartPtr{
    int * ptr;
public:
    explicit smartPtr(int *p = nullptr){ptr = p;}
    ~smartPtr(){delete ptr;}
    int & operator *(){return *ptr;}
    int * operator ->(){return ptr;}
};
int main(){
    smartPtr ptr(new int);
    *ptr = 20;
    cout << *ptr;
    return 0; // we need not to call delete
}
```
## `functor` which is operator `()` overloading ##
- Functor is an object which act like function its an operator `()` overloading in class
``` cpp
class MyFynctor{
    public:
        int operator()(int x){return x*5;}
};
int main(){
    myFunctor obj;
    int x = obj(5); // o/p 25
}
```
- The real advantage of functor they can help state
```cpp
class Matcher{
    string name;
public:
    Matcher(string x) {name = x;}
    bool operator()(string x){return x == name;}
};
int main(){
    Matcher obj("suraj");
    if(obj("suraj")){
        cout << "this is suraj object" << endl;
    }
}
// o/p
// this is suraj object
```
- Functors are commonly used in STL algorithms, for eg. you can define multiply functor that multiplies it's arguments by a specified amount.
```cpp
class multiplyBy{
    int factor;
public:
    multiplyBy(int f){factor = f;}
    int operator()(int other) const{
        return factor * other;
    }
}
```
- Then you could pass a multiply by object to an algorithm like std::transfer

```cpp
int array[5] = {1,2,3,4,5};
std::transform (array,array+5,array,multiplyBy(3));
// op array will be {3,6,9,12,15}
```
- Advantage:
    - functors often may be inline which is not true with function pointers.
    - functor object may hold state.
    - functor object (non-virtual) does not require `vtable` and runtime dispacting.
    - Its fits into oops.

- disAdvantage:
    - function object can not be swapped with other function object during runtime (at least unless it extends some base class which therefore gives some overhead).
    - It brings more complexity.
``` cpp
//for_each()
struct myClass{
    void operator(int i){
        std::cout << ' ' << i;
    }
}myObject;

void myFunction(){
    std::cout << ' ' <<i;
}
int main(){
    std::vector <int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    for_each(myVector.begin(),myVector.end(),myFunction());
    // OR
    for_each(myVector.begin(),myVector.end(),myObject);
}
```

## Overloaded `new` and `delete` operator ##
### Global overloading vs class specific overloading ###
- The new and delete operator can be overloaded globally or they can be overloaded for specific classes.
- If these operators are overloaded using member function for a class it means that these operators are only overloaded the specific class.
- If overloading is done outside the class (i.e. it is not a member function of a class) then overlaoded `new` and `delete` will be called anytime when you make use of these operators(within class or outside the class). This is called Global overloading.
```cpp
void * operator new (size_t size);
void operator delete (void*);
```
- Note both overloaded new and delete operator functions are static members by default, therefore they cannot have access to this pointer.
- When `new` is overloaded then inside `new` operator function we should always use global `new operator(:: new obj())` instead of normal `new(new obj())` or else the program will be recursive infinite.

### Overloading `new` and `delete` operator for a specific class ###

```cpp
class student{
    string name;
    int age;
public:
    student(){cout<< "constructor";}
    student(string name, int age){
        this->name = name;
        this->age = age;
    }
    void display(){
        cout << "name:" << name << endl;
        cout << "age:" << age << endl;
    }

    void *operator new(size_t size){
        cout << "overlaod new" <<endl;
        void *p = ::new student();
        // void *p = malloc(size); //this also works fine
        return p;
    }

    void operator delete(void *p){
        ::delete p;
        //free(p);
    }

    int main(){
        student *p = new student("yash",24);
        p->display();
        delete p;
    }
}
```
- Note in this code inside `new` operator function we have allocated dynamic memory through `new` operator but it should be global `new` operator otherwise it will go in recursion.
```cpp
void *p = new student(); // this will go in recursion
void *p = ::new student(); // this is correct
```

### Overloading `new` and `delete` operator globally ###
```cpp
using namespace std;
void * operator new(size_t size){
    void *p = malloc(size);
}
void delete(void *p){
    free(p);
}
int main(){
    int *p = new int(5);
    for(int i = 0; i<5; i++){
        p[i] = i;
    }
    cout << "array:";
    for(int i = 0; i < 5; i++){
        cout <<p[i] << ",";
    }
    cout <<endl;
    delete p;
}
```
- Note in this code in new overloaded function we cannot allocate memory using ::new int[5] as it is overloaded globally so we can use only malloc.

### why to overlaod `new` and `delete` operator ###
- The overloaded `new` operator can accept arguments therefore a class can have multiple overloaded new operator functions. This gives the programmer more flexibility in constomizing memory allocated for object for eg.
```cpp
void * operator new(size_t size, char c){
    void * ptr;
    ptr = malloc(size);
    if(ptr != nullptr){
        prt = c;
    }
    return ptr;
}
int main (){
    char *ch = new ('#') char;
}
```
- Note code will not only allocate memory for single character but will also initialize the allocated memory with `#` character.
- Overloaded `new` and `delete` operator also provide `garbage` collection flexibility for class objects.
- Exception run time handling can also be added into `new` operator function.
- We can also make use of `realloc()` function in overloaded `new` function to re allocate memory dynamically.
- Overloaded `new` operator also enable programmers to squeeze some extra performance out of their programs for eg. in class to speed up the allocation of new nodes a list of deleted nodes can be maintained so that their memory can be reused when new nodes are allocated. In this case overloaded `delete` operator will add nodes to list of deleted nodes and the overloaded `new` operator will allocate from the list rather then from the heap to speed up the memory allocation. Memory from the heap can be used when the list of deleted nodes is empty.

## Overload `[]` array index operator ##
- This operator is generally used with array to retrive and manipulate the array element.
```cpp
int main(){
    char name[] = "suraj verma";
    cout << name[6] << endl;
    cout << 6[name] << endl;
    return 0;
}
// o/p:  v
```
- In above statement both cout gives the output `v` due to the exclusive property of `[]` operator. The compiler reads both the statement in similar way there is no difference b/w *(name+5) and *(5+name).
- Overlaoding of `[]` may be useful when we want to check for index out of bound.
- We must return by reference in function because an expression like `array[i]` can be used an `l-value`.
```cpp
class Array{
    int * ptr;
    int size;
public:
    Array(int *, int);
    int & operator[](int);
    void print() const;
}
Array::Array(int *p = nullptr, int s = 0){
    size = s;
    ptr = nullptr;
    if(size){
        ptr = new int[5];
        for(int i = 0; i < size; i++)
            ptr[i] = p[i];
    }
}
int & Array::operator[](int index){
    if (index >= size){
        cout << "array index out of bound" << endl;
        exit(0);
    }
    return ptr[index];
}
void Array::print()const{
    for(int i = 0; i < size; i++)
    cout << ptr[i] << "," <<endl;
}
int main(){
    int a[] = {1,2,4,5};

    Array arr(a,4);
    arr[2] = 6;
    arr.print();
    arr[8] = 6;
    return 0;
}
```
```cpp
//output
1 2 6 5
array index out of bound, exiting
```

## String add using `+` Overloading ##
```cpp
class AddString{
    public:
    char str[100];
    AddString(){};
    AddString(char str[]){
        strcpy(this->str,str);
    }
    AddString operator+(AddString & s2){
        AddString s3;
        strcat(this->str,s2.str);
        strcpy(s3.str,this->str);
        return s3;
    }
}
int main(){
    char str1[] = "suraj";
    char str2[] = " barkha";
    AddString a1(str1);
    AddString a2(str2);
    AddString a3 = a1 + a2;
    cout << "str concatenation:" << a3.str;
}
```
## String comparision operators `==`, `<=`, `>=` ##
```cpp
class CompareString{
    public:
        char str[25];
    CompareString(char str1[]){
        strcpy(this->str,str1);
    }
    int operator == (CompareSring s2){
        if(strcmp(this->str, s2.str) ==0){
            return 1;
        }
        return 0;
    }
    int operator >= (CompareSring s2){
        if(strlen(str) <= strlen(s2)){
            return 1;
        }
        return 0;
    }
    int operator >= (CompareSring s2){
        if(strlen(str) >= strlen(s2)){
            return 1;
        }
        return 0;
    }
};
void compare(CompareString s1, CompareString s2){
    if(s1 == s2){
        cout <<"equal" ;
        return;
    }
    cout << "not equal";
    if(s1 >= s2){
        cout<< "s1 is greater then s2";
        return;
    }
    cout<< "s2 is greater then s1";
}

void testcase1(){
    char str1[] = "suraj";
    char str2[] = " verma";

    CompareString s1(str1);
    CompareString s2(str2);
    compare(s1,s2);
}

void testcase2(){
    char str1[] = "suraj";
    char str2[] = "suraj";

    CompareString s1(str1);
    CompareString s2(str2);
    compare(s1,s2);
}

int main(){
    testcase1();
    testcase2();
}
```
```cpp
//output
s2 is greater then s1
equal
```

## print operator `<<` overloading ##
```cpp
friend ostream & operator <<(ostream &os, char * ptr){
    os << "address pointer:" << ptr << endl;
}
char *ptr = "suraj";
cout << ptr;

//output
address pointer: 0x12345
```
## Conversion operator ##
- Sometime it is required to convert one concreate type to another type or primitive type implicitly. Conversion operator play smart role in such situation.
```cpp
class Complex{
private:
    double real,img;
public:
    Complex(double r=0.0, double i = 0.0) : real(r), img(i){}

    //get magnitude function in a usal style
    double getMag(){return get_mag();}

    //coversion operator style
    operator double(){return get_mag();}
private:
    double get_mag(){return sqrt(real*real + img * img);}
}
int main(){
    Complex cmplx (3.0,4.0);
    cout << cmplx.getMag() <<endl;
    //same can be done using conversion function
    cout << cmplx <<endl;
}
```
