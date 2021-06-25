/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <utility>
#include <vector>

using std::vector;
// using std::static
/*
      1       2  4  6  8   9



 */
// @lc code=start
class Solution {
 public:
  vector<int> avaliable(vector<vector<char>>& board, int row, int col) {
    vector<bool> used(9, false);
    vector<int> result;
    for (int i = 0; i < board.size(); ++i) {
      if (board[i][col] != '.') {
        used[board[i][col] - '0' - 1] = true;
      }

      if (board[row][i] != '.') {
        used[board[row][i] - '0' - 1] = true;
      }
    }

    for (int i = 0; i < used.size(); ++i) {
      if (used[i] == false)
        result.push_back(i + 1);
    }
    return result;
  }
  bool isValid(vector<vector<char>>& board, int row, int col, char target) {
    for (int i = 0; i < board.size(); ++i) {
      if (board[i][col] == target)
        return false;
      if (board[row][i] == target)
        return false;
    }
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
      for (int j = startCol; j < startCol + 3; ++j) {
        if (board[i][j] == target)
          return false;
      }
    }
    return true;
  }
  bool backtrack(vector<vector<char>>& board) {
    for (int row = 0; row < board.size(); ++row) {
      for (int col = 0; col < board.size(); ++col) {
        if (board[row][col] != '.') continue;
        for (char curr = '1'; curr <= '9'; ++curr) {          
            
          if (!isValid(board, row, col, curr))
            continue;

          board[row][col] = curr;
          if (backtrack(board))
            return true;
          board[row][col] = '.';
        }
        return false;
      }
    }
    return true;
  }
  void solveSudoku(vector<vector<char>>& board) { backtrack(board); }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  s.solveSudoku(board);
}