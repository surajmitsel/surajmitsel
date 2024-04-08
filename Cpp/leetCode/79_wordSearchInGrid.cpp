#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Medium

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

 

Example 1:
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]], word = "ABCB"
Output: false
*/


bool dfs(vector<vector<char>>& board, int r, int c, string &word, int index)
{
    if(index == word.length()){
        return true;
    }
    
    int row = board.size();
    int col = board[0].size();
    if(r < 0 || r >= row || c < 0 || c >= col || word[index] != board[r][c]) {
        return false;
    }
    
    // Mark the current cell as visited
    char temp = board[r][c];
    board[r][c] = '*';

    bool result = dfs(board, r, c+1, word, index+1);
    result |= dfs(board, r, c-1, word, index+1);
    result |= dfs(board, r+1, c, word, index+1);
    result |= dfs(board, r-1, c, word, index+1);
    
    // Restore the cell's original value
    board[r][c] = temp;
    
    return result;
}

bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    int col = board[0].size();
    int res = false;
    if(row == 0 || word.empty()){
        return false;
    }
    for (int r =0; r < row; r++){
        for (int c = 0; c < col; c++){
            if(word[0] == board[r][c]){
                if(dfs(board, r, c, word, 0)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    // Example usage
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'},
                                             {'S', 'F', 'C', 'S'},
                                             {'A', 'D', 'E', 'E'}};
    std::string word1 = "ABCCED";
    std::string word2 = "SEE";
    std::string word3 = "ABCB";
    
    // Test cases
    std::cout << exist(board, word1) << std::endl; // Output: true
    std::cout << exist(board, word2) << std::endl; // Output: true
    std::cout << exist(board, word3) << std::endl; // Output: false

    return 0;
}
