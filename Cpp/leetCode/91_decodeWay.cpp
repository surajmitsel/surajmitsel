#include <iostream>
#include <vector>
#include <string>

/*
91. Decode Ways
Medium

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back 
into letters using the reverse of the mapping above (there may be multiple ways). 
For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped 
into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:
Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
 
Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/

using namespace std;

int numDecodings_1(string s) {
    int n = s.length();
    if (n == 0) return 0;
    if (s[0] == '0') return 0;
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        // first digit
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        // Next digit
        int twoDigits = stoi(s.substr(i - 2, 2));
        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}

int numDecodings_2(string s) {
    if(s.length() ==0)
        return 0;
    
    if(s[0] == '0')
        return 0;
    
    if(s.length() == 1)
        return 1;
    
    int val1 = 1;
    int val2 = 1;
    
    for(int i = 1; i < s.length(); i++){
        int d1 = s[i] - '0';
        int d2 = (s[i-1] - '0') * 10 + d1;
        int val = 0;
        if(d1>=1)
            val += val1;
        if(d2 >= 10 && d2 <=26){
            val += val2;
        
        val1 = val2;
        val2 = val;
        } 
    }
    return val2;
}

int main() {
    string s = "226";
    cout << "Number of ways to decode '" << s << "': " << numDecodings_1(s) << endl;
    cout << "Number of ways to decode '" << s << "': " << numDecodings_2(s) << endl; // 3

    string s1 = "10";
    cout << "Number of ways to decode '" << s << "': " << numDecodings_1(s1) << endl;
    cout << "Number of ways to decode '" << s << "': " << numDecodings_2(s1) << endl; //1
    return 0;
}
