/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <vector>

using std::vector;

/*
    1       1       2
  1  2    -1- -2-   1
 2  1               1
 */

/*
    1       -1-      -1-
  1  -1-  -1- -1- -1- -1-
 1  -1-  -1- -1- -1- -1-
*/

/*
    1       2       2
  2  -2-  1 2     -1- -2-
 2 -2-  2  1    -2- -1-
*/

// 同一层用过的数字不能再用

// @lc code=start
class Solution {
 public:
  vector<vector<int>> result;
  vector<int> path;
  vector<bool> numsUsed;
  void backtrack(vector<int>& nums) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    vector<bool> levelUsed(20, false);
    for (int i = 0; i < nums.size(); ++i) {
      if (numsUsed[i])
        continue;
      if (levelUsed[nums[i] + 10])
        continue;

      levelUsed[nums[i] + 10] = true;
      numsUsed[i] = true;
      path.push_back(nums[i]);
      backtrack(nums);
      path.pop_back();
      numsUsed[i] = false;
    }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    numsUsed.resize(nums.size(), false);
    backtrack(nums);
    return result;
  }
};
// @lc code=end
