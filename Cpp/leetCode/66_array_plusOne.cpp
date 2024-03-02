#include <iostream>
#include <vector>

using namespace std;
/*
66. Plus One
Easy

You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.


Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
*/
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        } else {
            digits[i] = 0;
        }
    }
    // If we reach here, it means all digits were 9, so we need to add a new leading 1.
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    vector<int> digits1 = {1, 2, 3};
    vector<int> digits2 = {9, 9, 9};

    vector<int> result1 = plusOne(digits1);
    vector<int> result2 = plusOne(digits2);

    cout << "Result for digits1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result for digits2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
