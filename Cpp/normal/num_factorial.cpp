#include <iostream>
#include <type_traits>
using namespace std;

int fac(int num) {
  if (num < 0)
    return 0;
  else if (num > 1)
    return num * fac(num - 1);
  else
    return 1;
}
int main() {
  cout << "factorial:" << fac(5) << endl;
  cout << "factorial:" << fac(-2) << endl;
  return 0;
}