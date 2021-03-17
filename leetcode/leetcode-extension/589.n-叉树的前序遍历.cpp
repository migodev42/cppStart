/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
    void traversal(Node* root, vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i) {
            traversal(root->children[i], result);
        }
    }

   public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
// @lc code=end
