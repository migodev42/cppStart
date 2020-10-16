/**
 * Definition for a binary tree node.
 */
#include <utility>
#include <algorithm>
#include <vector>

using std::vector;
using std::max;
using std::pair;
using std::make_pair;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* pre;
    int curcnt = 1, maxcnt;
    void traverse(TreeNode* root, vector<int>& result) {
        if (!root) return;
        traverse(root->right, result);
        if (pre == nullptr) curcnt = 1;
        else if (pre->val == root->val) ++curcnt;
        else curcnt = 1;

        if (curcnt == maxcnt) result.push_back(root->val);
        else if (curcnt > maxcnt) {
            result.clear();
            result.push_back(root->val);
        }
        maxcnt = max(curcnt, maxcnt);

        pre = root;
        traverse(root->left, result);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        traverse(root, result);
        return result;
    }
};