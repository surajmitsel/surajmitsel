#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
/*
76. Minimum Window Substring
Hard

Hint
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) 
is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) 
            map[c]++;

        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        
        while(end < s.size()) {
            
            if(map[s[end++]]-- > 0) 
                counter--; //in t

            while(counter==0) { //valid
                if(end - begin < d)  
                    d = end-(head= begin);
                if(map[s[begin++]]++==0) 
                    counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s,t);
}