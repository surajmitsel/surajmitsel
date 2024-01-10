## list<> ##
- It is a doubly linked list
- list are sequential container that allows you constant time insert and deletion operation anywhere within the sequence and iteration in both direction.
- it allow non-contiguous memory allocation. As compared to the vector, the list has slow traversal, but once a position has been found, insertion and deletion are quick (constant time).
- Fast insert/remove at anyplace : O(1)
- Slow search: O(n) {slower than vector}
- No random access no [] operator
- Consume more memory than vector, its having two pointer
- Its having one function `splice` which other container does not have.

```cpp
// create
list<int> myList = {5,2,9};

// update
myList.push_back(6); //myList{5,2,9,6}
myList.push_front(4); //myList{4,5,2,9,6}

// traverse
for(auto it = mylist.begin(); it != mylist.end(); it++);{
    cout << *it;
}

// search
list<int>::iterator itr;
itr = find(mylist.begin(),mylist.end(),2); // point to 2

// insert
mylist.insert(itr,8);   // myList{4,5,8,2,9,6} // still point to 2
itr++; // point to 9
mylist.erase(itr);      // myList{4,5,8,2,6}

// splice 
// It merge the data of mylist1 (range itr_a, itr_b) into list1
// at itr position
list<int>mylist1 = {4,5,8,9,6}; // itr point to 8
list<int>mylist2 = {1,2,3,7,12}; // itr_a -> 2 , itr_b -> 7
mylist1.splice(itr, mylist2, itr_a, itr_b);

// remove
list<int> myList{1,2,2,2,2,5,6,7};
myList.remove(2); // {1,5,6,7}

//remove even
bool even(const int & val) {return (val % 2) == 0;}
int main(){
    list <int> myList {1,2,2,2,2,5,7};
    myList.remove_if(even); // 1,5,7
    return 0;
}

// backward print
int main(){
    list<int> myList;
    for(int i; i<=5; i++){
        myList.push_back(i);
    }
    for(list<int>::reverse_iterator rit = mylist.rbegin(); 
                                    rit != rend(); rit++){
        cout << *rit <<"," << endl;
    }
    // 5,4,3,2,1 complexity is O(1)
}
```

