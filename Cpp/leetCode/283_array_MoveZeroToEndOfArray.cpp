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

void moveZeroEndOfArray(vector<int> &nums) {
  if (nums.size() <= 1)
    return;

  int z = 0;  // Zero index always left to non zero
  int nz = 1; // non zero index always ahead of zero index

  while (z < nums.size() && nz < nums.size() && z < nz) {

    while (z < nums.size() && nums[z] != 0)
      z++; // moving z toward zero value index

    if (nz < z)
      nz = z + 1;

    while (nz < nums.size() && nums[nz] == 0)
      nz++; // moving nz toward non zero value index

    if (nz <= z || nz >= nums.size() || z >= nums.size())
      return;

    // swap none zero to zero location
    nums[z] = nums[nz];
    nums[nz] = 0;
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
