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
    void traverse(TreeNode* &root, vector<int>& nums){
        if(nums.empty()) return;

        auto maxiter = max_element(nums.begin(),nums.end());
        root = new TreeNode(*maxiter);

        vector<int> leftv(nums.begin(), maxiter);
        vector<int> rightv(maxiter+1, nums.end());
        traverse(root->left, leftv);
        traverse(root->right,rightv);

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = nullptr;
        traverse(root,nums);
        return root;
    }
};