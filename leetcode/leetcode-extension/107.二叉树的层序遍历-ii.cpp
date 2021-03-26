/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using std::pair;
using std::queue;
using std::reverse;
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<pair<TreeNode *, int>> cursor;
        cursor.push({root, 0});
        while (cursor.size()) {
            pair<TreeNode *, int> curritem = cursor.front();
            TreeNode *currnode = curritem.first;
            int currlevel = curritem.second;

            if (result.size() < currlevel + 1) {
                result.resize(currlevel + 1);
            }
            result[currlevel].push_back(currnode->val);
            cursor.pop();

            if (currnode->left) {
                cursor.push({currnode->left, currlevel + 1});
            }
            if (currnode->right) {
                cursor.push({currnode->right, currlevel + 1});
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
// @lc code=end
