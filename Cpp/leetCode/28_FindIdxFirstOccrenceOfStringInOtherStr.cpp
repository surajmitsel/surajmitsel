#include <iostream>
using namespace std;

/*
Given two strings needle and haystack, return the index of the first 
occurrence of needle in haystack, or -1 if needle is not part of haystack.

 Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/
int strStr(string haystack, string needle) {
    int n = needle.size();
    int m = haystack.size();

    for(int i = 0; i < m; i++){
        if(needle == haystack.substr(i,n)){
            return i;
        }
    }
    return -1;
}

int main(){
    cout << strStr("surajverma", "jver") << endl;
    cout << strStr("sadbutsad", "sad") << endl;
}