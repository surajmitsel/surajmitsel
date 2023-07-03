#include <iostream>
#include <map>
#include <string>

// IVXLCDM
using namespace std;
int romanToInt(std::string s) {
  int len = s.length();
  int result = 0;

  std::map<char, int> mp;
  mp.insert(make_pair<char, int>('I', 1));
  mp.insert(make_pair<char, int>('V', 5));
  mp.insert(make_pair<char, int>('X', 10));
  mp.insert(make_pair<char, int>('L', 50));
  mp.insert(make_pair<char, int>('C', 100));
  mp.insert(make_pair<char, int>('D', 500));
  mp.insert(make_pair<char, int>('M', 1000));

  char prev;
  for (int i = len - 1; i >= 0; i--) {
    if ((s[i] == 'I' && (prev == 'V' || prev == 'X')) ||
        (s[i] == 'X' && (prev == 'L' || prev == 'C')) ||
        (s[i] == 'C' && (prev == 'D' || prev == 'M'))) {
      result -= mp[s[i]];
    } else
      result += mp[s[i]];
    prev = s[i];
  }
  return result;
}

int main() { cout << "romanToInt:" << romanToInt("CI") << endl; }