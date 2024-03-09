#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;
/*
18 . 4sum
Medium

Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/
vector<vector<int>> fourSum(vector<int>& nums, long long int target) 
{
    int size = nums.size();
    vector<vector<int>> result;
    if(size < 4){
        return {};
    }
    sort(nums.begin(),nums.end());
    for(int i = 0; i < size-3; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue; // remove dup
        
        for (int j = i+1; j < size-2; j++){
            if(j > i+1 && nums[j] == nums[j-1]) continue; // remove dup
                
            int k = j + 1;
            int z = size -1;
            while(k < z){
                long long int sum = static_cast<long long int> (nums[i] + nums[j] + nums[k] + nums[z]);
                if(sum == target){
                    result.push_back({nums[i], nums[j], nums[k], nums[z]});
                    while (k<z && nums[k] == nums[k+1]) k++;
                    while (k<z && nums[z] == nums[z-1]) z--;
                    
                    k++;
                    z--;
                }
                else if(sum > target){
                    z--;
                }
                else {
                    k++;
                }
            }
        }
    }
    return result;
}


int main() {
  // vector<int> nums{-1, 0, 1, 2, -1, -4};
  int target = 0;
  //vector<int> nums{1,0,-1,0,-2,2}; target = 0;
  vector<int> nums{2,2,2,2,2}; target = 8;

  vector<vector<int>> result = fourSum(nums,target);
  cout << "threeSum:" << endl;
  for (auto x : result) {
    cout << "[";
    for (auto y : x) {
      cout << y << ",";
    }
    cout << "]" << endl;
  }
  return 0;
}