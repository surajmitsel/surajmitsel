#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
/* find the index of the two elements which is having is sum = target
 */

// METHOD1: using given vector
vector<int> findTwoSum(vector<int> &nums, int target) {
  vector<int> result;
  for (auto it1 = nums.begin(); it1 != nums.end(); it1++) {
    auto it2 =
        std::find(it1 + 1, nums.end(), target - *it1); // start from next pos
    if (it2 != nums.end()) {                           // found
      result.push_back(it1 - nums.begin());
      result.push_back(it2 - nums.begin());
      return result;
    }
  }
  return result;
}

// METHOD2: using hash map
vector<int> findTwoSum_hash(vector<int> &nums, int target) {
  vector<int> result;
  unordered_map<int, int> myMap; // <value,index>
  for (int i = 0; i < nums.size(); i++) {
    int val = nums[i];
    int complement = target - val;
    auto it = myMap.find(complement);
    if (it != myMap.end()) { // found
      return {it->second, i};
    }
    myMap[val] = i; // if not found then insert value and index
  }
  return result;
}
int main() {
  vector<int> nums{12, 9, 7, 11, 1, 10};
  int traget = 20; // ouput: 1,3
  vector<int> result = findTwoSum(nums, traget);
  std::cout << "findTwoSum:";
  for (auto x : result) {
    cout << x << ",";
  }
  cout << endl;

  vector<int> result1 = findTwoSum_hash(nums, traget);
  std::cout << "findTwoSum_hash:";
  for (auto x : result1) {
    cout << x << ",";
  }
  return 0;
}