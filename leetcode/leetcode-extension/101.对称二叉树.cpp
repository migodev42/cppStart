/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

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
    bool compare(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            // 左右节点都不存在
            return true;
        } else if (left==nullptr || right==nullptr) {
            // 左右节点只有一个存在
            return false;
        } else if (left->val != right->val) {
            // 左右节点都存在,且不等
            return false;
        } else {
            // 左右节点都存在,且相等
            return compare(left->left, right->right) &&
                   compare(left->right, right->left);
        }
    }
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return compare(root->left, root->right);
    }
};
// @lc code=end
