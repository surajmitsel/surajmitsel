#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
/*
Given an array of strings strs, group the anagrams together. You can return the
answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase, typically using all the original letters exactly once.
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]


Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
 */

vector<vector<string>> groupAnagram(vector<string> &strs) {
  vector<vector<string>> result;
  if (strs.size() <= 0)
    return result;

  // <key,vector of anagream strings>
  unordered_map<string, vector<string>> myMap;
  for (string str : strs) {
    // create the key will be same for all anagram strings
    string strKey = str;
    sort(strKey.begin(), strKey.end());
    myMap[strKey].push_back(str);
  }

  for (auto elm : myMap) {
    result.push_back(elm.second);
  }
  return result;
}
int main() {
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> result = groupAnagram(strs);
  std::cout << "groupAnagram:" << endl;

  for (auto arrayStrs : result) {
    for (string x : arrayStrs) {
      cout << x.c_str() << ",";
    }
    cout << endl;
  }
  return 0;
}
