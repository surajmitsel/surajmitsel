
## multimap<> ##
- It is a map that allows duplicate key.
- The value of the key in a multimap cannot be modified.
- Once it is in the container the elements are always const but they can be inserted or removed from the container.
- All elements are always sorted internally in multiset based on key.
- multiset containers are generally slower than unordered_multimap container to access individual elements by their key.
- multimap typically implemented as binary search tree.
- key cannot be modified.
```cpp
multimap<char,int> mymap;

(*itr).first = 'd'; //error

multimap<char,int> mymultimap;
multimap<char,int> ::iterator itr;
mymultimap.insert(pair<char,int>('a',100));
mymultimap.insert(pair<char,int>('z',150));
itr = mymultimap.insert(pair<char,int>('b',75));

// insert with hint of position
mymultimap.insert(pair<char,int>('c',300));
mymultimap.insert(pair<char,int>('z',400));
// mymultimap
// a 100
// b 75
// c 300
// z 150
// z 400
```
- operator[] is not overloaded in multimap
```cpp
multimap.erase(itr); // erase by interator
multimap.erase('z'); // erase by key z element
```