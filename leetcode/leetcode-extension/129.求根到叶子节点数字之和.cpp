/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
 */

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

  /*
    带参数前序traverse(dfs)
  */
  // class Solution {
  // public:
  //   int sum = 0;
  //   void traverse(TreeNode* root, int prevsum) {
  //     if (!root) return;
  //     prevsum = prevsum * 10 + root->val;
  //     if (!root->left && !root->right) {
  //       sum += prevsum;
  //     }
  //     traverse(root->left, prevsum);
  //     traverse(root->right, prevsum);
  //   }
  //   int sumNumbers(TreeNode* root) {
  //     traverse(root, 0);
  //     return sum;
  //   }
  // };

  /*
    带参数后序traverse(dfs)
    前序、中序、后序都是一样的....
  */
  // class Solution {
  // public:
  //   int sum = 0;
  //   void traverse(TreeNode* root, int prevsum) {
  //     if (!root) return;
  //     prevsum = prevsum * 10 + root->val;        
  //     traverse(root->left, prevsum);             
  //     traverse(root->right, prevsum);    
  //     if (!root->left && !root->right) {
  //       sum += prevsum;
  //     }       
  //   }
  //   int sumNumbers(TreeNode* root) {
  //     traverse(root, 0);
  //     return sum;
  //   }
  // };

  /*
    尾调用版本
  */
class Solution {
public:
  int traverse(TreeNode* root, int prevsum) {
    if (!root) return 0;
    prevsum = prevsum * 10 + root->val;
    if (!root->left && !root->right) {
      return prevsum;
    }
    return traverse(root->left, prevsum) + traverse(root->right, prevsum);
  }
  int sumNumbers(TreeNode* root) {
    return traverse(root, 0);
  }
};
// @lc code=end

