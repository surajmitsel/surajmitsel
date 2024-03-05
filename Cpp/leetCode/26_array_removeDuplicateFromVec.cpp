#include <iostream>
#include <vector>
#include <set>

using namespace std;
int removeDuplicates(vector<int> &nums) {
  if (nums.size() <= 1)
    return 0;
  auto it = nums.begin();
  auto it_next = nums.begin() + 1;
  while (it != nums.end() && it_next != nums.end()) {
    if (*it == *it_next) {
      nums.erase(it_next);
      it_next = it + 1;
    } else {
      it = it + 1;
      it_next = it_next + 1;
    }
  }
  return nums.size();
}

int removeDuplicates_set(vector<int> &nums){
  set<int> mySet;

  for(auto i: nums){
    mySet.insert(i);
  }

  nums.clear();

  for(auto i:mySet){
    nums.push_back(i);
  }
}

int main() {
  vector<int> vec1{1, 2, 2, 2, 2, 3, 3, 3};
  removeDuplicates(vec1);
  for (auto x : vec1)
    cout << x << ",";
  cout << endl;

  //----------------------------------------
  vector<int> vec2{1, 2, 2, 2, 2, 3, 3, 3};
  removeDuplicates_set(vec2);
  for (auto x : vec2)
    cout << x << ",";
  cout << endl;

}
