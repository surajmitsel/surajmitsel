
#include <algorithm>
#include <iostream>
#include <vector>

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
    int newRob = norob + nums[i];
    int newNoRob = max(norob, rob);
    rob = newRob;
    norob = newNoRob;
  }
  return max(rob, norob);
}

int main() {
  vector<int> house{2, 7, 9, 3, 1};
  // std::cout << "max_robber:" << max_robber(house) << endl;
  std::cout << "max_rob_dp:" << max_rob_dp(house) << endl;
}