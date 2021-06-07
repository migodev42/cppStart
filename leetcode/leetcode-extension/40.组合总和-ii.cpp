/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <vector>
using std::vector;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> result;
  vector<int> path;
  void backtrack(vector<int>& candidates, int target, int sum, int startIdx) {
    if (sum > target)
      return;
    if (sum == target) {
      result.push_back(path);
      return;
    }

    for (int i = startIdx; i < candidates.size(); ++i) {
      sum += candidates[i];
      path.push_back(candidates[i]);
      backtrack(candidates, target, sum, i + 1);
      sum -= candidates[i];
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    backtrack(candidates, target, 0, 0);
    return result;
  }
};
// @lc code=end
