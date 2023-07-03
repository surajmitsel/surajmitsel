// Type your code here, or load an example.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  std::cout << "std::vector" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5, 6};
  std::cout << "size:" << vec.size() << std::endl;         // 6
  std::cout << "capacity:" << vec.capacity() << std::endl; // 6
  // push back
  vec.push_back(20);

  std::cout << "size:" << vec.size() << std::endl;         // 7
  std::cout << "capacity:" << vec.capacity() << std::endl; // 12

  // reduce the capacity
  vec.shrink_to_fit();
  std::cout << "size:" << vec.size() << std::endl;         // 7
  std::cout << "capacity:" << vec.capacity() << std::endl; // 7

  // push back by moving // NO push_front API
  int x = 11;
  vec.push_back(std::move(x));

  // Print the vector
  for (auto &i : vec) {
    std::cout << i << ","; // no * used
  }
  std::cout << std::endl;

  // Print the vector
  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << ","; // * is used
  }
  std::cout << std::endl;
  // search element in vector
  int find = 20;
  auto it = std::find(vec.begin(), vec.end(), find);
  if (it != vec.end()) {
    std::cout << "found the value:" << find << std::endl;
  }
  std::cout << "*it:" << *it << std::endl;

  // search element in vector
  find = 5;
  auto itr = std::find_if(vec.begin(), vec.end(), [&find](auto &x) {
    if (x == find) {
      std::cout << "find the value:" << find << std::endl;
      return true;
    }
    return false;
  });
  std::cout << "*itr:" << *itr << std::endl;

  // insert element into vector
  vec.insert(itr, 75);
  for (auto &i : vec) {
    std::cout << i << ",";
  }
  std::cout << std::endl;
}