/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> result;
  vector<int> path;
  void backtrack(vector<int>& candidates,
                 int target,
                 int sum,
                 int startIdx,
                 vector<bool> used) {
    if (sum > target)
      return;
    if (sum == target) {
      result.push_back(path);
      return;
    }

    for (int i = startIdx; i < candidates.size(); ++i) {
      // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
      // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
      // 要对同一树层使用过的元素进行跳过
      if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
        continue;
      }
      sum += candidates[i];
      path.push_back(candidates[i]);
      used[i] = true;
      backtrack(candidates, target, sum, i + 1, used);
      used[i] = false;
      sum -= candidates[i];
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<bool> used(candidates.size(), false);
    sort(candidates.begin(),
         candidates.end());  // 对树层去重的话需要对数组进行排序
    backtrack(candidates, target, 0, 0, used);
    return result;
  }
};
// @lc code=end
