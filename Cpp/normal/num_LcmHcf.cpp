#include <iostream>
#include <type_traits>
using namespace std;
int hcf(int a, int b) {
  if (a == 0)
    return b;
  return hcf(b % a, a);
}

int lcm(int a, int b) { return (a * b) / hcf(a, b); }

// need to make variadic func for LCM and HCF
int main() {
  cout << "hfc:" << hcf(24, 10) << endl;
  cout << "lcm:" << lcm(24, 10) << endl;
  return 0;
}