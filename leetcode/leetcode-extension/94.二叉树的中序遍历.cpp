/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <stack>
#include <vector>
#include <algorithm>

using std::reverse;
using std::vector;
using std::stack;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // 递归法
 // class Solution {
 // public:
 //   vector<int> result;
 //   void traversal(TreeNode* root) {
 //     if (!root) return;
 //     traversal(root->left);
 //     result.push_back(root->val);
 //     traversal(root->right);

 //   }
 //   vector<int> inorderTraversal(TreeNode* root) {
 //     traversal(root);
 //     return result;
 //   }
 // };

 // 迭代法

class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (curr || st.size()) {
      if (curr) {
        st.push(curr);
        curr = curr->left;
      }
      else {
        curr = st.top();
        st.pop();
        result.push_back(curr->val);
        curr = curr->right;
      }
    }
    return result;
  }
};
// @lc code=end

