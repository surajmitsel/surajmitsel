// over loading () operator is creates the functors
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;
bool is_prime_rec(int num, int div) {
  if (div == 1 || div == 0)
    return true;
  else if (num % div == 0)
    return false;
  else
    return is_prime_rec(num, div - 1);
}
bool is_prime(int num) {
  if ((num & 0x01) == 0) { // remove even
    return false;
  }
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

void print_prime_up_to_num(int num){
    int i = 1;
    while(num > 1) {
        if(is_prime(num))
            cout << num << " ";
        num--;
    }
}
int main() {
  int val = 53;
  cout << "is_prime:" << is_prime(val) << endl;
  cout << "is_prime_rec:" << is_prime_rec(val, val / 2) << endl;
  print_prime_up_to_num(10);
  return 0;
}