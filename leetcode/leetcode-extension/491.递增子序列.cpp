/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> result;
  vector<int> path;
  //   vector<bool> used;

  void backtrack(vector<int>& nums, int startIdx) {
    if (path.size() >= 2) {
      result.push_back(path);
    }
    if (startIdx > nums.size()) {
      return;
    }

    vector<bool> used(200, false);
    for (int i = startIdx; i < nums.size(); ++i) {
      if (path.size() && nums[i] < path[path.size() - 1]) {
        continue;
      }
      if (used[nums[i] + 100] == true) {
        continue;
      }

      used[nums[i] + 100] = true;
      path.push_back(nums[i]);
      backtrack(nums, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    backtrack(nums, 0);
    return result;
  }
};
// @lc code=end
