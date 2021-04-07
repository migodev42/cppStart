/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */
#include <queue>

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

// 递归法1：自底向上
// class Solution {
//    public:
//     int countNodes(TreeNode *root) {
//         if (!root) return 0;

//         int lcnt = countNodes(root->left);
//         int rcnt = countNodes(root->right);
//         return lcnt+rcnt+1;
//     }
// };

// 递归法1：自顶向下
// class Solution {
//    public:
//     int cnt = 0;
//     void traversal(TreeNode *root) {
//         if (!root) return;
//         ++cnt;
//         traversal(root->left);
//         traversal(root->right);
//     }
//     int countNodes(TreeNode *root) {
//         traversal(root);
//         return cnt;
//     }
// };

// 迭代法：队列层序遍历
class Solution {
   public:
    int countNodes(TreeNode *root) {
        int cnt = 0;
        if (!root) return cnt;
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
            cnt+=size;
        }
        return cnt;
    }
};
// @lc code=end
