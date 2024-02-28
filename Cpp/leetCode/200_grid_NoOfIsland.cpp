#include <iostream>
#include <vector>
using namespace std;
/* ---> width (columns)
   ^
   | Hight (rows)
   |
eg.
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 0 0
0 0 0 1 1

Output = 3
*/

void dfs(vector<vector<char>>& grid, int i, int j) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1') {
        return;
    }

    // Mark the current cell as visited
    grid[i][j] = '0';

    // Explore 4-directionally
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) {
        return 0;
    }

    int rows = grid.size();
    int cols = grid[0].size();
    int numIslands = 0;

    // Traverse the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '1') {
                // Found land cell, perform DFS to mark connected land cells
                dfs(grid, i, j);
                numIslands++;
            }
        }
    }

    return numIslands;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Number of islands: " << numIslands(grid) << endl;

    return 0;
}