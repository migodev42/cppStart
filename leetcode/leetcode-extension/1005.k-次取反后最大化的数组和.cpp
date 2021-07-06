/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include <algorithm>
#include <vector>

using std::abs;
using std::sort;
using std::vector;

// @lc code=start
// 第一步：将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
// 第二步：从前向后遍历，遇到负数将其变为正数，同时K--
// 第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
// 第四步：求和
class Solution {
 static bool revCompare(int a, int b) { return abs(a) > abs(b); }  // 前一个大于后一个
 public:    
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), revCompare);  // 从大到小排序

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < 0 && k > 0) {
        nums[i] *= -1;
        --k;
      }
    }
    if (k % 2 == 1)
      nums[nums.size() - 1] *= -1;

    int sum = 0;
    for (int i : nums)
      sum += i;
    return sum;
  }
};
// @lc code=end
