/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

#include <vector>;

using std::vector;

// @lc code=start
/*
  动态规划五部曲

1 确定dp数组以及下标的含义
  dp[i] 为节点数为i的二叉搜索数可能的种类数量

2 确定递推公式
  二叉搜索树：左节点比根小，右节点比根大
  见3.

3 确定dp数组如何初始化
  i表示节点数
  dp[0] = 1; // 空节点也是一颗二叉树，也是一颗二叉搜索树，这是可以说得通的。
  dp[1] = 1;
  dp[2] = 2;

  dp[3] = 5
  dp[4] = 12

  dp[i] =
  sum:
  1做根 dp[0] * dp[i-1]
  2做根 dp[1] * dp[i-2]
  3做根 dp[2] * dp[i-3]
  .
  .
  i做根 dp[i-1]*dp[i-i]

4 确定遍历顺序（以及idx,循环次数）
  自前向后（自底向上）

5 举例推导dp数组（手动推导几个正确的结果比如0-3的结果）
  见3.

*/

class Solution {
 public:
  int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < i + 1; j++) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    
    return dp[n];
  }
};
// @lc code=end
