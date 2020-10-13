#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <iterator>
#include <deque>
#include <utility>
#include <string>

using std::vector;
using std::string;
using std::to_string;
using std::max;
using std::find;
using std::cout;
using std::endl;
using std::deque;
using std::stack;
using std::pair;
using std::ostream_iterator;
using std::make_pair;
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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

    void preorder_traverse(TreeNode* root, string& se) {
        if (!root) {
            se += "#,";
            return;
        }
        se += to_string(root->val) + ',';
        preorder_traverse(root->left, se);
        preorder_traverse(root->right, se);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string preorder;
        string inorder;
        preorder_traverse(root, preorder);

        cout << "string: " << preorder.substr(0, preorder.size() - 1) << endl;
        return preorder;
    }

    TreeNode* build(deque<string>& preorder) {
        if (preorder.size() == 0) return nullptr;
        string item = preorder.front();
        if (item == "#") {
            preorder.pop_front();
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(item));
        preorder.pop_front();

        root->left = build(preorder);
        root->right = build(preorder);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        deque<string> preorder;

        int start = 0;
        for (decltype(data.size()) i = 0; i < data.size(); ++i) {
            if (data[i] == ',') {
                preorder.push_back(data.substr(start, i - start));
                start = i + 1;
            }
        }
        return build(preorder);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));