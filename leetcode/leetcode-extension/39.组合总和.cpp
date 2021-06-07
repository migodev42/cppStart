/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <vector>;

using std::vector;

// @lc code=start
class Solution {
 private:
  vector<vector<int>> result;
  vector<int> path;

 public:
  void backtrack(vector<int>& candidates, int target, int sum, int index) {
    if (sum > target) {
      return;
    }
    if (sum == target) {
      result.push_back(path);
      return;
    }

    for (int i = index; i < candidates.size(); ++i) {
      path.push_back(candidates[i]);
      sum += candidates[i];
      backtrack(candidates, target, sum,
                i);  // 关键点1： 是i不是index，若是index则是每次从候选数字第零个开始，是i则是选择i以后的候选数字
                     // 关键点2：i不加1表示可以重复取当前候选数字
      sum -= candidates[i];
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    backtrack(candidates, target, 0, 0);
    return result;
  }
};
// @lc code=end
