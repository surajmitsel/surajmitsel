#include <iostream>
#include <type_traits>
using namespace std;
void fibnacci(int num) {
  int a = 1, b = 0, c = 0;
  while (c <= num) {
    c = a + b;
    a = b;
    b = c;
    std::cout << b << ",";
  }
}
int main() {
  int num = 10;
  cout << "fibnacci:";
  fibnacci(num);
  return 0;
}