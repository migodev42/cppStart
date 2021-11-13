/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

#include <vector>
#include <algorithm>

using std::max;
using std::vector;
// @lc code=start

// 动态规划
// dp[n] =

/*
      2   3   4   5
  1   1   1   1   1
  2   -   2   4   4
  3
  4
  5
  .
  .
  n


 */
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n+1);
    // n >= 3
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
      for (int j = 1; j < i - 1; j++) {
        dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
      }
    }
    return dp[n];
  }
};
// @lc code=end
