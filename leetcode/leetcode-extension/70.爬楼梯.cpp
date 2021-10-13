/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <vector>;

using std::vector;

// @lc code=start

// 动态规划

/* 
递推公式
  首先是dp[i - 1]，上i-1层楼梯，有dp[i - 1]种方法，那么再一步跳一个台阶不就是dp[i]了么。
  还有就是dp[i - 2]，上i-2层楼梯，有dp[i - 2]种方法，那么再一步跳两个台阶不就是dp[i]了么。dp[i] = dp[i - 1] + dp[i - 2] 
  那么dp[i]就是 dp[i - 1]与dp[i - 2]之和！

所以
dp[i] = dp[i - 1] + dp[i - 2] 。
*/
class Solution {
public:
    int climbStairs(int n) {
      if(n<3) return n;
      vector<int> dp(n+1);
      dp[0] = 0;
      dp[1] = 1;
      dp[2] = 2;
      for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
      }
      return dp[n];
    }
};
// @lc code=end

