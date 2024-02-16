#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int SubString(string &str, vector<int> &vec) {
  int ret = 1;
  int cnt = 1;
  for (unsigned int i = 1; i < str.length(); i++) { // i=1
    if (str[i] == str[i - 1]) {
      ++cnt;
    } else {
      vec.push_back(cnt);
      ret = max(ret, cnt);
      cnt = 1;
    }
  }
  vec.push_back(cnt);
  ret = max(ret, cnt);

  return ret;
}

int solution(string &S, vector<int> &vec) {
  // write your code in C++14 (g++ 6.2.0)

  // find the largest consicutive sequence of string
  int max_num_char = SubString(S, vec);
  return max_num_char;
}

int main() {

  string str = "aabbbcccccd";
  vector<int> vec;
  int subStrMaxLengh = solution(str, vec);
  int total = 0;

  for (int i = 0; i < vec.size(); i++) {
    cout << "vec val = " << vec[i] << endl;
    total += subStrMaxLengh - vec[i];
  }

  cout << "vec size = " << vec.size() << endl;
  cout << "maxlengh = " << subStrMaxLengh << " total " << total << endl;
  // maxlengh = 5 total 9
}
