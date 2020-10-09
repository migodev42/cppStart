/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);   
        auto l = root->left;
        auto r = root->right;
        root->left = nullptr;        
        root->right = l;

        // 取当前的右子树底端，接上以前的右子树
        TreeNode* getCurRight = root;
        while(getCurRight->right){
            getCurRight= getCurRight->right;
        }
        getCurRight->right = r;
        return;
    }
};