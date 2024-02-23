#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverse_str(string &str) { // pass by reference is must
  int len = str.length();
  for (int i = 0; i < (len / 2); i++) {
    swap(str[i], str[len - 1 - i]);
  }
}

void reverseStr_rec(string &str, int i, int len_1) {
  if (i > len_1) { // base case
    return;
  }
  swap(str[i], str[len_1]);
  reverseStr_rec(str, i + 1, len_1 - 1);
}

int main() {
  string str = "suraj verma";
  cout << "inut:" << str << endl;

  reverse_str(str);
  cout << "1.reverse_str:" << str << endl;

  reverseStr_rec(str, 0, str.length() - 1);
  cout << "2.reverseStr_rec:" << str << endl;

  // inbuild
  reverse(str.begin(), str.end());
  cout << "3.inbuild reverse:" << str << endl;
}
