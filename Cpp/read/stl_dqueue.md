## deque<> ##
- It’s a double ended queue. 
- It is a sequence container with dynamic in size that can expanded or contracted on both sides either front or on back.
- its similar interface like vector
- It does not provide contiguous memory but vector provide that
- It provide random access
- Fast insert/remove at the beginning and at the end
- Slow insert/remove at the middle: O(n)
- Slow search: O(n)
- Accessing elements in a deque by offsetting a pointer to another element causes undefined behaviour.
- For operation that involves frequent insertion or removal of element at position other than beginning or at the end perform worst and have less consistent iterator and reference then list and forward list.
- operator `[]` returns a reference to the element at position n in a container. It’s like similar to deque::at except deque::at is bound checked and signals of requested position is out of range by throwing out of range exception.

```cpp
// 1. create
deque<int> deq = {4,5,6};

// 2. insert front and back
deq.push_front(3); // {3,4,5,6}
deq.push_back(6);  // {3,4,5,6,6}
deq.emplace_front(2); // {3,4,5,6}
deq.emplace_back(8);  // {2,3,4,5,6,6,8}

// 3. update at pos
deq.at(6) = 7   // {2,3,4,5,6,7,8}

// 4. traverse
for(deque<int>::interator it = deq.begin();
     it != deq.end(); it++){
        cout << *it << endl;
}

// 5. insert
deque<int>:: iterator it = deq.begin();
it = deq.insert(it,10); // 3,10,4,5,6,7
deq.insert(it,2,20); // 3,20,20,10,4,5,6,7

it = deq.begin() + 2;
it = deq.insert(it,2,30) // 3,20,30,30,20,10,4,5,6,7

// remove last element
deq.pop_front();
deq.pop_back();

// remove element from position
deq.erase(deq.begin() + 5);

// 5. clear
deq.clear();

```



