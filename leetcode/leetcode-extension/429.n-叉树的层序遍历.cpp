/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */
#include <queue>
#include <utility>
#include <vector>

using std::pair;
using std::queue;
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
   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<pair<Node*, int>> cursor;
        cursor.push({root, 0});

        while (cursor.size()) {
            auto curritem = cursor.front();
            Node* currnode = curritem.first;
            int currlevel = curritem.second;

            if (result.size() < currlevel + 1) {
                result.resize(currlevel + 1);
            }

            result[currlevel].push_back(currnode->val);
            cursor.pop();

            vector<Node*> currchildren = currnode->children;
            for (int i = 0; i < currchildren.size(); ++i) {
                cursor.push({currchildren[i], currlevel + 1});
            }
        }
        return result;
    }
};
// @lc code=end
