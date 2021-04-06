/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include <algorithm>
#include <queue>

using std::max;
using std::queue;

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

// 递归法1
// class Solution {
//    public:
//     int maxdep = 0;
//     void traversal(TreeNode *root, int currdep) {
//         if (!root) return;

//         traversal(root->left, currdep + 1);
//         traversal(root->right, currdep + 1);
//         maxdep = max(currdep + 1, maxdep);
//     }
//     int maxDepth(TreeNode *root) {
//         traversal(root, 0);
//         return maxdep;
//     }
// };

// 递归法2
// 自底向上
// 从叶子节点开始，回溯到根节点，每次层级加1
// class Solution {
//    public:
//     int maxDepth(TreeNode *root) {
//         if(!root) return 0;

//         int lmax = maxDepth(root->left);
//         int rmax = maxDepth(root->right);
//         return max(lmax,rmax)+1;
//     }
// };

// 迭代法：层序遍历
class Solution {
   public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        int maxdep = 0;

        queue<TreeNode *> cursor;
        cursor.push(root);
        while (!cursor.empty()) {
            int size = cursor.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *curr = cursor.front();
                cursor.pop();
                if (curr->left) cursor.push(curr->left);
                if (curr->right) cursor.push(curr->right);
            }
            ++maxdep;
        }
        return maxdep;
    }
};
// @lc code=end
