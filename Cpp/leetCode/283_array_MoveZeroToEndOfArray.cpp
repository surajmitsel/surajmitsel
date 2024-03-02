#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
/* Given an integer array nums, move all 0's to the end of it
while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 */

void moveZeroEndOfArray(vector<int>& nums) {
    int nonZeroIndex = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            swap(nums[i], nums[nonZeroIndex]);
            nonZeroIndex++;
        }
    }
}

int main() {
  vector<int> nums{0, 1, 0, 3, 12, 0, 15, 18, 0, 75, 0};
  std::cout << "moveZeroEndOfArray:";
  moveZeroEndOfArray(nums);
  for (auto x : nums)
    cout << x << ",";
  cout << endl;
  return 0;
}
