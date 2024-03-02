#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
217. Contains Duplicate
Easy

Given an integer array nums, return true if any value appears at least twice in
the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

/*

*/

// METHOD1: with extra space of L,R
bool containsDuplicate(vector<int> &nums) {
  unordered_set<int> mySet;
  for(auto x:nums){
    if(mySet.find(x) != mySet.end()){
      return true;
    }
    mySet.insert(x);
  }
  return false;
}

int main() {
  //vector<int> vec{1, 2, 3, 1};
  vector<int> vec{1,1,1,3,3,4,3,2,4,2};

  cout << "containsDuplicate:" << containsDuplicate(vec);
}
