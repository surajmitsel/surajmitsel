#include <iostream>
#include <stack>
#include <string>

int longestValidParentheses(const std::string& s) {
    int maxLen = 0;
    std::stack<int> stk;
    stk.push(-1); // Push a dummy index to mark the start

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            stk.push(i); // Push index of '('
        } else { // s[i] == ')'
            stk.pop(); // Pop the previous '('
            if (!stk.empty()) {
                maxLen = std::max(maxLen, i - stk.top());
            } else {
                stk.push(i); // Push current index to mark new start
            }
        }
    }

    return maxLen;
}

int main() {
    //std::string s = "(()))())("; // Example string
    std::string s = ")))()"; // Example string
    std::cout << "Length of longest valid parentheses: " << longestValidParentheses(s) << std::endl;
    return 0;
}
