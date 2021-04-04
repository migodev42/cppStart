/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <vector>
#include <stack>

using std::stack;
using std::vector;

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
 //   void traversal(TreeNode* root){
 //     if(!root) return;
 //     result.push_back(root->val);
 //     traversal(root->left);
 //     traversal(root->right);
 //   }
 //   vector<int> preorderTraversal(TreeNode* root) {

 //     traversal(root);
 //     return result;

 //   }
 // };

 // 迭代法
class Solution {
public:
  vector<int> result;
  void traversal(TreeNode* root) {

  }
  vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode* node = st.top();
      st.pop();
      if(node) result.push_back(node->val);
      else continue;
      st.push(node->right);
      st.push(node->left);

    }
    return result;

  }
};

// @lc code=end

