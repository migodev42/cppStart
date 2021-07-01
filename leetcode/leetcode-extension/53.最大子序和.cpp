/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

#include <limits.h>
#include <vector>

using std::vector;

// @lc code=start

/* 贪心算法 */
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() < 2)
      return nums[0];

    int result = INT32_MIN;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      count += nums[i];
      if (count > result) { // 取区间累计的最大值（相当于不断确定最大子序终止位置）
        result = count;
      }
      if (count <= 0) { // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
        count = 0;
      }
    }
    return result;
  }
};


/* 动态规划 */
// @lc code=end
