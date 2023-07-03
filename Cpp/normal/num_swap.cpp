#include <iostream>
#include <type_traits>
using namespace std;
void swap_1(int *a, int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}
void swap_2(int *a, int *b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}
void swap_3(int *a, int *b) {
  *a = (*a) * (*b);
  *b = (*a) / (*b);
  *a = (*a) / (*b);
}

int main() {
  int a = -10;
  int b = 20;

  swap_1(&a, &b);
  cout << "swap_1:"
       << "a:" << a << ",b:" << b << endl;

  swap_2(&a, &b);
  cout << "swap_2:"
       << "a:" << a << ",b:" << b << endl;

  swap_3(&a, &b);
  cout << "swap_3:"
       << "a:" << a << ",b:" << b << endl;
  return 0;
}