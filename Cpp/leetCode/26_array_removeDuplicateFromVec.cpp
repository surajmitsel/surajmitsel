#include <iostream>
#include <vector>
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

int main() {
  vector<int> vec{1, 2, 2, 2, 2, 3, 3, 3};
  removeDuplicates(vec);

  for (auto x : vec)
    cout << x << ",";
  cout << endl;
}
