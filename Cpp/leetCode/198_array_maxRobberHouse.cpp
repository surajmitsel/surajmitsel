
#include <algorithm>
#include <iostream>
#include <vector>
/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping 
you from robbing each of them is that adjacent houses have security systems connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/
using namespace std;

// METHOD1 dynamic programming
// need to take the decision wheather next house to be robbed or not to be
// robbed based upon comparing max( cur + till_prev_prev, till_prev)
int max_rob_dp(vector<int> &nums) {
  if (nums.size() < 1)
    return 0;
  if (nums.size() == 1)
    return nums[0];

  vector<int> dp(nums.size(), 0); // need to initialized with size and value
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);
  for (int i = 2; i < nums.size(); i++) {
    dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
  }
  return dp[nums.size() - 1]; // because it will have one less size
}

// METHOD2
int max_robber(vector<int> &nums) {
  int rob = 0;
  int norob = 0;
  for (int i = 0; i < nums.size(); i++) {
    int new_rob = norob + nums[i];
    int new_norob = max(norob, rob);
    rob = new_rob;
    norob = new_norob;
  }
  return max(rob, norob);
}

int main() {
  vector<int> house{2, 7, 9, 3, 1};
  // std::cout << "max_robber:" << max_robber(house) << endl;
  std::cout << "max_rob_dp:" << max_rob_dp(house) << endl;
}