#include <iostream>
#include <vector>
using namespace std;
/*
5. Longest Palindromic Substring
Medium

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/
string longestPalindromSubStr(string str) {
  string result;
  int len = str.length();
  int max_len = 1;
  int st = 0, end = 0;

  for (int i = 0; i < len; i++) {
    int l = i, r = i;
    while (l >= 0 && r < len && (str[l] == str[r])) {
      l--;
      r++;
    }
    int len = r - l - 1;
    if (len > max_len) {
      max_len = len;
      st = i + 1;
      end = r - 1;
    }
  }

  for (int i = 0; i < len; i++) {
    int l = i, r = i + 1;
    while (l >= 0 && r < len && (str[l] == str[r])) {
      l--;
      r++;
    }
    int len = r - l - 1;
    if (len > max_len) {
      max_len = len;
      st = i + 1;
      end = r - 1;
    }
  }

  return str.substr(st, max_len);
}

int main() {
  string str = "babad";
  cout << "longestPalindromSubStr:" << longestPalindromSubStr(str).c_str();
}