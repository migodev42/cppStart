/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include <string>

using std::string;

// @lc code=start
class Solution {
 public:
  int lengthOfLastWord(string s) {
    int rs = 0;
    string::iterator curr = s.end() - 1;
    while (*curr == ' ')
      curr--;
    while (curr >= s.begin() && *curr != ' ') {
      curr--;
      rs++;
    }
    return rs;
  }
};
// @lc code=end
