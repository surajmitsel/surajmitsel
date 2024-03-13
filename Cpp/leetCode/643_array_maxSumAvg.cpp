#include <iostream>
#include <vector>
/*
643. Maximum Average Subarray I

Easy

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has
 the maximum average value and return this value. 
 Any answer with a calculation error less than 10-5 will be accepted.


Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
*/
double findMaxAverage(std::vector<int>& nums, int k) {
    int left = 0;
    int right = k;
    double curr_sum = 0;
    
    // Calculate sum of the first k elements
    for (int i = 0; i < k; ++i) {
        curr_sum = curr_sum + nums[i];
    }
    
    // Initialize max_avg with the average of the first k elements
    double max_avg = curr_sum / k;
    
    // Slide the window
    while (right < nums.size()) {
        curr_sum = curr_sum + nums[right] - nums[left];
        max_avg = std::max(max_avg, curr_sum / k);
        left++; right++; // Move the window to the right
    }
    
    return max_avg;
}

double findMaxAverage_dp(std::vector<int>& nums, int k) {
    int n = nums.size();
    
    // Calculate prefix sums
    std::vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i] + nums[i];
    }
    
    // Initialize max_avg with the average of the first k elements
    double max_avg = static_cast<double>(dp[k]) / k;
    
    // Slide the window
    for (int i = k + 1; i <= n; ++i) {
        // Calculate the sum of the current window using prefix sums
        int sum = dp[i] - dp[i - k];
        // Update max_avg if the average of the current window is greater
        max_avg = std::max(max_avg, static_cast<double>(sum) / k);
    }
    
    return max_avg;
}

int main() {
    // Example usage
    std::vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    std::cout << "Maximum average: " << findMaxAverage(nums, k) << std::endl;
    std::cout << "Maximum average: " << findMaxAverage_dp(nums, k) << std::endl;
    
    return 0;
}
