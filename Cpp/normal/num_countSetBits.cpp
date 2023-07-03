#include <iostream>
#include <type_traits>
using namespace std;
int count_set_bit(int val) {
  int cnt = 0;
  while (val) {
    val = val & (val - 1);
    cnt++;
  }
  return cnt;
}

int main() {
  cout << "count_set_bit:" << count_set_bit(0x8A55);
  return 0;
}