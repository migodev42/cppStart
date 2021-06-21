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
  bool isPalindrome(const string const& s, int left, int right) {
    while (left < right) {
      if (s[left++] == s[right--]) {
        continue;
      } else {
        return false;
      }
    }
    return true;
  }
  void backtrack(const string const& s, int splitidx) {
    if (splitidx >= s.size()) {
      result.push_back(path);  // path都是符合回文的path，判断回文逻辑放到单层递归逻辑中
      return;
    }
          
    for (int i = splitidx; i < s.size(); ++i) {
      if (isPalindrome(s, splitidx, i)) {
        // 如何表示切割子串 [splitidx,i]
        string str = s.substr(splitidx, i - splitidx + 1);
        path.push_back(str);
      } else {  // 如果不是则直接跳过
        continue;
      }

      backtrack(s, i + 1);
      path.pop_back();
    }
  }
  vector<vector<string>> partition(string s) {
    backtrack(s, 0);
    return result;
  }
};
// @lc code=end
