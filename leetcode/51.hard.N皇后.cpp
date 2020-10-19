#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool isValid(vector<string> board, int row, int col) {        
        // 检查当前列有没有重复的
        for(auto i = 0; i<row; ++i){
            if(board[col][i] == 'Q') return false;
        }

        // 检查左上方
        for(auto irow = row-1, icol = col-1;
            irow >=0 && icol>=0;
            --irow, --icol){
            if(board[icol][irow] == 'Q') return false;
        }

        // 检查右上方
        for(auto irow = row-1, icol = col+1;
            irow >=0 && icol< board.size(); 
            --irow, ++icol){
            if(board[icol][irow] == 'Q') return false;
        }
        return true;

    }
    void backtrack(vector<string> board, vector<vector<string>>& rs, int currow) {
        int n = board[0].size();
        if (currow == n) {
            rs.push_back(board);
            return;
        }        
        for (auto col = 0; col < n; ++col) {
            if (!isValid(board, currow, col)) {
                continue;
            }
            board[col][currow] = 'Q';
            backtrack(board, rs, currow + 1);
            board[col][currow] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rs;
        // 初始化 n*n 的棋盘
        vector<string> board(n, string(n, '.'));
        backtrack(board, rs, 0);
        return rs;
    }
};