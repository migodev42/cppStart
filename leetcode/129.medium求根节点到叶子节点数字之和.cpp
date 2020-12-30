/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode {
     int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
class Solution {
public:
    int result=0; 
    void traverse(TreeNode* root,int prevSum){
        if(!root) return;
        prevSum = root->val + prevSum* 10;
        if(!root->left && !root->right){
            result+=prevSum;
            return;
        }
        traverse(root->left,prevSum);
        traverse(root->right,prevSum);

    } 
    int sumNumbers(TreeNode* root) {
        traverse(root,0);
        return result;
    }
};