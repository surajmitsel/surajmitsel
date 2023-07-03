#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;
/*

15. 3Sum
Medium

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not
matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
*/

/*
solution:
need to first sort the array and then need to take 3 index pointer
i,j from left side and k from right side
add a[i] + a[j] and then find a[k] if addition is zero
need to move j++ if sum is <0
and     move k-- if sum is >0
*/
vector<vector<int>> threeSum(vector<int> &nums) {
  vector<vector<int>> result;
  int size = nums.size();
  if (nums.size() < 3)
    return {};

  // 1.sort the array
  sort(nums.begin(), nums.end());

  // 2. traverse the array
  for (int i = 0; i < size - 2; i++) { // size -2 bcz i,j (0 to size-2)
    if ((i == 0) || nums[i] != nums[i - 1]) {
      int j = i + 1;    // j is next to ith index
      int k = size - 1; // k is last element

      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          result.push_back({nums[i], nums[j], nums[k]});
          while (j < k && nums[j] == nums[j + 1]) // removing duplicate
            j++;
          while (j < k && nums[k] == nums[k - 1]) // removing duplicate
            k--;
          j++;
          k--;
        } else if (sum < 0)
          j++;
        else
          k--;
      } // while loop
    }
  } // for loop
  return result;
}

int main() {
  // vector<int> nums{-1, 0, 1, 2, -1, -4};
  // vector<int> nums{0, 1, 1};
  vector<int> nums{-5, 4, 1, 1, -1, 0, 8, -3, -5, -6 - 2, 8, -1, -2, -3};

  vector<vector<int>> result = threeSum(nums);
  cout << "threeSum:" << endl;
  for (auto x : result) {
    cout << "[";
    for (auto y : x) {
      cout << y << ",";
    }
    cout << "]" << endl;
  }
  return 0;
}