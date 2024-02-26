#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
/*152. Maximum Product Subarray
Medium

Given an integer array nums, find a
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

/*
kednes algorithm
T: O(n)
S: O(1)
*/
int maxProductOfSubArray(vector<int> &nums) {
  if (nums.size() == 0)
    return 0;
  int max_overall = nums[0];
  int max_end_here = nums[0];
  int min_end_here = nums[0];
  for (int i = 1; i < nums.size(); i++) { // start from 1
    int temp = max_end_here;
    max_end_here = max({nums[i], nums[i] * max_end_here, nums[i] * min_end_here});
    min_end_here = min({nums[i], nums[i] * temp, nums[i] * min_end_here}); // since max ending here already updated so 
                                                                            //taken previous value of max_end_here
    max_overall = max(max_overall, max_end_here);
  }
  return max_overall;
}
int main() {
  vector<int> nums{2, 3, -2, 4};
  std::cout << "maxProductOfSubArray:" << maxProductOfSubArray(nums) << endl;
  return 0;
}
