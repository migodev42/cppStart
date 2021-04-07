/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
#include <algorithm>

using std::min;

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

// 递归法：自底向上
// 和最大深度的区别在于，最小深度需要判断最小的是否为空，如果为空则不是最小深度
// 比如：当一个左子树为空，右不为空，这时左子树并不是最低点
class Solution {
   public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;

        int lmin = minDepth(root->left);
        int rmin = minDepth(root->right);
        if (lmin == 0 && rmin == 0) {
            return 1;
        } else if (lmin == 0 && rmin != 0) {
            return rmin + 1;
        } else if (lmin != 0 && rmin == 0) {
            return lmin + 1;
        } else {
            return min(lmin, rmin) + 1;
        }
    }
};
// @lc code=end
