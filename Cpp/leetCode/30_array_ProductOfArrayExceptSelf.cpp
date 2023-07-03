#include <iostream>
#include <vector>
using namespace std;
/*
238. Product of Array Except Self
Medium
17.3K
949
Companies
Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
integer.

You must write an algorithm that runs in O(n) time and without using the
division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/
/*
  solution: need to creare left prouct and right product array
  and the result = L[i] * R[i]

  for eg [1,2,3,4]
  L[] = [1,1,2*1,3*2]  => [1,1,2,6]
  R[] = [2*3*4,3*4,4*1,1]  => [24,12,4,1]
  result = [24,12,8,6]
*/

// METHOD1: with extra space of L,R
vector<int> productArrayExceptSelf(vector<int> &nums) {
  int size = nums.size();
  vector<int> L(size, 1); // left product with size and initialize with 1
  vector<int> R(size, 1); // right product with size and initialize with 1
  vector<int> result(size, 1);

  for (int i = 1; i < size; i++)
    L[i] = L[i - 1] * nums[i - 1];

  for (int i = size - 2; i >= 0; i--)
    R[i] = R[i + 1] * nums[i + 1];

  for (int i = 0; i < size; i++)
    result[i] = L[i] * R[i];

  return result;
}

// METHOD2: without extra space we can add into result itself
vector<int> productArrayExceptSelf_withoutES(vector<int> &nums) {
  int size = nums.size();
  vector<int> result(size, 1);

  for (int i = 1; i < size; i++)
    result[i] = result[i - 1] * nums[i - 1]; // till here we have Left product

  int right_prod = nums[size - 1]; // right product is calculated on the fly
  for (int i = size - 2; i >= 0; i--) {
    result[i] = result[i] * right_prod;
    right_prod = right_prod * nums[i];
  }

  return result;
}

int main() {
  vector<int> vec{1, 2, 3, 4};
  // vector<int> vec{-1, 1, 0, -3, 3};
  vector<int> result = productArrayExceptSelf(vec);

  cout << "productArrayExceptSelf:";
  for (auto x : result)
    cout << x << ",";
  cout << endl;

  vector<int> result1 = productArrayExceptSelf_withoutES(vec);
  cout << "productArrayExceptSelf_withoutES:";
  for (auto x : result1)
    cout << x << ",";
  cout << endl;
}
