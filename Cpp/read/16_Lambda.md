## `Lambda function` ##
- c++11 introduce lambda function to allows us write an inline function which can be used for short snippets of code.
- simple form of lambda function can be defined as follow:
```cpp
[capture Clouse](parameters)->return type{ /*body of lambda*/}

[]()->ret {/*function body*/}
[]() {/*function body*/}
[] {/*function body*/}
```
- Generally return type in a lambda is evaluated by compiler itself and we don't need to specified that explicitly and `->ret` can be ignored in simple case but in complex cases as in conditional statement compiler cannot make out return type and we need to specify that.

- In lambda function operator overloading `()` takes place and the capture clause defines internally data member for the class which is generated in background for lambda object and function body becomes the member function so instead of defining class first and write functor and then create operator overloading callable object which takes lot of code so lambda function solve the purpose smoothly.
```cpp
auto sum = [&x, y]          // class data member list
            (int a, int b)  // operator`()` overloading
                {           // function body as member function
                return a+b;
                };
```
- Syntax used for capturing variables
```cpp
[&] // capture all external variables by reference
[=] // capture all external variables by value
[a,&b] // capture `a` by value and `b` by reference
[]  //lambda function can access only those variables which are local to it
``` 
```cpp
struct test{
 void func(int);
};

void test::func(int x){
    [x, x]{};       // error
    [&, &x]{};      // error
    [this, *this]{};// error 
    
    [&]{};          // ok
    [&, x]{};       // ok, by reference except i is captured by copy
    [&, this]{};    // ok equivalent to [&]
    [&, this, i]{}; // ok equivalent to [&, i]
    [=, &i]{};      // ok
    [=, this]{};    // ok(>= c++17) , error(< c++17)
    [=, *this]{};   // ok(>= c++20) , error(< c++20)
}
```
### vector use case using lambda ###
```cpp
int main(){
    vector<int> v1 = {3,1,7,9};
    vector<int> v2 = {10,2,7,16,9};
    
    // 1. Access v1 and v2 by reference
    auto pushInTo = [&](int m){
        v1.push_back(m);
        v2.push_back(m);
    }

    //2. Access v1 by copy
    [v1](){
        for(auto it = v1.begin(); it!=v1.end(); it++){
            cout << *it << endl;
        }
    }

    //3. first number greater than Num
    int Num = 5;
    vector<int>:: interator it = find_if(v1.begin(), v2.end(),[Num](int i){
        return i > Num;
    });
    cout << "First number greater than 5 is " << *it << endl;

    //4. lambada to count number greater than or equal to N[=] access all variable
    int N = 5;
    int count_N = count_if(v1.begin(), v1.end(),[=](int a){
        return a >= N
    });
    cout << "number of element greater than or equal to 5 :" << count_N << endl;
}
```
- Before c++14 to generalize the lambda function expression template parameter were used for eg.
```cpp
[](int a, int b) -> int{return a + b;} // for integer input
[](double a, double b) -> double{return a + b;} // for float input

// Generalized
tempate<typename T>
[](T a, T b){ return a + b; }
```
- But c++14 onward `auto` keyword introduced to identify the type at compile time automatically. So we need not of template
```cpp
// [](auto a, auto b) -> auto {return a + b;}

int main(){
    auto sum = [](auto a, auto b){return a + b;}
    cout << sum(1,6) << endl;
    cout << sum(1.2,6.4) << endl;
    cout << sum(string("suraj ") string("verma")) << endl;
    return 0 ;
}
```
```cpp
// declare generalized lambda and store in greater
int main(){
    auto greater = [](auto a, auto b)->boolean {return a>b;};
    vector<int> v1 = {1,4,2,1,6,62,636};
    vecror<int> v2 = {4.62,161.3,62.26,13.4,235.5};
    sort(v1.begin(),v1.end(),greater);
    sort(v2.begin(),v2.end(),greater);

    printElement(v1);
    printElement(v2);
}
void printElement(auto & vec){
    for(auto x:vec){
        cout << x << ",";
    }
}
// output
636, 62, 6, 4, 2, 1, 1
235.5, 161.3, 62.26, 13.4, 4.62
```
- Pass a lambda function as a parameter to another function
```cpp
template<typename T, typename proc>
void do_something(T val, printHanlder print){
    std::cout << "do_something" << endl;
    print(val);
}

int main(){
    do_something(16, [](auto &val){cout << val << endl;});
}
```
- In this case the compiler will deduce the type of lambda function and pass that to the do-something function or other way.
```cpp
template<typename T>
void do_something(T val, std::function <void(T)> print){
    std::cout << "do_something" << endl;
    print(val);
}

int main(){
    do_something(16, [](auto &val){cout << val << endl;});
}
```
- using the function wrapper std::function us very useful to store heterogeneous functions into container so you can store function pointers, functors or lambda expression.

```cpp
using sum_fun = std::function <int (int a ,int b)>;
int func(int val, sum_fun sum){
    int t = val + sum(2+3);
    return t;
}
int main(){
    auto sum = [](int a, int b){return a+b;};
    int d = func(5,sum);
    //OR
    int d = func(5,[](int a, int b){return a+b;});
    return 0;
}
```

