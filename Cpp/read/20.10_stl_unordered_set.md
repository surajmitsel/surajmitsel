## unordered_set<> ##
- Container that store unique elements in no particular order and which allow for fast retrieved individual elements based on their value.
- In an unordered_set the value of the elements is at same time it is also a key that identifies it uniquly.
- element cannot be modified because they acts like key but they can be inserted and removed.
- All operation on the unordered_set takes constant time O(1) and an average which can go up to linerar time O(n) in worst case.
- unordered_set can contain key of anytype.
- when we define key of user defined type then we need to specify our own comparision function accordingly to which key will be compared.
- set opereation is O(log n) where as unordered_set it is O(1)
- find, insert, and erase takes constant time on average.
- The iterator works as pointer to the key value so that we can get the key by dereferencing then using * operator.
```cpp
int main(){
    unordered_set<string> stringSet;
    stringSet.insert("code");
    stringSet.insert("in");
    stringSet.insert("c++");
    stringSet.insert("is");
    stringSet.insert("fast");
    string key = "slow";

    // find returns end iterator if key is not found or else it return iterator to that key

    if(stringSet.find(key) == stringSet.end())
        cout << key << " not found" << endl;
    key = "c++";

    if(stringSet.find(key) != stringSet.end())
        cout << key << " found" << endl;

    for (itr = stringSet.begin(); itr != stringSet.end(); itr++)
        cout << *itr << endl;

    return 0;
 }
 /* output
  slow not found
  c++ found
  is 
  fast
  c++
  in 
  code
*/
 ```
 ```cpp
 //find all duplicate elements among them
 // duplicates are 5,2,1
 int main(){
    int a[] = {1,5,2,1,4,3,1,7,2,8,9,5}; 
    int n  = sizeof(a)/sizeof(a[0]);
    printDuplicate(array,n);
    return 0;
 }
 void printDuplicate(int array[], int n){
    unordered_set<int> intSet;
    unordered_set<int> duplicate;
    for(int i=0; i<n; i++){
        if(intSet.find(array[i]) == inset.end()){
            inset.insert(array[i]);
        }else{
            duplicate.insert(array[i]);
        }
    }

    unordered_set<int>::iterator itr;
    for(itr = duplicate.begin(); itr != duplicate.end(); itr++){
        cout << *itr << ",";
    }

    //output
    // 5,2,1,
 }
 ```
 ```cpp
 unordered_set<string> myset = {"red","green","blue"};
 auto itr = myset.find("green");
 if(itr != myset.end()){
    cout << *itr++ << ",";
 }
 myset.insert("yellow"); // O(1)
 ```


