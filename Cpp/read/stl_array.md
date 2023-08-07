## array<> ##
- Size cannot be changed and stored at contiguous memory location.
- 2 array of integer are having different type like a,b have different type.
```cpp
array<int,3> a = {3,4,5};
array<int,4> b = {10,18,21,9};
```
- zero size array is valid but there should not be dereference.

```cpp
array<int> myArray;
for(int i = i; i < 10; i++){
    myArray.at(i) = i+1;
}
myArray[4];     // 4
myArray.at(4);  // 4
myArray.front();// 1
myArray.back(); // 10
```
```cpp
char * cStr = "Test string";
array<char,12> myArray;
memcpy(myArray.data(), cStr, 12);
myArray.data(); // "Test string"
```
```cpp
array<int,5> first = {1,2,3,4,5};
array<int,5> second = {6,7,8,9,10};
first.swap(second);
// first -> 1,2,3,4,5
// second -> 6,7,8,9,10
```

