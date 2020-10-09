#include <vector>
#include <deque>
#include <utility>

// #include 
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
using std::deque;
using std::pair;
using std::make_pair;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rs;
        deque<pair<TreeNode*, int>> q;
        if (!root) {
            return rs;
        }
        q.push_back(make_pair(root, 0));
        while (q.size() != 0)
        {
            pair<TreeNode*, int> next = q.front();
            auto level = next.second + 1;
            TreeNode* node = next.first;
            
            // rs为二维数组，每一层的节点存放为一个数组
            if (rs.size() < level) {
                rs.resize(level);
            }

            rs[level - 1].push_back(node->val);
            // cout << level << node->val;
            // you may want to print the current node here or do other processing
            
            // 处理完的节点出栈
            q.pop_front();
            
            // 下一层的子节点依次入栈
            if (node->left)
                q.push_back(make_pair(node->left, level));
            if (node->right)
                q.push_back(make_pair(node->right, level));
        }
        return rs;
    }
};