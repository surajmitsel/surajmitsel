/*
221. Maximal Square
Medium
Topics
Companies
Given an m x n binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.

 

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:
Input: matrix = [["0"]]
Output: 0
*/

/*
https://www.youtube.com/watch?v=Bw8ItQLw868&list=PL1w8k37X_6L86f3PUUVFoGYXvZiZHde1S&index=33 
This solution iterates through each cell of the matrix, 
updating the dynamic programming table dp to store the side length of the largest square ending at that cell. 
Finally, it returns the area of the largest square found.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int maximalSquare(std::vector<std::vector<char>>& matrix) 
{
    if (matrix.empty() || matrix[0].empty()) 
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxSide = 0;
    std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                maxSide = std::max(maxSide, dp[i][j]);
            }
        }
    }

    return maxSide * maxSide;
}

int main() {
    std::vector<std::vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    std::cout << "Maximal square area: " << maximalSquare(matrix) << std::endl;

    return 0;
}


