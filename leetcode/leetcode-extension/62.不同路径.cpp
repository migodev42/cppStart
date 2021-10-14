/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <vector>
using std::vector;

// @lc code=start

/*
  m 行 n列
  dp[m][n]
  m、n表示网格维度，dp[m][n]的值表示到达m*n的路径数

  dp[m][n] = dp[m-1][n] + dp[m][n-1]

  dp[0][0] = 0
  dp[0][1] = 1
  dp[1][0] = 1
  dp[1][1] = 2
  dp[1][2] = 3
  dp[1][3] =
  dp[2][1] = 3
  dp[2][2] = 6


 */
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));
     dp[0][0] = 1;

    // 初始化两条边上的路径数（只有一行时，路径数量始终为1）
    for (int i = 1; i < m ; ++i) {
      dp[i][0] = 1;
    }

    for (int j = 1; j < n ; ++j) {
      dp[0][j] = 1;
    }


    for (int i = 1; i < m ; ++i) {
      for( int j = 1; j<n; ++j){      
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
    return dp[m-1][n-1];
  }
};
// @lc code=end
