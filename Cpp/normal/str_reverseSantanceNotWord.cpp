#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <string>
#include <type_traits>

using namespace std;

// METHOD1
void reverseText(string &str) {
  // `str[low…high]` forms a word
  int low = 0;
  int high = 0;
  for (int i = 0; i <= str.length(); i++) { //<=
    if (str[i] == ' ' || str[i] == '\0') {
      reverse(str.begin() + low, str.begin() + high + 1);
      low = i + 1;
      high = i + 1; // reset `low` and `high` for the next word
    } else {
      high = i;
    }
  }
  // reverse the whole text
  reverse(str.begin(), str.end());
}

// METHOD2
string reverseSantaceNotWord_stack(string str) {
  string result{};
  stack<string> stk;

  // use <= so that null can be used in if
  for (int i = 0; i <= str.length(); i++) { // <=
    if (str[i] == ' ' || str[i] == '\0') {
      stk.push(result); // push word into stack
      result = {};      // clear for next word
    } else {
      result = result + str[i]; // Forming word
    }
  }
  while (!stk.empty()) {
    result += stk.top();
    if (stk.size() != 1) // last word no need to add space
      result += ' ';
    stk.pop();
  }
  return result;
}
// METHOD3
void reverseSantaceNotWord_OnlyPrint(char str[]) {
  string result{};
  int length = strlen(str);
  for (int i = length - 1; i >= 0; i--) {
    if (str[i] == ' ') {
      str[i] = '\0';
      printf("%s", &(str[i]) + 1);
      printf(" ");
    }
  }
  printf("%s", str);
}

int main() {
  string str = "hi suraj kumar verma"; // output verma suraj hi
  cout << "befor str:" << str << ",length:" << str.length() << endl;

  string result = reverseSantaceNotWord_stack(str);
  cout << "after str:" << result << ",length:" << result.length() << endl;

  reverseText(result);
  cout << "after str:" << result << ",length:" << result.length() << endl;

  reverseSantaceNotWord_OnlyPrint(const_cast<char *>(str.c_str()));
  return 0;
}
