/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
// class Solution {
//    public:
//     int findBottomLeftValue(TreeNode *root) {
//         // 假设根节点不会为空，所以不需要处理!root
//         queue<TreeNode *> cursor;
//         int result = 0;
//         cursor.push(root);
//         while (!cursor.empty()) {
//             int size = cursor.size();
//             for (int i = 0; i < size; ++i) {
//               TreeNode* curr = cursor.front();
//               cursor.pop();
//               if(i==0) result = curr->val;
//               if(curr->left) cursor.push(curr->left);
//               if(curr->right) cursor.push(curr->right);
//             }
//         }
//         return result;
//     }
// };

#include <utility>
using std::pair;

class Solution {
   public:
    pair<TreeNode *, int> result;
    void dfs(TreeNode *root, int depth) {
        if (!root) return;
        if (depth > result.second) result = {root, depth}; 
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    int findBottomLeftValue(TreeNode *root) {
        result = {root, 0};
        dfs(root, 0);        
        return result.first->val;
    }
};
// @lc code=end
