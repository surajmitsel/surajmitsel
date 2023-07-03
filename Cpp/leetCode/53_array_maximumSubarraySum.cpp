#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
/* Given an integer array nums, find the subarray
 with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 */

int maxSumOfSubArray(vector<int> &nums) {
  if (nums.size() == 0)
    return 0;
  int sum = nums[0];
  int sum_max = nums[0];
  for (int i = 1; i < nums.size(); i++) { // start from 1
    sum = max(sum + nums[i], nums[i]);
    sum_max = max(sum_max, sum);
  }
  return sum_max;
}
int main() {
  vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::cout << "maxSumOfSubArray:" << maxSumOfSubArray(nums) << endl;
  return 0;
}
