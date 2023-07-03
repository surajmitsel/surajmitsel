// over loading () operator is creates the functors
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;
bool are_anagram(const char *str1, const char *str2) {
  int count[256] = {0};
  int i = 0;

  for (i = 0; str1[i] && str2[i]; i++) {
    count[str1[i]]++;
    count[str2[i]]--;
  }

  if (str1[i] || str2[i]) {
    return false;
  }
  for (i = 0; i < 256; i++) {
    if (count[i]) {
      return false;
    }
  }
  return true;
}
int main() {
  string str1{"abcdef"};
  string str2{"febacd"};
  cout << "are_anagram:" << are_anagram(str1.c_str(), str2.c_str()) << endl;
  return 0;
}