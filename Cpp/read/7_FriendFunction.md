## `friend` function ##
- The `friend` function are declared with the keyword `friend`, it is not the member of the class but it has right to access `private data member` of a class.
- `friend` class can access `private` and `protected` member of other class in which it is declared as `friend`. For example 
linked-list class may be allowed to access `private` member of Node.
- `inline`: Friend functions can be defined (given a function body) inside class declarations.

### friend function cannot be ###
- `const` member function
- `static` function
- `virtual` function
- `inherited` to derived class
- `called by object` of the class
-  Scope of the class but it cannot have `this` pointer access
- `friendship` is not mutual until specified as such 
- `member function` of the class but it cannot be defined inside class
- having `const object` as parameter.


```cpp
class Node{
private:
    int key;
    Node * next;
    friend class LinkedList; // it can access private member of class Node
};
```
- `friend` can be method of another class or global function.
```cpp
class Node{
private:
    int key;
    Node * next;
    friend int LinkedList::search(); //------(1)
    // Only the search() function of class LinkedList() can access the private member of class Node.
};
```
- `friend` function should be used only for limited purpose too many `friend` function reduces the purpose of encapsulation.
- `friendship is not a mutual` i.e. if class A is a friend of class B that doesn't mean B is a friend of class A.
- `friendship is not inheritable`. So if base class has a friend function then the friend function does not becomes the friend of derived class.
```cpp
class Base{
protected:
    int x;
public:
    Base(){x=0;}
    friend void show();
};

class Derived:public Base{
protected:
    int y;
public:
    Derived(){y=0;}
};

void show(){
    Derived d;
    cout << "default value of Base:x = " << d.x;

    // we cannot access private member declated in class derived
    cout << "default value of Derived:y" <<d.y;
}

int main(){
    show();
    getChar();
    return 0;
}
```
- `friend` function definition does not use SRO operator.
- It is not the scope of the class so it cannot be called by the object of that class.
- It can be declare in `private` or `public` part and usually it has object as an argument.
- member function of one class can be `friend` function of another class in that case they are declared with SRO operator.
- Keyword `friend` is placed only in declaration not in definition.
- `friend` is invoked without the use of an object.
- `friend` can not be `const` and `static` function.

```cpp
class Example{
private:
    int a,b;
public:
    int sum(int,int);
    friend int compute(Example x);
};
int Example::sum(int a,int b){
    this->a = a;
    this->b = b;
    return a+b;
}
int compute (Example x){
    return x.a + x.b -5;
}

int main(){
    Example e;
    cout << e.sum(10,6); // 16
    cout << compute(e);  //11

}
```

```cpp
class Data{
private:
    // data-member
public:
    int func();
};

class User{
private:
    // data-member
public:
    // func() is a member class Data and friend of class User
    friend int Data::func();
}
```
- We can also declare all the member function  of one class as the `friend` function of another class
```cpp
class test{
private:
    // data members
public:
    friend class foo;
};
```
- `friend` fuction can be used for `operator-overloading` and it takes one argument for `unary-operator` and two argument for `binary-operator`.
- `friend` function in c++ cannot be declared as `virtual` and therefore no dynamic binding of `friend` function is possible.
-  `friend` function cannot be `static` because `static` member functions can access only static data member whereas `friend` function can access all the members, second is `friend` function also required an object to access the members whereas `static` member cannot access. Another thing `static` functions are member function but `friend` functions are not member functions.
- `friend` function cannot be `const` because `const` keyword can only be added to member functions not to `friend` functions, even the parameter to the `friend` function cannot be `const` object. It will give compilation error.
- `friend` function cannot be inherited in derived class.

## `final` class using `friend` function ##
- The class which cannot be inherited further is called `final` class, so one extra class makeFinal is used for this purpose.
```cpp
class MakeFinal{
private:
    MakeFinal(){cout <<"MakeFinal constructor";}
    friend class Final;
};

class Final{
public:
    Final(){cout <<"Final constructor" << endl;}
};

class Drv: public Final{
    public:
    Drv(){cout <<"Drv constructor" << endl;}
};

int main(int argc, const char* argv[]){
    Drv d;
    return 0;
}
```
```cpp
//output
in constructor Drv::Drv(): error MakeFinal::MakeFinal() is private.
```
- Derived constructor directly invokes MakeFinal's constructor and the constructor of MakeFinal is private therefore we get the compilation error.
- We can do `friend` function `overloading` 
```cpp
class Example{
    int x;
public:
    friend void func();
    friend void func(Example&);
    friend void func(Example*, int a);
};

void func(Example& e){
    cout << e.x << endl;
}

void func(Example& e, int a){
    cout << "void func(Example& e, int a)" << endl;
}

void func(){
    cout << "empty" << endl;
}

int main(int argc, const char* argv[]){
    Example obj;
    func();
    func(obj);
    func(obj,5);
    return 0;
}

// o/p
// empty
// 287539201
// void func(Example& e, int a)

```
## Unary operator `-` overloading using friend funcion ##
```cpp
class Test{
private:
    int a;
public:
    void set_a(int x){a = x;};
    int get_a();
    friend void operator - (Test &obj); // unary operator
};

void operator - (Test &obj){
    obj.a = - obj.a;
}
int main(){
    Test obj;
    obj.set_a(10);
    cout << "a:" << obj.get_a(); // a:10
   
   - obj();
    cout << "a:" << obj.get_a(); // a:9

}
```
## Binary operator `*` overloading using friend function ##
```cpp
class Test{
private:
    int a;
public:
    void set_a(int x){x = a;};
    int get_a();
    friend Test operator *(Test &obj1, Test & obj2); // binary operator
};

Test operator * (Test &obj1, Test & obj2){
    Test tmp;
    tmp.a = obj1.a * obj2.a;
    return tmp;
}
int main(){
    Test obj1, obj2;
    obj1.set_a(10);  
    obj2.set_a(20);

    Test obj3 = obj1 * obj2;
    cout << "a:" << obj3.get_a(); // 200
}
```
## `private` constructor using `friend` function ##
- If we want that class should not be inherited by any other class
```cpp
class Test{
private:
    Test(){cout <<"constructor Test() \n";}
    friend class Another; // -----(1)
};

class Another{
public:
    Another(){
        Test t1;
        cout <<"constructor Another()\n";
    }
};

int main(){
    Another a1;
    return 0;
}
```
```cpp
constructor Test()
constructor Another()
```
- If you comment the line (1) then you will encounter below error
```cpp
error: ‘Test::Test()’ is private within this context
```
