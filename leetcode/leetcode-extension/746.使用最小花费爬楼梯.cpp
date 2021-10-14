/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <algorithm>
#include <vector>

using std::min;
using std::vector;

// @lc code=start

// 动态规划，和背包问题很相似了
// 注意走两步和走一步的定义
// [10,15,20]
// 从10开始，走一步花费20到达15，走一步花费15到达20，花费20走一步到达顶部
/*
  1 确定dp数组以及下标的含义
    dp数组存放到达每一层的最小花费
    下标i表示楼层
  2 确定递推公式
    第i层的花费可以由第i-1层的花费(走两步) 和
  第i-2层+i的花费比较得出最小（走一步）

    dp[i] = min (dp[i-1], dp[i-2]) + cost[i]
  3 确定dp数组如何初始化
  4 确定遍历顺序（以及idx,循环次数）
  5 举例推导dp数组（手动推导几个正确的结果比如0-3的结果）

 */
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size());
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); ++i) {
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    // 注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
    return min(dp[cost.size() - 1], dp[cost.size() - 2]);
  }
};
// @lc code=end
