/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

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

    unordered_set<int> used;
    for (int i = startIdx; i < nums.size(); ++i) {
      if (path.size() && nums[i] < path[path.size() - 1]) {
        continue;
      }
      if (used.find(nums[i])!=used.end()) {
        continue;
      }    

      used.insert(nums[i]);
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
