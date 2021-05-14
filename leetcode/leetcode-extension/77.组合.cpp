/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
   public:
    vector<vector<int>> result;
    void backtrack(int n, int k, vector<int> path) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < n; ++i) {
            path.push_back(i);
            backtrack(n, k, )
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, {});
        return result;
    }
};
// @lc code=end
