#include <iostream>
#include <vector>
#include <unordered_map>
/*

525. Contiguous Array
Medium

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 
Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/
class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        if(nums.size() <= 1){
            return 0;
        }
        std::unordered_map<int, int> countMap; // Stores the count of 0s and 1s encountered
        int maxLength = 0;
        int count = 0; // Tracks the difference between count of 0s and 1s

        // Initialize the map with 0 count at index -1
        countMap[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            // Increment count for 1, decrement for 0
            count = (nums[i] == 1) ? count + 1 : count - 1;

            // If count is already present in the map, update max length
            if (countMap.find(count) != countMap.end()) {
                maxLength = std::max(maxLength, i - countMap[count]);
            } else {
                // Otherwise, store the current index for this count
                countMap[count] = i;
            }
        }
        return maxLength;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1};
    std::cout << "Maximum length: " << sol.findMaxLength(nums) << std::endl;
    return 0;
}
