#include <iostream>
#include <vector>

using namespace std;
/*
34. Find First and Last Position of Element in Sorted Array

Medium

Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

vector<int> searchRange(vector<int>& nums, int target) 
{
    int start = -1; 
    int end = -1;
    int left = 0;
    int right = nums.size() - 1;
    
    // Search for the leftmost occurrence of the target
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]){
            start = mid;
            right = mid - 1;
        }
        else if (target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    // If target not found, return [-1, -1]
    if (start == -1) return {-1, -1};
    
    left = 0;
    right = nums.size() - 1;
    
    // Search for the rightmost occurrence of the target
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]){
            end = mid;
            left = mid + 1;
        }
        else if (target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return {start, end};
}
int main() {
    std::vector<int> nums = {5, 7, 7, 8, 8, 8, 9, 9, 10, 11};
    int target = 8;
    
    std::vector<int> result = searchRange(nums, target);
    std::cout << "Start: " << result[0] << ", End: " << result[1] << std::endl;
    
    return 0;
}