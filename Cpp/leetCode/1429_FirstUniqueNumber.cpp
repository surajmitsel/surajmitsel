#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>


/*
We use unordered_map to store the frequency of each number, unordered_set to store unique numbers, 
and list to maintain the order of appearance of each number.

In the constructor FirstUnique, we initialize the data structures and 
populate them with the given list of numbers.
*/

// It should maintain always unique number on top
class FirstUnique {
private:
    std::unordered_map<int, int> frequency;
    std::unordered_set<int> unique;
    std::list<int> doublyLinkedList;

public:
    FirstUnique(std::vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        if (!doublyLinkedList.empty()) {
            return doublyLinkedList.front();
        }
        return -1;
    }
    
    void add(int value) {
        if (frequency.find(value) != frequency.end()) {
            if (unique.find(value) != unique.end()) {
                unique.erase(value);
                doublyLinkedList.remove(value);
            }
        } else {
            frequency[value] = 1;
            unique.insert(value);
            doublyLinkedList.push_back(value);
        }
    }
};

// Example usage:
int main() {
    std::vector<int> nums = {2, 3, 5};
    FirstUnique obj(nums);
    std::cout << obj.showFirstUnique() << std::endl; // Output: 2
    obj.add(5);
    std::cout << obj.showFirstUnique() << std::endl; // Output: 2
    obj.add(2);
    std::cout << obj.showFirstUnique() << std::endl; // Output: 3
    obj.add(3);
    std::cout << obj.showFirstUnique() << std::endl; // Output: -1
    
    return 0;
}