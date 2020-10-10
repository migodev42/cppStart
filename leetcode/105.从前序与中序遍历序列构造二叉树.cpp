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
    void traverse(TreeNode* &root, deque<int>& preorder, vector<int>& inorder){
        if(preorder.empty() || inorder.empty()) return;

        auto rootval = preorder.front();
        root = new TreeNode(rootval);        
        preorder.pop_front();

        auto rootiter =  find(inorder.begin(),inorder.end(), rootval);
        vector<int> leftv(inorder.begin(),rootiter);
        vector<int> rightv(rootiter+1,inorder.end());
        
        traverse(root->left,preorder, leftv);
        traverse(root->right,preorder, rightv);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        deque<int> predeque(preorder.begin(), preorder.end());
        TreeNode* root = nullptr;
        traverse(root, predeque, inorder);
        return root;
    }
};