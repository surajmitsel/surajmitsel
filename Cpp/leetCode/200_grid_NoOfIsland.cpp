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

void dfs(vector<vector<int>> &grid, int r, int c) {
  grid[r][c] = 0; // reset

  if (r + 1 < grid.size() && grid[r + 1][c] == 1) // down
    dfs(grid, r + 1, c);

  if (r - 1 >= 0 && grid[r - 1][c] == 1) // up
    dfs(grid, r - 1, c);

  if (c + 1 < grid[r].size() && grid[r][c + 1] == 1) // right
    dfs(grid, r, c + 1);

  if (c - 1 >= 0 && grid[r][c - 1] == 1) // left
    dfs(grid, r, c - 1);
}

int noOfIsland(vector<vector<int>> &grid) {
  int count = 0;

  int rows = grid.size(); // No of Rows
  if (!rows)              // no rows
    return 0;
  int colms = grid[0].size(); // no columns
  if (!colms)
    return 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colms; j++) {
      if (grid[i][j] == 1) {
        count++;
        dfs(grid, i, j); // reset all up,down,left,right 1 values to 0
      }
    }
  }
  return count;
}

int main() {
  vector<vector<int>> grid({{1, 1, 0, 0, 0},
                            {1, 1, 0, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 1}});

  std::cout << "noOfIsland:" << noOfIsland(grid) << endl;
  return 0;
}
