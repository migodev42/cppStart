#include <vector>
#include <algorithm>
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
using std::max;

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
    void traverse(TreeNode* root, const int &sum, int curSum, bool &hasSum){
        if(hasSum) return;
        if(!root) return;
        if(!root->right && !root->left){
            hasSum = sum == (root->val + curSum);
        }
        traverse(root->left, sum, curSum+root->val, hasSum);
        traverse(root->right, sum, curSum+root->val, hasSum);
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        bool hasSum = false;
        traverse(root, sum, 0, hasSum);
        return hasSum;
    }
};