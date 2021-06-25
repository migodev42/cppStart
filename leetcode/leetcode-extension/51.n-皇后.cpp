/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <string>
#include <vector>

using std::string;
using std::vector;
/* 
  "Q..."                      ".Q.." "..Q." "...Q"
-"Q..."- ".Q.." "..Q." "...Q"  

 */
// @lc code=start
class Solution {
 public:
  vector<vector<string>> result;
  bool canPlaceHere(vector<string>& path, int x, int y) {
    // 上方
    for (int i = x; i >= 0; --i) {
      if (path[i][y] == 'Q')
        return false;
    }
    // 左上方
    for (int i = x, j = y; i >= 0 && j >= 0; --i, --j) {
      if (path[i][j] == 'Q')
        return false;
    }

    // 右上方
    for (int i = x, j = y; i >= 0 && j < path.size(); --i, ++j) {
      if (path[i][j] == 'Q')
        return false;
    }
    return true;
  }
  void backtrack(vector<string> path, int startIdx) {
    if (startIdx >= path.size()) {
      result.push_back(path);
      return;
    }

    for (int i = 0; i < path.size(); ++i) {
      if (!canPlaceHere(path, startIdx, i))
        continue;

      path[startIdx][i] = 'Q';
      backtrack(path, startIdx + 1);
      path[startIdx][i] = '.';
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<string> path(n, string(n,'.'));
    backtrack(path, 0);
    return result;
  }
};
// @lc code=end
int main(){
  Solution s;
  s.solveNQueens(4);
}