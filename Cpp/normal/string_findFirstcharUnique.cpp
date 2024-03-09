#include <iostream>
#include <unordered_map>
using namespace std;

char firstUniqueChar(const std::string& s) {
    std::unordered_map<char, int> charFreq;

    // Count the frequency of each character in the string
    for (char c : s) {
        charFreq[c]++;
    }

    // Find the first character with frequency 1
    for (char c : s) {
        if (charFreq[c] == 1) {
            return c;
        }
    }

    // If no unique character found, return null character
    return '\0';
}

int main() {
    std::string s = "leetcode";
    char result = firstUniqueChar(s);
    if (result != '\0') {
        std::cout << "First unique character: " << result << std::endl;
    } else {
        std::cout << "No unique character found" << std::endl;
    }

    map<char,int> x;
    x['a'] = 1;
    x['z'] = 2;
    x['m'] = 8;

    x['k'] = 10;
    x['b'] = 5;
    for(auto &i:x){
        cout << i.first << ",";
    }
    return 0;
}
