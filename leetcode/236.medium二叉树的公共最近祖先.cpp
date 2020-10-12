/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
 1 base case !root return nullptr
 2 如果当前节点等于 p 或者q，则当前节点必定是该分支待选的一个公共节点，return root
 3 如果left 和right都存在，则当前节点即ans
 4 left 和right都不存在，则当前分支没有公共节点 return nullptr
 5 left和right存在任意一个，则存在的那个即为该分支下待选的公共节点， return left || right
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root->val == p->val || root->val == q->val) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right) return root;
        return left?left:right;
    }
};