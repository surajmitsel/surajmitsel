
#include <list>
#include <unordered_map>

// It should maintain always unique number on top

class FirstUnique {
private:
    std::list<int> uniqueList; // value inseted from back
    //<value, list position>
    std::unordered_map<int, std::list<int>::iterator> freqMap;

public:
    FirstUnique(std::vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }

    void add(int value) {
        if (freqMap.find(value) == freqMap.end()) { //not found
            uniqueList.push_back(value);
            freqMap[value] = std::prev(uniqueList.end());
        } else {
            auto it = freqMap[value];
            if (it != uniqueList.end()) { // found
                uniqueList.erase(it);
                freqMap[value] = uniqueList.end();
            }
        }
    }

    int showFirstUnique() {
        if (uniqueList.empty()) {
            return -1;
        }
        return uniqueList.front();
    }

    
};

// Example usage:
int main() {
    std::vector<int> nums = {2, 3, 5};
    FirstUnique* obj = new FirstUnique(nums);
    std::cout << obj->showFirstUnique() << std::endl; // Output: 2
    obj->add(5);
    std::cout << obj->showFirstUnique() << std::endl; // Output: 2
    obj->add(2);
    std::cout << obj->showFirstUnique() << std::endl; // Output: 3
    obj->add(3);
    std::cout << obj->showFirstUnique() << std::endl; // Output: -1
    delete obj;
    return 0;
}
