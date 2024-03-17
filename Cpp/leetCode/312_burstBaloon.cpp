#include <iostream>
#include <vector>
/*
312. Burst Balloons
Hard

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with 
a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1]
 coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as 
 if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/

class Solution {
public:
    int maxCoins(std::vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    dp[left][right] = std::max(dp[left][right], dp[left][k - 1] + nums[left - 1] * nums[k] * nums[right + 1] + dp[k + 1][right]);
                }
            }
        }
        return dp[1][n];
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {3, 1, 5, 8};
    std::cout << "Maximum number of coins: " << sol.maxCoins(nums) << std::endl;
    return 0;
}
