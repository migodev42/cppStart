#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool isValid(vector<string> board, int col, int row){
        // 检查列
        for(auto i=0; i<row; ++i){
            if(board[i][col] == 'Q') return false;
        }
        // 检查左上方
        for(auto curcol = col-1, currow = row -1; 
            curcol >=0 && currow >=0;
            --curcol, --currow
        ){
            if(board[currow][curcol]=='Q') return false;
        }
        // 检查右上方
        for(auto curcol = col+1, currow = row -1;
            curcol < board[0].size() && currow >=0;
            ++curcol, --currow
        ){
            if(board[currow][curcol]=='Q') return false;
        }
        return true;
    }
    void backtrack(vector<string> &board, int row, vector<vector<string>> &result){
        int cnt = board[0].size();
        if(row==cnt) {
            result.push_back(board);
            return;
        }
        for(auto col=0; col<cnt; ++col){
            if(!isValid(board,col,row)){
                continue;
            }
            board[row][col] = 'Q';
            backtrack(board,row+1,result);
            board[row][col] = '.';
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n,'.'));        
        vector<vector<string>> result;
        backtrack(board,0,result);
        return result.size();
    }
};