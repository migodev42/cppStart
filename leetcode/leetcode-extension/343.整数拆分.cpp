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

// 动态规划五部曲
/* 
1 确定dp数组及下标的含义 
  dp[i] 是分拆正整数i，可以得到的最大乘积为dp[i]

2 确定递推公式
  dp[i]的最大乘积自底向上遍历而来
  从1到j 比较两个渠道 
    j*(i-j)  分拆为两个数
    j*dp[i-j] 分拆为多个数
  所以 dp[i] = max(dp[i],j*(i-j),j*dp[i-j]);
  (还要比较dp[i]的原因是，从1到j是一个更新dp[i]的过程，每次需要和自己比较)

3 确定dp数组如何初始化
  根据题意n>=3， 所以 dp[0] 和 dp[1] 不需要初始化
  直接从dp[2]开始 dp[2] = 1 (注意这里idx与数字对应了，所以数组长度应该为n+1)

4 确定遍历顺序
  确定遍历顺序，先来看看递归公式：dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
  dp[i] 是依靠 dp[i - j]的状态，所以遍历i一定是从前向后遍历，先有dp[i - j]再有dp[i]。
  枚举j的时候，是从1开始的。i是从3开始，这样dp[i - j]就是dp[2]正好可以通过我们初始化的数值求出来。

5 举例推导dp数组
  举例当n为10 的时候，dp数组里的数值，如下：
  下标：  2  3  4  5  6  7  8  9  10
  dp[i]: 1  2  4  6  9  12 18 27 36

时间复杂度：O(n^2)
空间复杂度：O(n)

*/
 

/*  
      正整数n
      2   3   4   5
  1   1   1   1   1
  2   -   2   4   4
  3
  4
  5
  .
  .
  n
  分拆为1，2，3...

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
