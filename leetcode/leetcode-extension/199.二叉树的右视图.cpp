/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode *> cursor;
        cursor.push(root);
        while (!cursor.empty()) {
            int size  = cursor.size();

            for(int i =0; i<size; ++i){
              TreeNode *curr = cursor.front();
              cursor.pop();
              if(i==size-1){
                result.push_back(curr->val);
              }
              if(curr->left) cursor.push(curr->left);
              if(curr->right) cursor.push(curr->right);
            }
        }
        return result;
    }
};
// @lc code=end
