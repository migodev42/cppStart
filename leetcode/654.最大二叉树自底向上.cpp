/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        auto maxiter = max_element(nums.begin(),nums.end());
        TreeNode* root = new TreeNode(*maxiter);

        vector<int> leftv(nums.begin(), maxiter);
        vector<int> rightv(maxiter+1, nums.end());
        root->left = constructMaximumBinaryTree(leftv);
        root->right = constructMaximumBinaryTree(rightv);
        return root;
    }
};