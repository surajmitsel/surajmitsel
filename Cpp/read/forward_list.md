## forward_list<> ##
- It is a sequence container that allow constant time insert and erase operation within the sequence
- It is like a single linked list
- The elements are stored in dynamically allocated space.
- Insert and delete happens only from front.
```cpp
forward_list::empty //tells if list is empty is or not.
```
- Require less space because it keeps track of next element but list keeps tack of pervious and next element
- It cannot be interated backward and its individual elements cannot be accessed dynamically.

