/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr)), right(nullptr) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//  不考虑二叉搜索树的性质
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (!p || !q) return nullptr;

        if (root == p) return p;
        if (root == q) return q;

        TreeNode* hasLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* hasRight = lowestCommonAncestor(root->right, p, q);

        if (hasLeft != nullptr && hasRight != nullptr) {
            return root;
        } else {
            return hasLeft ? hasLeft : hasRight;
        }
    }
};
// @lc code=end
