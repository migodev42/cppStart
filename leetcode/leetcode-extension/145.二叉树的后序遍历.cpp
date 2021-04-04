/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
//     if(!root) return;
//     traversal(root->left);
//     traversal(root->right);
//     result.push_back(root->val);
//   }
//   vector<int> postorderTraversal(TreeNode* root) {
//     traversal(root);
//     return result;
//   }
// };
// 迭代法
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> result;
      stack<TreeNode*> st;
      st.push(root);
      while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        if(!node) continue;
        else result.push_back(node->val);
        st.push(node->left);
        st.push(node->right);

      }
      // （前序）中左右 -> （临时）中右左 -> （后序）左右中
      reverse(result.begin(), result.end());
      return  result;
    }

};
// @lc code=end

