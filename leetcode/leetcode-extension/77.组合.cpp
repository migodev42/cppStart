/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>

using std::vector;

// @lc code=start
/* 基本解法 */
/* class Solution {
   public:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(int n, int k, int curr) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = curr; i <= n; ++i) {
            path.push_back(i); // 处理节点
            backtrack(n, k, i + 1); //
递归：控制树的纵向遍历，注意下一层搜索要从i+1开始 path.pop_back(); //
回溯，撤销处理的节点
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }
}; */

/* 剪枝 */
class Solution {
   public:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(int n, int k, int curr) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = curr; i <= n - (k - path.size()) + 1; /* 剪枝 */
             ++i) {
            path.push_back(i);  // 处理节点
            backtrack(
                n, k,
                i + 1);  // 递归：控制树的纵向遍历，注意下一层搜索要从i+1开始
            path.pop_back();  // 回溯，撤销处理的节点
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }
};
// @lc code=end
