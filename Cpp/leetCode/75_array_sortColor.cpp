#include <iostream>
#include <vector>
#include <set>

using namespace std;


/*
75. Sort Colors
Medium

Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?


Solution: To solve this problem, you can use the Dutch National Flag Algorithm (DNF), 
also known as the three-way partitioning algorithm. 
The idea is to partition the array into three sections: 
the red section (0s), the white section (1s), and the blue section (2s). 
You maintain three pointers: one for the current position (mid),
 one for the end of the red section (low), and one for the start of the blue section (high).
  You iterate through the array, swapping elements to move 0s to the beginning and 2s to the end, 
  while keeping 1s in the middle.
*/

void sortColors_1(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // it is 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}


int main() {
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sortColors_1(nums1);
    cout << "Sorted colors for nums1: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {2, 0, 1};
    sortColors_1(nums2);
    cout << "Sorted colors for nums2: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {2, 0, 1, 1, 2, 1, 0, 0, 2 ,1};
    sortColors_1(nums3);
    cout << "Sorted colors for nums3: ";
    for (int num : nums3) {
        cout << num << ",";
    }
    cout << endl;

    return 0;
}
