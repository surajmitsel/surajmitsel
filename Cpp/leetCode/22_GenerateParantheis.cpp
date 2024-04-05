#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateParentheses(vector<string>& result, 
                                string current, 
                                int open, 
                                int close, 
                                int n) {
    // Base case: if both open and close counts are equal to n, we have formed a valid combination
    if (open == n && close == n) {
        result.push_back(current);
        return;
    }

    // Add an opening parenthesis if we haven't used up all the openings yet
    if (open < n) {
        generateParentheses(result, current + '(', open + 1, close, n);
    }

    // Add a closing parenthesis if it doesn't violate the well-formed condition
    if (close < open) {
        generateParentheses(result, current + ')', open, close + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParentheses(result, "", 0, 0, n);
    return result;
}

int main() {
    int n = 3;
    vector<string> result = generateParenthesis(n);
    cout << "total:" << result.size() << endl;
    for (const string& str : result) {
        cout << str << endl;
    }
    return 0;
}

/*
total:5
((()))
(()())
(())()
()(())
()()()
*/
