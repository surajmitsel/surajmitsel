## weak_ptr ##
- weak_ptr is created as a copy of shared_ptr. It provides access to an object that is owned by one more shared_ptr instance but does not participate in reference counting.
- The existence or destruction is not having any impact on shared_ptr or its other copies. It requires in some case to break circular references b/w shared_ptr
- `weak_ptr` is the model of the concept of temporary ownership because it borrows the resources from shared_ptr.
its having limited interface so it’s not so smart as compared to shared_ptr.
- `unique_ptr` is the model of exclusive ownership.
- `shared_ptr` is the concept of shared ownership.

```cpp
int main(){
    shared_ptr<int> sp1,sp2;
    weak_ptr<int> wp;

    sp1 = make_shared<int> (10);  //sp1
    wp = sp1;                     //sp1,wp

    sp2 = wp.lock();              //sp1,wp,sp2
    sp1.reset();                  //wp,sp2

    sp1 = wp.lock();              //wp,sp2,sp1

    cout << *sp1 << endl; // 10
    cout << *sp2 << endl; // 10
    return 0;
}
```

### weak_ptr expired ###
- returns whether the weak_ptr object is either empty or there are no more share_ptr in the owner group it belongs to.
The function shall return the same as (use_count() == 0) although it may do so in a more efficient way.

```cpp
int main(){
    shared_ptr<int> shared (new int(10));
    weak_ptr<int> weak(shared);

    cout << weak.expired() ? "expired" : "not expired" << endl;

    shared.reset();

    cout << weak.expired() ? "expired" : "not expired" << endl;
}
//output
// not expired
// expired
```

- weak_ptr doesn't change in opposite to the shared_ptr the reference counter of the shared variable.
```cpp
int main(){
    cout << std::boolaplpha <<endl;
    auto sp1 = make_shared<int> (2011);
    weak_ptr<int> wp(sp1);
    
    cout << sp1.use_count() << endl; // 1
    cout << wp.use_count() << endl;  // 1
    cout << wp.expired() << endl;    // false

    if(shared_ptr<int> sp2 = wp.lock()){
        cout << *sp1 << endl;               // 2011
        cout << sp2.use_count << endl;      // 2
    }else{cout << "dint get resource" << endl;}

    wp.reset();

    if(shared_ptr<int> sp2 = wp.lock()){
        cout << *sp1 << endl;           
        cout << sp2.use_count << endl;
    }else{cout << "dint get resource" << endl;} // dint get resource

}
```
