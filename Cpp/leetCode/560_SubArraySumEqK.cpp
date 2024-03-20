/*

560. Subarray Sum Equals K
Medium

Hint
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
Approach:
This problem can be solved using the prefix sum technique 
along with a hashmap to store the frequency of prefix sums. 
We iterate through the array and keep track of the current sum. 
For each prefix sum encountered, we check if the complement (sum - k) exists in the hashmap.
 If it does, it means there is a subarray whose sum equals k. 
 We increment the count by the frequency of the complement.
*/

int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    unordered_map<int, int> prefixSumFreq;
    prefixSumFreq[0] = 1;
    for (int num : nums) {
        sum += num;
        if (prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
            count += prefixSumFreq[sum - k];
        }
        prefixSumFreq[sum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << "Total number of continuous subarrays with sum " << k << ": " << subarraySum(nums, k) << endl;
    return 0;
}
