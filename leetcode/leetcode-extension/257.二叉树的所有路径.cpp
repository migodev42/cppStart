/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include <string>
#include <vector>

using std::string;
using std::to_string;
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
    vector<string> result;
    void traversal(TreeNode *root, string path) {
        if (!root) return;
        if (path.size()) {
            path = path + "->" + to_string(root->val);
        } else {
            path = to_string(root->val);
        }
        // 找叶子节点，在叶子节点处进行result插入
        if (!root->left && !root->right) {
          result.push_back(path);
        }
        traversal(root->left, path);
        traversal(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        traversal(root, "");
        return result;
    }
};
// @lc code=end
