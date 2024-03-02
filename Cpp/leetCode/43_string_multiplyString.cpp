#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
43. Multiply Strings
Medium

Given two non-negative integers num1 and num2 represented as strings, return the product of 
num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

string multiply(string num1, string num2) {
    int m = num1.size();
    int n = num2.size();
    vector<int> result(m + n, 0); // Store intermediate results

    // Perform multiplication digit by digit
    for (int i = m - 1; i >= 0; i--) {  
        for (int j = n - 1; j >= 0; j--) {
            
            int mul = (num1[i] - '0') * (num2[j] - '0'); // -'0' will return dec value
            int sum = mul + result[i + j + 1]; // Add to the current position
            
            result[i + j] = result[i + j] + sum / 10; // Carry to the next position
            result[i + j + 1] = sum % 10;             // last digit of multiplication
        }
    }

    // Convert the result vector to a string
    string res = "";
    for (int digit : result) {
        if (!(res.empty() && digit == 0)) { // Skip leading zeros
            res = res + to_string(digit);
        }
    }

    return res.empty() ? "0" : res;
}

int main() {
    string num1 = "123";
    string num2 = "456";
    cout << multiply(num1, num2) << endl;
    return 0;
}
