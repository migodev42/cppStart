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
    void traverse(TreeNode* &root, vector<int>& inorder, vector<int>& postorder){
        if(inorder.empty() || postorder.empty()) return;

        int rootval = *(postorder.end()-1);
        root = new TreeNode(rootval);
        postorder.pop_back();

        auto rootiter = find(inorder.begin(), inorder.end(), rootval);
        vector<int> leftv(inorder.begin(), rootiter);
        vector<int> rightv(rootiter+1, inorder.end());
        
        traverse(root->right,rightv,postorder);
        traverse(root->left,leftv,postorder);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = nullptr;
        traverse(root, inorder, postorder);
        return root;
    }
};