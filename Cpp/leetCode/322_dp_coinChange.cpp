#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;
/*
322. Coin Change
Medium

You are given an integer array coins representing coins of different
denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that
amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

int coinChange(vector<int> &coins, int amount) {
  if (amount == 0)
    return 0;
  int size = coins.size();
  if (size == 0)
    return 0;
  int ans = INT_MAX;
  for (int i = 0; i < size; i++) {
    if (amount - coins[i] >= 0) {
      int sub_ans = coinChange(coins, amount - coins[i]);
      if (sub_ans != INT_MAX && sub_ans + 1 < ans) {
        ans = sub_ans + 1;
      }
      //cout << sub_ans << "," << ans << endl;
    }
  }
  return ans;
}

int coinChange_dp_1(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            if (dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int coinChange_dp_2(vector<int> &coins, int amount) {
  // creating the base dp array, with first value set to 0
  if (amount < 1)
    return 0;
  int dp[++amount];
  dp[0] = 0;

  sort(begin(coins), end(coins)); // more convenient to have the coins sorted

  for (int i = 1; i < amount; i++) { // 1 to n

    dp[i] = INT_MAX; // setting dp[0] base value to 1, 0 for all the rest
    for (int c : coins) {
      if (i - c < 0)
        break;
      // if it was a previously not reached cell, we do not add use it
      if (dp[i - c] != INT_MAX)
        dp[i] = std::min(dp[i], 1 + dp[i - c]);
    }
  }
  return dp[--amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
  // vector<int> coins{1, 2, 5};
  vector<int> coins{7, 5, 1};
  int amount = 4;
  cout << "coinChange:" << coinChange(coins, amount) << endl;
  cout << "coinChange_dp_1:" << coinChange_dp_1(coins, amount) << endl;
  cout << "coinChange_dp_2:" << coinChange_dp_2(coins, amount) << endl;

  return 0;
}