#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;
/*
55. Jump Game
Medium

You are given an integer array nums. You are initially positioned at the array's
first index, and each element in the array represents your maximum jump length
at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump
length is 0, which makes it impossible to reach the last index.
*/


// i + a[i] => denotes the jump and it is an max jump from index 0 
// METHOD1
bool canJump_1(vector<int> &nums) {
  int max_reach = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (i + nums[i] > max_reach) {
      max_reach = i + nums[i];
    }
    // cout << "max_reach:" << max_reach << endl;
    if (max_reach == i)
      break; // Its an stuck condition we can not move 
  }
  return max_reach >= nums.size() - 1;
}
// METHOD2
bool canJump_2(vector<int> &nums) {
  int last_good_index = nums.size() - 1;
  for (int i = nums.size() - 1; i >= 0; i--) {
    if (i + nums[i] >= last_good_index) {
      last_good_index = i;
    }
  }
  return last_good_index == 0;
}

// METHOD3
bool canJump_3(vector<int> &nums) {
  int max_reach = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    if(max_reach < i)
      return false;
    max_reach = max(max_reach, i + nums[i]);
  }
  return true;
}

int main() {
  vector<int> nums{2, 3, 1, 2, 4};
  cout << "canJump_1:" << canJump_1(nums) << endl;
  cout << "canJump_2:" << canJump_2(nums) << endl;
  cout << "canJump_3:" << canJump_3(nums) << endl;

  return 0;
}