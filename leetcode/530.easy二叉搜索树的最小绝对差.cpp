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
    void traverse(TreeNode* root, vector<int> &sorted){
        if(!root) return;

        traverse(root->left,sorted);
        sorted.push_back(root->val);
        traverse(root->right,sorted);
    }
    int findmin(vector<int> sorted){
        auto beg = sorted.begin();
        int res;
        for(auto beg = sorted.begin(); beg+1 !=sorted.end(); ++beg){
            res = min(res, abs(*(beg)-*(beg+1)));
        }
        return res;
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> sorted;
        traverse(root,sorted);        
        return findmin(sorted);
    }
};