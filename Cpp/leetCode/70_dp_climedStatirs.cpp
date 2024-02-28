#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;
/*
70. Climbing Stairs
Easy
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?



Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


Constraints:

1 <= n <= 45
*/

// this is becoming a fibabacci series
// 0,1,  1,2,3,5,8,13,21,34
int climbStairs_1(int n) {
  if (n <= 2)
    return n;
  int x = 1, y = 2;

  for (int i = 3; i < n; i++) {
    int tmp = y;
    y = x + y;
    x = tmp;
  }
  return x + y;
}

int climbStairs_2(int n) {
  int a = 0, b = 1, c = 0;
  for (int i = 0; i < n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

int climbStairs_3(int n) {
  if (n <= 2)
    return n;
  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];

  return dp[n];
}

int main() {
  cout << "climbStairs_1:" << climbStairs_1(8) << endl;
  cout << "climbStairs_2:" << climbStairs_2(8) << endl;
  cout << "climbStairs_3:" << climbStairs_3(8) << endl;
  return 0;
}