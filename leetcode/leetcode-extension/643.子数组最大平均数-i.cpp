/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

 // @lc code=start
#include <vector>
#include <algorithm>
#include <limits>


using std::max;
using std::vector;

class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    // int left = 0, right = left + k;
    int acc = 0;
    for (int j = 0;j < k;++j) {
      acc += nums[j];      
    }

    int maxsum = acc;
    for (int i = 1; i + k <= nums.size();++i) {
      acc = acc - nums[i-1];
      acc = acc + nums[i+k-1];
      maxsum = max(maxsum, acc);
    }
    return maxsum / (k * 1.0);
  }
};
// @lc code=end

