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
int expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindrome(string s) {
    if (s.empty()) {
        return "";
    }
    
    int start = 0, end = 0;
    
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int maxLen = max(len1, len2);
        if (maxLen > end - start) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }
    
    return s.substr(start, end - start + 1);
}



int main() {
    cout << longestPalindrome("babad") << endl; // Output: "bab" or "aba"
    cout << longestPalindrome("cbbd") << endl;  // Output: "bb"
    return 0;
}