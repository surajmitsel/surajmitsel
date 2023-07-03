#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>
using namespace std;
/*
130. Surrounded Regions
Medium

Given an m x n matrix board containing 'X' and 'O', capture all regions that are
4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
Example 1:
Input: board =
[["X","X","X","X"],
 ["X","O","O","X"],
 ["X","X","O","X"],
 ["X","O","X","X"]]

Output:
[["X","X","X","X"],
 ["X","X","X","X"],
 ["X","X","X","X"],
 ["X","O","X","X"]]

Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.

Example 2:
Input: board = [["X"]]
Output: [["X"]]


Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

void dfs(vector<vector<char>> &board, int i, int j) {
  if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() &&
      board[i][j] == 'O') {
    board[i][j] = 'A';
    dfs(board, i - 1, j); // up
    dfs(board, i + 1, j); // down
    dfs(board, i, j - 1); // left
    dfs(board, i, j + 1); // right
  }
}

void solve(vector<vector<char>> &board) {
  int row = board.size();
  if (row < 2)
    return; // all on border
  int col = board[0].size();
  if (col < 2)
    return; // all on border

  // boundurary cell if it is 'O' and its connected all 'O'
  // then convert to other character'A'
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (board[i][j] == 'O' &&
          (i == 0 || j == 0 || i == row - 1 || j == col - 1)) {
        dfs(board, i, j);
      }
    }
  }

  // convert back 'A' and actual convert the sourrounding 'O' to 'X'
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (board[i][j] == 'O') {
        board[i][j] = 'X';
      } else if (board[i][j] == 'A') {
        board[i][j] = 'O';
      }
    }
  }
}

int main() {
  vector<vector<char>> board{{'X', 'X', 'X', 'X'},
                             {'X', 'O', 'O', 'X'},
                             {'O', 'X', 'O', 'X'},
                             {'X', 'O', 'X', 'X'}};
  cout << "Surrounded Regions" << endl;
  cout << "before--------" << endl;
  for (auto row : board) {
    for (auto col : row) {
      cout << col << ",";
    }
    cout << endl;
  }
  solve(board);
  cout << "after---------" << endl;
  for (auto row : board) {
    for (auto col : row) {
      cout << col << ",";
    }
    cout << endl;
  }

  return 0;
}