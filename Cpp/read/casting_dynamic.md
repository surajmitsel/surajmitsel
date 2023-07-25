## dynamic_cast ##
- `dynamic_cast<>` require RTTI (run time type information) for track of dynamic type.
- dynamic cast can only be used with `pointers` and `references` to class or with `void *`. Its purpose is to ensure that the result of type conversion points to a valid complete object of the destination pointer type.
- This naturally includes pointer `up-cast` (derived->base) in the same way as allowed as an implicit conversion.
- But dynamic_cast can also `down-cast` (base->derived) only for polymorphic case (those with virtual members) if and only if the pointed object is a valid complete object of the target type for eg.
```cpp
class Base {virtual void dumy(){}};
class Derived: public Base {int a;};

int main(){
    try{
        Base * bd = new Derived;
        Base * bb = new Base;
        Derived * d;

        d = dynamic_cast <Derived *>(bd);
        if(d == nullptr){
            cout << "nullptr on first type cast" << endl;
        }

        d = dynamic_cast <Derived *>(bb);
        if(d == nullptr){
            cout << "nullptr on second type cast" << endl;
        }
    }catch(exception &exp){
        cout << "Exception:"<< exp.what() << endl;
    }
    return 0;
}
// output
nullptr on second type cast
```
- dynamic_cast cannot perform the other implicit casts allowed on pointers casting nullptr b/w pointer types (even b/w unrelated classes) and casting any pointer of any type to a `void *` pointer.
- Most common use case of dynamic_cast is for converting base class pointers into derived class pointer. This process is called down casting. The conversion will be successful if base class pointer is already points to derived class object or else conversion will return nullptr.
- `NOTE` use static_cast unless you are down casting, in that case dynamic_cast is better choice.

## Does not work ##
It does not work in following case:
- With protected or private inheritance
- For classes they don’t declare or inherit any virtual function thus they don’t have virtual table.
- In certain cases involving virtual base class.

## dynamic_cast vs virtual function ##
usually virtual function should be preferred over down casting however there are times when down casting is a better choice
- when you cannot modify a base class to add the virtual function (eg. because the base class is a part of standard library).
- when you need access to something which is derived class specific (eg. an access function that only exists in derived class)
- when adding a virtual function to base class does not make sense.

## RTTI ##
- It is a feature in c++ which is utilized by dynamic_cast. Some compiler allows you to turn RTTI off as an optimization in that case dynamic_cast will not work correctly.
- It is mechanism that exposes information about an objects data type at runtime and is available only for the classes which have at least one virtual function.
- It allows the type of an object to be determined during program execution.
- For eg. dynamic_cast uses RTTI and following program fails with error `cannot dynamic cast b to derived class D*` because there is no virtual function in the base class
```cpp
class B{};
class D: public B{};
int main(){
    B * b = new D;
    D * d = dynamic_cast<D*> (b);
    if(d != nullptr){
        cout << "works" << endl;
    }else{
        cout <<"error" << endl;
    }
}
// output
error
```

```cpp
class B{virtual void func(){}};
class D: public B{};
int main(){
    B * b = new D;
    D * d = dynamic_cast<D*> (b);
    if(d != nullptr){
        cout << "works" << endl;
    }else{
        cout <<"error" << endl;
    }
}
// output
works
```

