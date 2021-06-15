/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <string>
#include <vector>

using std::string;
using std::vector;

// @lc code=start
// 思路梳理：
/*
  回文串： 栈的数据结构
  单个字符永远都是回文串

  回溯的结束条件，字符串切在每个切割点都是回文串
 */
class Solution {
 public:
  vector<vector<string>> result;
  vector<string> path;
  bool isPalindrome(vector<string>) {
    
  }
  void backtrack() {
    if (isPalindrome(path)) {
      result.push_back(path);
    }
  }
  vector<vector<string>> partition(string s) {
    backtrack();
    return result;
  }
};
// @lc code=end
