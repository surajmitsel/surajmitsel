#include <iostream>
using namespace std;

int sumFactors(int num) {
  int sum = 0;
  for (int i = 1; i <= num; i++) { // 1 to <=num
    if (num % i == 0) {
      sum += i;
    }
  }
  return sum;
}
int main() {
  int num = 24; // 1+2+3+4+6+8+12+24
  cout << "sumFactors:" << sumFactors(num);
  return 0;
}