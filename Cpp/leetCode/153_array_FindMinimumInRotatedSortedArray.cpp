#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

/*
Suppose an array of length n sorted in ascending order is rotated between 1 and
n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum
element of this array.

You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Example 3:
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
*/

// METHOD1: using std::algo
int findMinInRottedArray_1(vector<int> &nums) {
  return *min_element(nums.begin(), nums.end());
}

// METHOD2: Binary Search iterative
int findMinInRottedArray_2(vector<int> &nums) {
  int l = 0;
  int r = nums.size() - 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (nums[mid] > nums[r])
      l = mid + 1;
    else
      r = mid;
  }
  return nums[l];
}

// METHOD3: Binary Search recursive
int bSearch(vector<int> &nums, int l, int r) {
  if (l == r)
    return nums[l];

  int mid = l + (r - l) / 2;

  if (nums[mid] < nums[r])
    return bSearch(nums, l, mid);

  if (nums[mid] > nums[r])
    return bSearch(nums, mid + 1, r);

  return nums[r];
}
int findMinInRottedArray_3(vector<int> &nums) {
  return bSearch(nums, 0, nums.size() - 1);
}

int main() {
  vector<int> nums{3, 4, 5, 1, 2};
  // vector<int> nums{4, 5, 6, 7, 0, 1, 2};
  // vector<int> nums{11, 13, 15, 17};
  cout << "findMinInRottedArray_1:" << findMinInRottedArray_1(nums) << endl;
  cout << "findMinInRottedArray_2:" << findMinInRottedArray_2(nums) << endl;
  cout << "findMinInRottedArray_3:" << findMinInRottedArray_3(nums) << endl;
  return 0;
}