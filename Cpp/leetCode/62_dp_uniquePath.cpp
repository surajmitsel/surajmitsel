#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

/*
62. Unique Paths
Medium

There is a robot on an m x n grid. The robot is initially located at the
top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right
corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right
at any point in time.

Given the two integers m and n, return the number of possible unique paths that
the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2
* 109.

Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the
bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/

/*
solution 3 x 7

   &  21  15  10  6   3   1
   7  6   5   4   3   2   1
   1  1   1   1   1   1   #
*/

int uniquePaths(int row, int col) {
  vector<vector<int>> paths(row, vector<int>(col));
  
  for (int r = 0; r < row; r++)
    paths[r][col - 1] = 1; // last col
  
  for (int c = 0; c < col; c++)
    paths[row - 1][c] = 1; // last row
  
  for (int r = row - 2; r >= 0; r--)
    for (int c = col - 2; c >= 0; c--)
      paths[r][c] = paths[r][c + 1] + paths[r + 1][c];

  return paths[0][0];
}

int main() {
  int row = 3;
  int col = 7;
  cout << "uniquePaths:" << uniquePaths(row, col);
  return 0;
}