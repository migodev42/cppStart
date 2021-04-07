/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
class Solution {
   public:
    int rs = 0;
    void traversal(TreeNode *root, bool isLeft) {
        if (!root) return;

        if (!root->left && !root->right && isLeft) {
            rs += root->val;
        }
        traversal(root->left, true);
        traversal(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode *root) {
        traversal(root, false);
        return rs;
    }
};

// class Solution {
//    public:
//     int rs = 0;
//     void traversal(TreeNode *root) {
//         if (!root) return;

//         if (root->left && !root->left->right && !root->left->left) {
//             rs += root->left->val;
//         }
//         traversal(root->left);
//         traversal(root->right);
//     }
//     int sumOfLeftLeaves(TreeNode *root) {
//         traversal(root);
//         return rs;
//     }
// };
// @lc code=end
