/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
// 方法1
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> result;
//         if(!root) return result;

//         queue<pair<TreeNode*,int>> cursor;
//         cursor.push({root,0});

//         while(cursor.size()){
//             auto curritem = cursor.front();
//             TreeNode* currnode = curritem.first;
//             int currlevel = curritem.second;

//             if(result.size()<currlevel+1){
//                 result.resize(currlevel+1);
//             }
//             result[currlevel].push_back(currnode->val);

//             cursor.pop();
//             if(currnode->left){
//                 cursor.push({currnode->left, currlevel+1});
//             }
//             if(currnode->right){
//                 cursor.push({currnode->right, currlevel+1});
//             }

//         }
//         return result;
//     }
// };

// 方法2 更优
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode *> cursor;
        cursor.push(root);
        while (!cursor.empty()) {
            int size = cursor.size();
            vector<int> level_result;  // 每层的结果数组

            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            // 固定的size即为每层的节点数
            for (int i = 0; i < size; ++i) {
                TreeNode *currnode = cursor.front();
                cursor.pop();
                level_result.push_back(currnode->val);
                if (currnode->left) cursor.push(currnode->left);
                if (currnode->right) cursor.push(currnode->right);
            }
            if (level_result.size()) {
                result.push_back(level_result);
            }
        }
        return result;
    }
};
// @lc code=end
