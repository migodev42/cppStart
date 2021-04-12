/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */
#include <climits>
#include <cmath>
#include <algorithm>

using std::min;
using std::abs;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    int minval = INT16_MAX;
    TreeNode* prev;
    void traversal(TreeNode* root){
      if(!root) return;
      
      traversal(root->left);
      if(prev){
        minval = min(minval, abs(root->val - prev->val));
      }
      prev = root;
      traversal(root->right);

    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return minval;
    }
};
// @lc code=end

