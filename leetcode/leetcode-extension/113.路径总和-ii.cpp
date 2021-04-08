/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
   public:
    vector<vector<int>> result;
    void traversal(TreeNode *root, vector<int> path, int curr) {
        if (!root) return;

        path.push_back(root->val);
        if (!root->left && !root->right &&root->val == curr) {
            result.push_back(path);
        }
        traversal(root->left, path, curr - root->val);
        traversal(root->right, path, curr - root->val);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        traversal(root, {}, targetSum);
        return result;
    }
};
// @lc code=end
