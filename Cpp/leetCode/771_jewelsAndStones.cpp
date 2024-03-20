/*


771. Jewels and Stones
Easy
You're given strings jewels representing the types of stones that are jewels, 
and stones representing the stones you have. Each character in stones is a type of stone you have. 
You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0
 

Constraints:

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.
*/
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        std::unordered_set<char> jewelSet;
        int count = 0;
        
        // Populate the set with jewels
        for (char jewel : jewels) {
            jewelSet.insert(jewel);
        }
        
        // Count the stones that are jewels
        for (char stone : stones) {
            if (jewelSet.find(stone) != jewelSet.end()) {// found
                count++;
            }
        }
        
        return count;
    }
};

// Example usage:
int main() {
    Solution sol;
    std::string jewels = "aA";
    std::string stones = "aAAbbbb";
    int result = sol.numJewelsInStones(jewels, stones); // Output: 3
    std::cout << result;
    return 0;
}
