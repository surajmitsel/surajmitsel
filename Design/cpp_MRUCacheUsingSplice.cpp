#include <iostream>
#include <unordered_map>
#include <list>

/*
A Most Recently Used (MRU) cache is a data structure that stores a fixed number of items, 
where the most recently accessed item is retained and the least recently accessed 
item is discarded when the cache reaches its capacity.

Here's a simple implementation of an MRU cache in C++ using a combination of a
doubly linked list and an unordered map:
*/
class MRUCache {
private:
    struct Node {
        int key;
        int value;
        Node(int k, int v) : key(k), value(v) {}
    };
    
    int capacity;
    std::list<Node> cacheList;
                       //key, list iterator pos
    std::unordered_map<int, std::list<Node>::iterator> cacheMap;
    
    // Move a node to the front of the list
    void moveToFront(std::list<Node>::iterator it) {
        cacheList.splice(cacheList.begin(), cacheList, it);
    }

public:
    MRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1; // Key not found
        }
        // Move the accessed node to the front of the list
        moveToFront(cacheMap[key]);
        return cacheMap[key]->value;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) { //found
            // Key already exists, update the value and move it to the front
            cacheMap[key]->value = value;
            moveToFront(cacheMap[key]);
        } else {
            // Key does not exist
            if (cacheList.size() == capacity) {
                // Evict the most recently used item
                cacheMap.erase(cacheList.front().key);
                cacheList.pop_front();
            }
            // Insert the new node to the front of the list
            cacheList.push_front(Node(key, value));
            cacheMap[key] = cacheList.begin();
        }
    }
};

int main() {
    // Create an MRU cache with capacity 2
    MRUCache cache(2);

    // Put key-value pairs into the cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Get and print the value of key 1
    std::cout << cache.get(1) << std::endl; // Output: 1

    // Put a new key-value pair into the cache, which evicts key 2
    cache.put(3, 3);

    // Get and print the value of key 2 (should return -1)
    std::cout << cache.get(2) << std::endl; // Output: -1

    return 0;
}
