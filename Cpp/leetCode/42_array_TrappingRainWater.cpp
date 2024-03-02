#include <iostream>
#include <vector>

using namespace std;
/*
Hard
42. Trapping Rain Water ()
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
// https://www.youtube.com/watch?v=C8UjlJZsHBw
*/

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int left = 0, right = n - 1; // Two pointers
    int maxLeft = 0, maxRight = 0; // Maximum heights encountered from left and right

    int water = 0; // Total amount of trapped water

    while (left < right) {
        if (height[left] <= height[right]) {
            // Update maxLeft and calculate water trapped between height[left] and maxLeft
            maxLeft = max(maxLeft, height[left]);
            water = water + (maxLeft - height[left]);
            left++;
        } else {
            // Update maxRight and calculate water trapped between height[right] and maxRight
            maxRight = max(maxRight, height[right]);
            water = water + (maxRight - height[right]);
            right--;
        }
    }

    return water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Amount of water trapped: " << trap(height) << endl;
    return 0;
}
