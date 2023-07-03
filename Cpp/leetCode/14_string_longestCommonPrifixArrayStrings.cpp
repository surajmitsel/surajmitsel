#include <iostream>
#include <vector>
using namespace std;
/*
Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".
Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

// first take common b/w 1,2 then (result,3) then (result,4)
*/
string longestCommonPrefix(vector<string> &strs) {
  string result = strs[0];
  int j = 0;
  for (int i = 1; i < strs.size(); i++) { // t=1 start from next string
    while (j < result.length() && j < strs[i].length() &&
           result[j] == strs[i][j]) {
      j++;
    }
    result = result.substr(0, j);
    std::cout << result.c_str() << std::endl;
    j = 0;
  }
  return result;
}

int main() {
  vector<string> strs{"flower", "flow", "flight"};
  cout << longestCommonPrefix(strs).c_str();
}