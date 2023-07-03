#include <iostream>
#include <type_traits>
using namespace std;

int sumDigit(int num) {
  int sum = 0;
  while (num) {
    int pop = num % 10;
    sum = sum + pop;
    num = num / 10;
  }
  return sum;
}
int main() {
  int num = 123056;
  cout << "sumDigit:" << sumDigit(num);
  return 0;
}