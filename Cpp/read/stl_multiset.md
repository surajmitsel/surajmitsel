## multiset <> ##
- It allows to add duplicate items into set
- always stores in sorted order
- can erase more than 1 element by giving start and end iterator
- All other properties are same as set
- Insertion, Accessing, deleting of Elements- O(log N)
```cpp
multiset<int> my_multiset = {10,12,13,14,15};

//OR
int a[] = {42,12,35,9,57};
multiset<int> my_multiset = {a,a+5}; // 9,12,35,42,57
multiset<int>::iterator itr = my_multiset.begin();
*itr = 10; // it cannot be modified its read only
```
- In set/multiset the value of the element cannot be modified, it's read only elements, means elements can be inserted or deleted but value of element cannot be modified.
```cpp
for(auto itr = my_multiset.begin(); itr != my_multiset.end(); itr++){
    cout << * itr << endl;
}
```
```cpp
int a[] = {10,18,19,32,15,9,18};
multiset<>my_multiset(a,a+7); // 9,10,15,18,18,19,32
my_multiset.count(18); // 3
```
```cpp
pair<it,it> ret = my_multiset.equal_range(18);
my_multiset.erase(ret.first,ret.second); // 9,10,15,32
itr = my_multiset.find(32);
my_multiset.erase(itr); // 9,10,15
my_multiset.erase(my_multiset.find(10)); // 9,15
```
```cpp
int a[] = {77,16,2,30,30};
multiset<int> my_multiset(a,a+5);
multiset<int>:: reverse_iterator r_itr;
for(r_itr = my_multiset.rbegin(); r_itr != my_multiset.rend(); r_itr++){
    cout << * r_itr << "," << endl; // 2,16,30,30,77
}
```
```cpp
for(int i=0; i<=5 ;i++){
    my_multiset.insert(i*10); //10,20,30,40,50
}
itr = my_multiset.insert(25);
itr = my_multiset.insert(itr,27); // efficient insertion
itr = my_multiset.insert(itr,29); // hint inserting efficient
itr = my_multiset.insert(itr,24); // not efficient
//[10,20,24,27,29,30,40,50]
int a[] = {5,10,15};
my_multiset.insert(a,a+3);
//[5,10,10,15,20,24,27,29,30,40,50]
```


