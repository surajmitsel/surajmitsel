#include <iostream>
#include <type_traits>
using namespace std;
// r = 10r + pop
void reverse(int num) {
  int rev = 0;
  while (num) {
    int pop = num % 10;
    rev = rev * 10 + pop;
    num = num / 10;
  }
  std::cout << rev << std::endl;
}
int main() {
  int num = 123450789;
  cout << "reverse:";
  reverse(num);
  return 0;
}