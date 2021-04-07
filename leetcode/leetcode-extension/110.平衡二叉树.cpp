/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
#include <cmath>
#include <algorithm>

using std::max;
using std::abs;

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
    int result=true;
    int maxDep(TreeNode *root) {
        if (!root) return 0;

        int lmax = maxDep(root->left);
        int rmax = maxDep(root->right);
        if(abs(lmax - rmax) > 1)  result=false;
        if(!result) return 0;
        return max(lmax, rmax) + 1;
    }
    bool isBalanced(TreeNode *root) {
        maxDep(root);
        
        return result;
    }
};
// @lc code=end
