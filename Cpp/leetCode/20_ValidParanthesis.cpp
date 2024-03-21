#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

/*
20. Valid Parentheses

Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/


bool isValid(string s) {
    if(s.empty()){
        return true;
    }
    unordered_map<char,char> myMap;
    stack <char> myStk;
    myMap[')'] = '(';
    myMap['}'] = '{';
    myMap[']'] = '[';

    for(auto ch: s){
        if(myMap.find(ch) == myMap.end()) {  // Not found i.e open bracket
            myStk.push(ch);
        }else{ // found close bracket
            if(myStk.empty() || myStk.top() != myMap[ch])
                return false;
            myStk.pop();
        }
    }
    // If stack is empty, all brackets were closed properly
    return myStk.empty();
}

int main() {
    cout << boolalpha; // Print true/false instead of 1/0
    cout << isValid("()") << endl;       // Output: true
    cout << isValid("()[]{}") << endl;   // Output: true
    cout << isValid("[({})]") << endl;   // Output: true
    cout << isValid("(]") << endl;       // Output: false
    cout << isValid("[") << endl;       // Output: false
    return 0;
}
