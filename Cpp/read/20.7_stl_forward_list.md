## forward_list<> ##
- It is a sequence container that allow constant time insert and erase operation within the sequence
- It is like a single linked list
- The elements are stored in dynamically allocated space.
- Insert and delete happens only from front.
```cpp
forward_list::empty //tells if list is empty is or not.
```
- Require less space because it keeps track of next element but list keeps tack of pervious and next element
- It cannot be iterated backward and its individual elements cannot be accessed dynamically.
```cpp
int main(){
    forward_list<int> first;
    forward_list<int> second;
    first.assign({1,2,3});
    second.assign(5,10); // 5 elements with value 10

    for(int &a:first){
        cout << a <<"," << endl; //1,2,3
    }
    for(int &b:second){
        cout << b << "," << endl; // 10,10,10,10,10
    }
    return 0;
}
```
```cpp
forward_list<int> myList = {2,3,8,10,12};
forward_list:: begin; // returns the iterator to the first element

forward_list:: front; // returns the reference to the first element

for(int it = myList.begin(); it != myList.end(); ++it){
    cout << *it << ",";
}
myList.push_front(19);
myList.push_front(34); // 34,19,2,3,8,10,12
myList.remove(8);      // 34,19,2,3,10,12

// remove the element by value
myList.remove_if(single_digit); // 34,19,10,12
myList.remove_if(is_odd:object); // 34,10,12
```
```cpp
forward_list<int> ::iterator it;
it = myList.begin();
it = myList.insert_after(it,10);   // 34,10,10,12
it = myList.insert_after(it,2,11); // 11,11,34,10,10,12
it = myList.insert_after(it,{1,2,3}); // 11,1,2,3,11,34,10,10,12
myList.reverse(); // 12,10,10,34,11,3,2,1,11
```
```cpp
int main(){
    forward_list<int> first = {10,20,30,40,50};
    first.push_front(60); // place by copy
    first.emplace_front(70); // no copy, element is created directly

    //70,60,10,20,30,40,50
    first.pop_front(); // 60,10,20,30,40,50
    return 0;
}
```


