#include <array>
#include <iostream>
#include <vector>
using namespace std;

int occureOddNumTime(vector<int> &nums) {
  int find = 0;
  for (auto val : nums) {
    find = find ^ val;
  }
  return find;
}

int main() {
  vector<int> nums{1, 2, 1, 2, 3, 4, 5, 3, 4, 5, 4, 5, 4, 5, 7, 0, 0, 7};  // 7
  if(nums.size() % 2 == 0){
    cout << "even number of elements" << endl;
  }else{
    cout << "occureOddNumTime: " << occureOddNumTime(nums) << endl;
  }
  return 0;
}