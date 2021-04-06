/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */
#include <algorithm>
#include <queue>
#include <stack>

using std::queue;
using std::stack;
using std::swap;

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
//     void traversal(TreeNode *root) {
//         if (!root) return;

//         traversal(root->left);
//         traversal(root->right);
//         TreeNode* tmp = root->right;
//         root->right = root->left;
//         root->left = tmp;
//         return ;
//     }
//     TreeNode *invertTree(TreeNode *root) {
//       traversal(root);
//       return root;
//     }
// };

// 递归法2
// https://mp.weixin.qq.com/s/6gY1MiXrnm-khAAJiIb5Bg

// 1、确定递归函数的参数和返回值
// 参数就是要传入节点的指针，不需要其他参数了，通常此时定下来主要参数，
// 如果在写递归的逻辑中发现还需要其他参数的时候，随时补充。
// 返回值的话其实也不需要
// 但是题目中给出的要返回root节点的指针，可以直接使用题目定义好的函数，
// 所以就函数的返回类型为TreeNode*。

/* class Solution {
   public:
    TreeNode *invertTree(TreeNode *root) {

        // 2、确定终止条件
        // 当前节点为空的时候，就返回
        if (!root) return root;

        // 3、确定单层递归的逻辑
        //
因为是先前序遍历，所以先进行交换左右孩子节点，然后反转左子树，反转右子树。
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        // swap(root->left, root->right);

        return root;
    }
}; */

// 迭代法1：模拟深度优先遍历(前序)
// class Solution {
//    public:
//     TreeNode *invertTree(TreeNode *root) {
//         if(!root) return root;
//         stack<TreeNode *> st;
//         st.push(root);
//         while (!st.empty()) {
//             TreeNode *curr = st.top();
//             st.pop();
//             swap(curr->left, curr->right);
//             if (curr->right) st.push(curr->right);
//             if (curr->left) st.push(curr->left);
//         }

//         return root;
//     }
// };

// 迭代法2: 广度优先遍历(层序)
class Solution {
   public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return root;
        queue<TreeNode *> cursor;
        cursor.push(root);
        while (!cursor.empty()) {
            int size = cursor.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *curr = cursor.front();
                cursor.pop();
                swap(curr->left, curr->right);
                if (curr->left) cursor.push(curr->left);
                if (curr->right) cursor.push(curr->right);
            }
        }

        return root;
    }
};

// @lc code=end
