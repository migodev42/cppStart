/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>

using std::vector;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> result = {};
  vector<int> path;
  void backtrack(vector<int>& nums, int startidx) {
    result.push_back(path);
    if (path.size() >= nums.size()) {
      return;
    }

    for (int i = startidx; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      backtrack(nums, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    backtrack(nums, 0);
    return result;
  }
};
// @lc code=end
