#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
/* find if the given number is happy number or not
* eg num = 19
 (1)^2 + (9)^2 = 1 + 81 = 82
 (8)^2 + (2)^2 = 68
 (6)^2 + (8)^2 = 100
 (1)^ + 0 + 0 = 1 so its an happy number


 Eg num = 25
 4 + 25 = 29
 4 + 81 = 85
 64 + 25 = 89 => create loop again
 64 + 81 = 145,42,20,4,16,37,58,89


 so if it creates the loop then we can tell its not happy number
 */

int SumOfSquere(int num) {
  int sum = 0;
  while (num) {
    int d = num % 10;
    sum = sum + d * d;
    num = num / 10;
  }
  return sum;
}
// METHOD1
bool isHappyNum(int num) {
  if (num < 0)
    return false;
  unordered_set<int> mySet;

  // not found then put into set
  while (mySet.find(num) == mySet.end()) { // not found
    mySet.insert(num);
    num = SumOfSquere(num);
    if (num == 1) {
      return true;
    }
  }

  // if same number is found in set again then return false;
  return false;
}

// METHOD2 by finding loop in sum
bool isHappyNum_loop(int num) {
  if (num < 0)
    return false;

  int slow_sum = num;
  int fast_sum = SumOfSquere(num);
  if (slow_sum == 1 || fast_sum == 1)
    return true;

  while (slow_sum != fast_sum) { // found the same again then false
    slow_sum = SumOfSquere(slow_sum);
    fast_sum = SumOfSquere(SumOfSquere(fast_sum));
    if (slow_sum == 1 || fast_sum == 1)
      return true;
  }
  return false;
}
int main() {
  int num = 19;
  std::cout << "isHappyNum:" << isHappyNum(num) << endl;
  std::cout << "isHappyNum_loop:" << isHappyNum_loop(num) << endl;
  return 0;
}
