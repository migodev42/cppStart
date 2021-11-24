/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */
#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
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
  vector<TreeNode*> needSwap;
  TreeNode* pre = nullptr;
  void swap(TreeNode* node1, TreeNode* node2) {
    int tmp = node2->val;
    node2->val = node1->val;
    node1->val = tmp;
  }
  void traverse(TreeNode* node) {
    if (!node)
      return;
    traverse(node->left);
    if (pre && node->val < pre->val) {
      needSwap.push_back(pre);
      needSwap.push_back(node);
    }
    pre = node;
    traverse(node->right);
  }
  void recoverTree(TreeNode* root) {
    traverse(root);
    if (needSwap.size() == 2) {
      swap(needSwap[0], needSwap[1]);
    }
    if (needSwap.size() == 4) {
      swap(needSwap[0], needSwap[3]);
    }
  }
};
// @lc code=end
