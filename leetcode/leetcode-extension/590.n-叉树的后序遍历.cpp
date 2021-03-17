/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */
#include <vector>

using std::vector;
class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
   private:
    vector<int> result;
    void traversal(Node* root) {
        if (!root) return;
        for (auto i = 0; i < root->children.size(); ++i) {
            traversal(root->children[i]);
        }
        result.push_back(root->val);
    }

   public:
    vector<int> postorder(Node* root) {
        traversal(root);
        return result;
    }
};
// @lc code=end
