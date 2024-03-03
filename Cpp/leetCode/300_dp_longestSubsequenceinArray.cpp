#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;
/*
300. Longest Increasing Subsequence
Medium

Given an integer array nums, return the length of the longest strictly
increasing subsequence

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
*/

/*
solution 1:
ans =1,
1. dp[n] => 1
2. for (i -> 0-n)
      for (j -> i to 0)
        if (nums[j] < nums[i])
          dp[i] = max[dp[i], dp[j]+1]
          ans= max(ans,dp[i])
*/
int lengthOfLIS_1(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1); // Initialize dp array with 1s

    int maxLength = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                maxLength = max(maxLength, dp[i]);
            }
        }
    }

    return maxLength;
}

// METHOD2:
/*
  take the res vector which will only maitain the length for subsequece
  the data may not be actual longest subsequecnce

  1. vec res(size)
  2. find lower bound(<=) in res vec
     if end => num[i] => push to end of res
     if not end => it replace with nums[i]
  3. return length of res
*/
int lengthOfLIS_2(vector<int> &nums) {
  vector<int> res;
  for (int i = 0; i < nums.size(); i++) {
    // get the it of lower value index then current value
    auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
    
    if (it != res.end()){
      //cout <<"*it" << *it << "," << nums[i] << endl;
      *it = nums[i]; // replace the value if found
      // for(int x:res)
      //   cout << x << ",";
      // cout <<endl;
    }
    else{
      res.push_back(nums[i]); // append it end if not found
      // for(int x:res)
      //   cout << x << ",";
      // cout <<endl;
    }
  }
  return res.size();
}

int main() {
  // vector<int> nums{2, 3, 1, 2, 4};          // 234 124 op = 3
  vector<int> nums{1, 2, 7, 8, 3, 4, 5, 9}; // 123459 op = 6
  //vector<int> nums{7, 7, 7, 7, 7, 7, 7}; // 7 op = 1
  // vector<int> nums{0, 1, 0, 3, 2, 3}; // 0123  op = 4
  cout << "lengthOfLIS_1:" << lengthOfLIS_1(nums) << endl;
  cout << "lengthOfLIS_2:" << lengthOfLIS_2(nums) << endl;

  return 0;
}