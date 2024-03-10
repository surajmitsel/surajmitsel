#include <iostream>
#include <vector>

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
