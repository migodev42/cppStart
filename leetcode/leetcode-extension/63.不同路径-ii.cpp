/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include <vector>
using std::vector;
// @lc code=start

// 动态规划
// dp[m][n] = dp[m-1][n] + dp[m][n-1]
// 其中 grid[m][n] = 1时，dp[m][n] = 0，即有障碍的位置没有路径
// dp[1][n] = dp[m][1] = 0;
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    // 根据题目限制m,n都>=1,所以不用考虑数组下标溢出问题

    int m = obstacleGrid.size();     // 行
    int n = obstacleGrid[0].size();  // 列
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      if (obstacleGrid[i][0]) {
        break;
      }
      dp[i][0] = 1;
    }

    for (int j = 0; j < n; ++j) {
      if (obstacleGrid[0][j]) {
        break;
      }
      dp[0][j] = 1;
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j]) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};
// @lc code=end
