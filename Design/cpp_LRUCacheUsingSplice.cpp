#include <iostream>
#include <unordered_map>
#include <list>
/*
A Least Recently Used (LRU) cache is a data structure that maintains a 
fixed-size cache of key-value pairs. When the cache reaches its maximum capacity 
and a new key-value pair needs to be added, the least recently used item is evicted
from the cache to make room for the new item.

Here's a simple implementation of an LRU cache in C++ using a combination 
of a doubly linked list and an unordered map:
*/

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node(int k, int v) : key(k), value(v) {}
    };
    
    int capacity;
    std::list<Node> cacheList;
                    // key, interator in list pos
    std::unordered_map<int, std::list<Node>::iterator> cacheMap;
    
    // Move a node to the front of the list
    void moveToFront(std::list<Node>::iterator it) {
        cacheList.splice(cacheList.begin(), cacheList, it);
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1; // Key not found
        }
        // Move the accessed node to the front of the list
        moveToFront(cacheMap[key]);
        return cacheMap[key]->value;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Key already exists, update the value and move it to the front
            cacheMap[key]->value = value;
            moveToFront(cacheMap[key]);
        } else {
            // Key does not exist
            if (cacheList.size() == capacity) {
                // Evict the least recently used item
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            // Insert the new node to the front of the list
            cacheList.push_front(Node(key, value));
            cacheMap[key] = cacheList.begin();
        }
    }
};

int main() {
    // Create a cache with capacity 2
    LRUCache cache(2);

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
