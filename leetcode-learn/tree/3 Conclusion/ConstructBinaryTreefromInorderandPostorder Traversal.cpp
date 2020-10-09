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
    void traverse(TreeNode* root, vector<int> inorder, stack<int, vector<int>>& pstack) {
        if (!root) return;
        auto iter = find(inorder.begin(), inorder.end(), root->val);
        vector<int> leftv(inorder.begin(), iter);
        vector<int> rightv(iter, inorder.end());

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        stack<int, vector<int>> pstack(postorder);
        int rootval = pstack.top();
        TreeNode* root = new TreeNode(rootval);
        pstack.pop();
        // cout << *pend << endl;
        // cout << root->val << endl;
        traverse(root, inorder, pstack);
        return root;
    }
};

int main() {
    Solution s;
    vector<int> inorder = { 9,3,15,20,7 };
    vector<int> postorder = { 9,15,7,20,3 };
    ostream_iterator<int> out_iter(cout, ",");
    s.buildTree(inorder, postorder);
}