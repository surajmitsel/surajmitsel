#include <iostream>
#include <cctype>
/*
125. Valid Palindrome
Easy

A phrase is a palindrome if, after converting all uppercase letters 
into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
bool isPalindrome(std::string s) {
    int left = 0; 
    int right = s.length() - 1;
    
    while (left < right) {
        
        while (left < right && (isalnum(s[left]) == false)) ++left; //Skip non-alphanumeric from left
        while (left < right && (isalnum(s[right]) == false)) --right; //Skip non-alphanumeric from right
        
        // Compare characters ignoring cases
        if (tolower(s[left]) != tolower(s[right]))
            return false;
        
        // Move pointers towards the center
        ++left;
        --right;
    }
    return true;
}

int main() {
    std::string s1 = "A man, a plan, a canal: Panama";
    std::string s2 = "race a car";

    std::cout << std::boolalpha;
    std::cout << "Is \"" << s1 << "\" a palindrome? " << isPalindrome(s1) << std::endl; // Output: true
    std::cout << "Is \"" << s2 << "\" a palindrome? " << isPalindrome(s2) << std::endl; // Output: false

    return 0;
}
