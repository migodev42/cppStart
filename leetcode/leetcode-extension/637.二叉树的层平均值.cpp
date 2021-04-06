/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

#include <queue>
#include <vector>

using std::queue;
using std::vector;

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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> result;
        if (!root) return result;
        queue<TreeNode *> cursor;
        cursor.push(root);
        while (!cursor.empty()) {
            int size = cursor.size();
            int sum = 0;
            for (int i = 0; i < size; ++i) {
              TreeNode* curr = cursor.front();
              cursor.pop();
              sum+=curr->val;
              if(curr->left) cursor.push(curr->left);
              if(curr->right) cursor.push(curr->right);
            }
            result.push_back(sum/size);
        }
        return result;
    }
};
// @lc code=end
