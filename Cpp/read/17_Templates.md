## Templates ##
- Templates are way of making your class more abstract by letting you define the behaviour of the class without actually knowing what datatype will be handled by the operation of the class
- Template can be used in conjunction without abstract datatype in order to allow the to handle any type of data. For eg. you can make stack class as template that can handle a stack of any datatype rather than having to create a stack of any datatype.
- It is a ability to have a single class that can handle several different datatype means the code is easier to handle and it makes class more usable.
- C++ adds two keyword to support templates `template` and `typename`. The second keyword can always be replaced by keyword `class`.
- Templates are expended at compile time this is like macros, the difference is compiler does type checking before expansion.
- Templates in C++ are resolved at compile time. When you use templates to define generic code, the compiler generates specific code for each instantiation of the template with different template arguments. This process is known as template instantiation, and it occurs during the compilation process. The compiler verifies the correctness of template code, including syntax and type checking, and generates the appropriate code for each template instantiation. The resulting compiled code contains the specific implementations for each template instantiation, and there is no runtime overhead associated with template instantiation.
- The basic syntax for declaring a template class is follow as
```cpp
    // Definition
    template <class myType> 
    class myClass{
        // implementation
    }; 

    //Declaration or use
    myClass <int> obj;
```

## function templates ##
- We can write a generic function that can be used for different data types. For eg. function templates are `sort()`, `max()`, `min()`, `printArray()`
```cpp
template <typename T>
T myMax(T x, T y){
    return x>y? x: y;
}

int main(){
    cout << myMax<int>(3,7) << endl;
    cout << myMax<double>(3.0,7.5) << endl;
    cout << myMax<char> (`g`,`i`) << endl;
    return 0;
}
```
### bubble short using template ###
```cpp
template<class T>
void bubbleSort(T a[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; i<j; j--){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
            }
        }
    }
}
int main(){
    int a[5] = {10,50,30,40,20};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a,5);
    cout <<"sorted array:\n";
    for(int i=0; i<n; i++)
        cout <<a[i] <<",";
    return 0;
}
```
## class Template ##
- Like function template class templates are useful when a class defines something which is independent of datatype can be useful for class like LinkedList, Binarytree, stack, queue, array etc.

### Template array class ###
```cpp
template <typename T>
class Array{
private:
    T *ptr;
    int size;
public:
    Array(T array[],int s);
    void print();
};

template <typename T>
Array<T> ::Array(T array[], int s){
    ptr = new T[s];
    size = s;
    for (int i=0;i<s;i++){
        ptr[i] = array[i];
    }
}

template <typename T>
Array<T> ::print(){
    for (int i=0;i<s;i++){
        cout << *(ptr + i) ",";
    }
}

int main(){
    int array[5] = {1,2,3,4,5};
    array<int> a(array,5);
    a.print();
    return 0;
}
```
## Template argument ##
```cpp
template<class T, class U>
class myClass{
    T x;
    U y;
public:
    myClass(){
        cout << "constructor classed \n";
    }
};

int main(){
    myClass <char,char> a;
    myClass <int,double> b;
    return 0;
}
// output:
constructor classed
constructor classed
```
## default value argument to template ##
```cpp
template <class T, class U = char>
class myClass{
    T x;
    U y;
public:
    myClass(){
        cout << "constructor classed \n";
    }
};

int main(){
    myClass <char> a; // This will call myClass<char,char>
    myClass <int> b; // This will call myClass<int,char>
    return 0;
}
```

## nontype argument to template ##
- We can pass nontype argument to templates. Nontype parameters are mainly used for specifying max or min values or any other constant value for a particular instance of a template. The important thing to note about nontype parameters is that they must be const. The compiler should not the value of nontype parameters at compile time because compiler needs to create function/class for a specified nontype value at compile time.
```cpp
template<class T, int max>
int arrayMinIndex(T array[], int n){
    int m = max;
    for(int i = 0; i < n; i++){
        if(array[i] < m){
            m = array[i];
        }
    }
    return m;
}

int main(){
    int array1[] = {10,20,15,12};
    int n1 = sizeof(array1)/ sizeof(array1[0]);
    char array2[] = {1,2,3};
    int n2 = sizeof(array2)/ sizeof(array2[0]);

    cout << arrayMinIndex<int,1000>(array1,n1);
    cout << arrayMinIndex<char,250>(array2,n2);
    return 0;
}
```

## template and static variable ##
- Each instantiation of function templates has its own copy of local static variable for eg. in the following program there are two instance `void func(int)` and `void func(double)` so two copy of static variable exists.

```cpp
template <typename T>
void func(const T& x){
    static int i = 10;
    cout << ++i << endl;
    return;
}

int main() {
    func<int>(1);
    func<int>(2);

    func<double>(1.1);
    return 0;
}
// output:
11
12
11
```

## template specialization ##
- What if we want to write a different code for particular datatype consider a big project that needs a function `sort()` for arrays of any different datatype. Let `quickSort()` be used for all datatype except char datatype, in case of char total possible value would be 256 so `countSort()` would be better option. It is possible in C++ to get a special behaviour for a particular datatype. This is called template specialization.
```cpp
template <class T>
void sort(T array[], int size){
    // implemenation of Quick sort
}

template <>
void sort <char> (char aarry[], int size){
    // implemantion of count sort for char type
}
```
- Another example cloud be class `set` that represents a set of elements and supports operation like `union`, `intersection` etc. when the type of element is char, we may want to use a simple `boolean` array of size 256 to make a set. For other datatypes, we have to use some other complex techniques.

## function template specialization ##
- Consider the following simple code where we have general template `fun()` for all datatype except `int` for `int` there is a specialized version of `fun()`.
```cpp
template <class T>
void fun(T a){
    cout <<"The main template fun():" << a << endl; 
}

template <>
void fun(int a){
    cout <<"function specialized template for int type :" << a << endl; 
}

int main(){
    fun<char>('a');
    fun<int>(10);
    fun<float>(10.14);
}
//output
The main template fun():a
function specialized template for int type :
The main template fun():10.14
```

## class template specialization ##
- In the following program a specialized version of class test is written for `int` datatype.

```cpp
template <class T>
class test{
    public:
        test(){cout <<"general template object\n";}
};
template <>
class test<int>{
    public:
        test(){cout <<"class specialized template object\n";}
};

int main(){
    test<int> a;
    test<char> b;
    test<float> c;
    return 0;
}
//output
general template object
class specialized template object
```

## smart pointer template class ##
```cpp
template <typename T>
class smartPtr{
    T * ptr;
public:
    explicit smartPtr(T *p = nullptr){ptr = p;}
    ~smartPtr(){delete ptr;}
    T & operator *(){return *ptr;}
    T * operator ->(){return ptr;}
};
int main(){
    smartPtr <int> ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0; // we need not to call delete
}
```

## function overloading vs template ##
- Both function overloading and templates are example of polymorphism feature of opp's function overloading is used when multiple function do similar operations whereas templates are used when multiple function do identical operations.
