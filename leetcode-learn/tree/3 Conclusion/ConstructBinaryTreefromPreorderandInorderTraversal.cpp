#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <iterator>
#include <deque>
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
using std::deque;
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
    void traverse(TreeNode*& root, deque<int>& pdueue, vector<int>inorder) {
        if (pdueue.empty() || inorder.empty()) return;

        int rootval = pdueue.front();
        root = new TreeNode(rootval);
        pdueue.pop_front();

        auto splitIter = find(inorder.begin(), inorder.end(), rootval);
        vector<int> leftv(inorder.begin(), splitIter);
        vector<int> rightv(splitIter + 1, inorder.end());
        traverse(root->left, pdueue, leftv);
        traverse(root->right, pdueue, rightv);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = nullptr;
        deque<int> pdueue(preorder.begin(), preorder.end());
        traverse(root, pdueue, inorder);
        return root;
    }
};