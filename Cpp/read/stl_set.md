## set<> ##
- It is faster as compared to any sequence container
- Insert return the pair of value whether it is inserted the item or not and position of inserted element.
- Element has to be unique, the value of the element cannot be modified once it is added to the set, though it is possible to remove and add the modified value of the element.
- We can erase more than one element by giving start and end iterator position.
- No push_back and push_front method.
- set are implemented using `BST`
- Traversal is using iterator.

```cpp
int main(){
    set<int> a;
    a.insert(12);
    a.insert(10);
    a.insert(20);
    a.insert(10);
    a.insert(90);
    a.insert(85);
    a.insert(45);
    
    set<int> iterator it, it1, it2;
    for(it = a.begin(); it!=a.end(); it++){
        cout << *it << ","; //12,10,20,10,90,85,45
    }
    it1 = a.find(10);
    it2 = a.find(90);

    a.erase(it1,it2); //2,90
    
    return 0;
}
```
```cpp
set<int>:: iterator it;

set<int>myset;
myset.insert(3);
myset.insert(1);
myset.insert(7);

it = myset.find(7); // O(log(n)) it point to 7
pair<set<int>:: iterator , bool> ref;
ref = myset.insert(3);
// 3 already present in the set so no insert is performed,so ref will be set to false, but if it insert new element then it will be set to true.

if(ref.second == false){
    it = ref.first; // now it will be pointing to 3;
}
```
```cpp
set<int>myset{3,1,7};
it = myset.find(3); 
myset.insert(it,9);
```
- Though the it is pointing to 3 but the value 9 is not inserted after 3, because user cannot decide the position of inserting element in set then what is the use of passing parameter it here ?
It actually gives the hint that it can be inserted after 3 if no other big element is present in set, it reduces the time of insertion but the hint should be good.

```cpp
myset.erase(it); // 1,7,9
myset.erase(7); //1,9
```
- None of the sequence container provide this kind of erase
```cpp
set<int> myset{10,20,30,40};
set<int> :: interator itr;
itr = myset.find(40); 
myset.erase(itr);// 10,20,30
myset.erase(myset.find(20)); // 10,30
```
```cpp
int a[] = {12,82,37,64,15};
set<int> first(a,a+5); // first {12,15,37,64,82} sorted 
set<int> second; // empty {}
second = first; // second {12,15,37,64,82}, first {}

```

