/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
   public:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(int cnt, int target, int curr, int currSum) {
        if (path.size() == cnt) {
            if(currSum == target) result.push_back(path);            
            return;
        }
        for (int i = curr; i <= 9; ++i) {
            path.push_back(i);
            backtrack(cnt, target, i + 1, currSum+i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int cnt, int target) {
        backtrack(cnt, target, 1, 0);  // 1-9
        return result;
    }
};
// @lc code=end
