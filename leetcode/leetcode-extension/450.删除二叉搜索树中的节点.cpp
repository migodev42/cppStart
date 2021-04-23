/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return nullptr;

        if (root->val == key) {
            // 根等于值

            if (root->left && root->right) {
                // 若左右子树都存在将左子树放到右子树的最左侧节点的left
                // 或将右子树放到左子树的最右子树的right
                // (根节点大于所有左子树的节点，小于所有右子树的节点)
                TreeNode *cursor = root->right;
                while (cursor->left) {
                    cursor = cursor->left;
                }
                cursor->left = root->left;                
                return root->right;
            } else {
                return !!root->left ? root->left : root->right;
            }
            // }
        } else if (root->val > key) {
            // 根大于值
            root->left = deleteNode(root->left, key);
        } else {
            // 根小于值
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
// @lc code=end
