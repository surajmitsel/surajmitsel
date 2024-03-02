#include <iostream>
#include <string>

using namespace std;
/*
58. Length of Last Word
Easy
Topics
Companies
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

int lengthOfLastWord(string s) {
    int length = 0;
    bool foundWord = false;

    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != ' ') {
            foundWord = true; // Found a non-space character
            length++;
        } else if (foundWord) {
            break; // Stop counting if we have already found a word and encounter a space
        }
    }
    return length;
}

int main() {
    string s1 = "Hello World";
    string s2 = "   fly me   to   the moon  ";

    cout << "Length of last word in \"" << s1 << "\": " << lengthOfLastWord(s1) << endl;
    cout << "Length of last word in \"" << s2 << "\": " << lengthOfLastWord(s2) << endl;

    return 0;
}
