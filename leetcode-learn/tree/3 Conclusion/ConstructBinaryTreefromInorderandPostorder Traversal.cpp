#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <iterator>

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
using std::find;
using std::cout;
using std::endl;
using std::stack;
using std::ostream_iterator;

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
    void traverse(TreeNode*& root, vector<int> inorder, vector<int>& pstack) {
        if (pstack.size() == 0 || inorder.size() == 0)return;
        if (!root) {
            int rootval = pstack.back();
            root = new TreeNode(rootval);
        }
        pstack.pop_back();

        auto iter = find(inorder.begin(), inorder.end(), root->val);
        vector<int> leftv(inorder.begin(), iter);
        vector<int> rightv(iter + 1, inorder.end());

        traverse(root->right, rightv, pstack);
        traverse(root->left, leftv, pstack);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = nullptr;
        traverse(root, inorder, postorder);
        return root;
    }
};

int main() {
    Solution s;
    vector<int> inorder = { 9,3,15,20,7 };
    vector<int> postorder = { 9,15,7,20,3 };
    s.buildTree(inorder, postorder);
}