#include <vector>
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
using std::vector;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void traverse(TreeNode* root, vector<int> &rs){
        if(!root) return;            
        traverse(root->left, rs);        
        traverse(root->right, rs);
        if(root->val){
            rs.push_back(root->val);    
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> rs= {};
        traverse(root, rs);        
        return rs;
    }
};