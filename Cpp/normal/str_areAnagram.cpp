// over loading () operator is creates the functors
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;
bool are_anagram_1(const char *str1, const char *str2) {
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

bool are_anagram_2(const std::string& str1, const std::string& str2) {
    // If the lengths of the strings are different, they cannot be anagrams
    if (str1.length() != str2.length()) {
        return false;
    }

    // Count the frequency of characters in str1
    std::unordered_map<char, int> charCount;
    for (char c : str1) {
        charCount[c]++;
    }

    // Subtract the frequency of characters in str2
    for (char c : str2) {
        charCount[c]--;
        // If any character count becomes negative, the strings are not anagrams
        if (charCount[c] < 0) {
            return false;
        }
    }

    // If all character counts are zero, the strings are anagrams
    return true;
}

int main() {
  string str1{"abcdef"};
  string str2{"febacd"};
  cout << "are_anagram:" << are_anagram_1(str1.c_str(), str2.c_str()) << endl;
  cout << "are_anagram:" << are_anagram_2(str1.c_str(), str2.c_str()) << endl;
  return 0;
}