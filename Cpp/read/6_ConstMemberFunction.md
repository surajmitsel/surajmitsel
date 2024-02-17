## Const member function ##
- Declaring a member function with keyword `const` specifies that the function is read only and it does not modify the object for which it is called.
- The `const` keyword should be placed after the parenthesis of the argument list.
- like member function the object of the class can also be declare as constant.
- `const` object cannot be modified and hence can invoke only `const` member functions as these function ensure not to modify the object. Any attempt to change the data member of `const` objects results in a compile time error.
```cpp
const ClassName Obj;
```
- The `const` keyword required to put both in declaration and definition.
- The `const` member function can be called by any object like `const` and `non-const` object.
- Whenever and object is declared as `const` it needs to be initialized at the time of declaration. However the object initialization while declaring is possible only with the help of constructor.
- The `const` member function cannot call any member function which is not `const`
```cpp
int Data::getMonth() const{
    return month;
}
``` 
- Mostly getter functions are defined as `const`.
- Whenever a function is declared as `const`, it can be called on any type of object. `non-const` functions can only be called by `non-const` objects.
```cpp
class Test{
    int value;
public:
    Test(int v = 0) {value = v;}
    int getValue(){return value};
};
int main(){
    const Test t;
    cout << t.getValue();
    return 0;
}
```
```cpp
//output
passing `const Test` as `this` argument Test::getValue() discard qualifier.
```
- Note that just because a function declared as `const` that doesn't prohibit `non-const` functions from using it. the rule is
    - `const` functions can always be called.
    - `non-const` function can only be called by `non-const` objects.

## `const` overloading ##
- In large part because `const` function cannot return `non-const` references to an object data, there are many times where it might seems appropriate to have both `const` and `non- const` version of a function. For instance if you are returning a reference to some member data then you may want to have `non-const` version of a function that returns `non-const` reference.
```cpp
int & myClass:: getData(){
    return data;
}

const & int & myData:: getData() const{
    return data;
}
```

## `const_` iterator ##
- In order to enforce const ness c++ required that `const` function return only `const` pointers and references.
Since iterator also can be used to modify underlying collections, when an STL collection is declared `const` then any iterator used over the collection must be `const` iterators. Use the keyword `const_` for iterators.

```cpp
std::vector<int> vec;
for (std::vector<int> iterator:: itr = vec.begin(), end = vec.end();itr != end; ++itr){
    std::cout << *itr <<std::endl;
}
```
- Note that itr used a `const` interator to interate over a `non-const` collection for not allows to modify the collection members.

## `mutable` in `const` object ##
- `mutable` storage class can only be used on `non-static`, `non-const` data member of a class.
- `mutable` data member of a class can be modified even if its part of `const` object

```cpp
class Test{
public:
    Test(){x=1;y=2}
    mutable int x;
            int y;
};

int main(){
    const Test obj;
    obj.x = 123; // no error
    obj.y = 45 // error
    return 0;
}
```
- `friend` function cannot be declared as const function in C++ because friend means that the function is global hence it does not have `this` pointer and `const` means we cannot change `*this` 
- `static` function also cannot be `const`
- `const` data member of a class must be initialized using initializer list in the class.

