/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include <vector>

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;
        if (postorder.empty()) return nullptr;
        int rootidx = postorder.size() - 1;
        int rootval = postorder[rootidx];

        TreeNode *root = new TreeNode(rootval);

        if (postorder.size() == 1) return root;

        int split_idx = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (rootval == inorder[i]) {
                split_idx = i;
                break;
            }
        }
        vector<int> l_inorder(inorder.begin(), inorder.begin() + split_idx);
        vector<int> r_inorder(inorder.begin() + split_idx + 1, inorder.end());

        postorder.resize(postorder.size() - 1);

        vector<int> l_postorder(postorder.begin(),
                                postorder.begin() + l_inorder.size());
        vector<int> r_postorder(postorder.begin() + l_inorder.size(),
                                postorder.end());

        root->left = buildTree(l_inorder, l_postorder);
        root->right = buildTree(r_inorder, r_postorder);

        return root;
    }
};
// @lc code=end
