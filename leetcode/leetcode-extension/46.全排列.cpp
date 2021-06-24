/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>

using std::vector;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> result;
  vector<int> path;
  vector<bool> used;  // 当前树枝中使用过的数字不能再用
  void backtrack(vector<int>& nums) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    // 这里和组合问题、切割问题和子集问题最大的不同就是for循环里不用startIndex了。
    // 因为排列问题，每次都要从头开始搜索
    // 而used数组，其实就是记录此时path里都有哪些元素使用了，一个排列里一个元素只能使用一次。
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i] == true)
        continue;
      used[i] = true;
      path.push_back(nums[i]);
      backtrack(nums);
      path.pop_back();
      used[i] = false;
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    used.resize(nums.size(), false);
    backtrack(nums);
    return result;
  }
};
// @lc code=end
