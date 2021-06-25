/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

// @lc code=start
class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int idx = s.size() - 1;
    int result = 0;
    for (int i = g.size() - 1; i >= 0; --i) {
      if(idx<0) return result;
      if (g[i] <= s[idx]) {
        ++result;
        --idx;
      }
    }
    return result;
  }
};
// @lc code=end
