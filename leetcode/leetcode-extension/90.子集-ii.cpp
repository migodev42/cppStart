/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> result = {};
  vector<int> path;
  vector<bool> used;
  void backtrack(vector<int>& nums, int startidx) {
    result.push_back(path);
    if (path.size() >= nums.size()) {
      return;
    }

    for (int i = startidx; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
        continue;
      }

      path.push_back(nums[i]);
      used[i] = true;
      backtrack(nums, i + 1);

      path.pop_back();
      used[i] = false;
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    used.resize(nums.size(), false);
    backtrack(nums, 0);
    return result;
  }
};
// @lc code=end
