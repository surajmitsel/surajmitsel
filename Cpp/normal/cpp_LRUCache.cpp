#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
using namespace std;

// LRU cache is like a map <key,value>
class LRUCache {
  int capacity{0};
  std::list<int> key_list; // making queue & always keeping recent item on top
  // Storing 3 things: <key, pair<value,position of key in list>>
  std::unordered_map<int, std::pair<int, std::list<int>::iterator>> myMap;

public:
  // constructor
  LRUCache(int capacity) : capacity(capacity) {}

  // get API
  int get(int key) {
    if (myMap.find(key) != myMap.end()) { // found the key
      key_list.erase(myMap[key].second);
      key_list.push_front(key);             //*******push Front
      myMap[key].second = key_list.begin(); // updating
      return myMap[key].first;              // returing value
    }
    return -1;
  }

  // put API
  void put(int key, int value) {
    if (myMap.find(key) != myMap.end()) { // found the key
      key_list.erase(myMap[key].second);
      key_list.push_front(key); //*******push Front
      myMap[key] = {value, key_list.begin()};
    } else { // Not found need to push and update position
      // reached to maximum capacity then errage last
      if (key_list.size() >= capacity) {
        myMap.erase(key_list.back());
        key_list.pop_back();
      }
      key_list.push_front(key); //*******push Front
      myMap[key] = {value, key_list.begin()};
    }
  }

  // print
  void print() {
    cout << "LRU key sequence:";
    for (auto it : key_list) {
      std::cout << it << ",";
    }
    cout << endl;
  }
};

int main() {
  LRUCache *lru = new LRUCache(5);
  // <key,value> its like a map
  // Least recently used:

  // This difines the replacement policy
  // eg. when cache is full and if new the element is requested
  // which is not present in cache then this new element will be replacing
  // the element which is least used
  // keep most recent in begining always

  lru->put(1, 10);
  lru->put(2, 20);
  lru->put(3, 30);
  lru->put(4, 40);
  lru->put(5, 50);

  lru->print();

  std::cout << lru->get(1) << endl;
  std::cout << lru->get(5) << endl;
  std::cout << lru->get(3) << endl;
  std::cout << lru->get(2) << endl;
  std::cout << lru->get(4) << endl;
  lru->print();

  lru->put(5, 70);

  lru->print();

  return 0;
}
