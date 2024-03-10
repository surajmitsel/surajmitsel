#include <string>
#include <stack>
#include <iostream>
/*
844. Backspace String Compare
Easy

Given two strings s and t, return true if they are equal when both are typed into empty text editors. 
'#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?
*/

std::string processString(std::string str) 
{
    std::stack<char> st;
    for (char ch : str) {
        if (ch != '#') {
            st.push(ch);
        } else if (!st.empty()) {
            st.pop();
        }
    }
    std::string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

bool backspaceCompare(std::string s, std::string t) {
    return processString(s) == processString(t);
}

int main() {
    // Test cases
    std::string s1 = "ab#c";
    std::string t1 = "ad#c";
    std::string s2 = "ab##";
    std::string t2 = "c#d#";
    std::string s3 = "a##c";
    std::string t3 = "#a#c";
    std::string s4 = "a#c";
    std::string t4 = "b";

    // Call the backspaceCompare function and display the results
    std::cout << "Test Case 1: " << std::boolalpha << backspaceCompare(s1, t1) << std::endl;
    std::cout << "Test Case 2: " << std::boolalpha << backspaceCompare(s2, t2) << std::endl;
    std::cout << "Test Case 3: " << std::boolalpha << backspaceCompare(s3, t3) << std::endl;
    std::cout << "Test Case 4: " << std::boolalpha << backspaceCompare(s4, t4) << std::endl;

}