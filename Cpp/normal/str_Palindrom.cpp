#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_Palindrom(string str) { // pass value
  for (int i = 0, len = str.length() - 1; i < len; i++, len--) {
    if (str[i] != str[len]) {
      return false;
    }
  }
  return true;
}

int main() {
  string str = "abcd dcba";
  cout << "inut:" << str << endl;
  cout << "is_Palindrom:" << is_Palindrom(str) << endl;
  return 0;
}
