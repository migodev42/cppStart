/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */
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
// class Solution {
//    public:
//     int result = false;
//     int target;
//     void dfs(TreeNode *root, int cursum) {
//         if (!root) return;
//         if (!root->left && !root->right) {
//             if (cursum+root->val == target) result = true;
//         }
//         dfs(root->left, root->val + cursum);
//         dfs(root->right, root->val + cursum);
//     }
//     bool hasPathSum(TreeNode *root, int targetSum) {
//         target = targetSum;
//         dfs(root, 0);
//         return result;
//     }
// };

// class Solution {
//    public:
//     bool hasPathSum(TreeNode *root, int targetSum) {
//         if (!root) return false;
//         if (!root->left && !root->right && root->val == targetSum) {
//             return true;
//         }
//         return hasPathSum(root->left, targetSum - root->val) ||
//                hasPathSum(root->right, targetSum - root->val);
//     }
// };

class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root)
      return false;
    if (!root->right && !root->left)
      return targetSum == root->val;
    return (hasPathSum(root->left, targetSum - root->val) ||
            hasPathSum(root->right, targetSum - root->val));
  }
};
// @lc code=end
