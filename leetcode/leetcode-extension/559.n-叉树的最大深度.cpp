/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */
#include <algorithm>
#include <queue>
#include <vector>

using std::max;
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

// 递归法: 自底向上
// class Solution {
//    public:
//     int maxDepth(Node* root) {
//         if (!root) return 0;
//         int tmp_maxdep = 0;
//         for (int i = 0; i < root->children.size(); ++i) {
//             tmp_maxdep = max(maxDepth(root->children[i]), tmp_maxdep);
//         }
//         // 子树的max，得加上自己这层，所以需要加1
//         return tmp_maxdep + 1;
//     }
// };

// 递归法：自顶向下
// class Solution {
//    public:
//     int maxdep = 0;
//     void traversal(Node* root, int currdep) {
//         if (!root) return;

//         for (int i = 0; i < root->children.size(); ++i) {
//             traversal(root->children[i], currdep + 1);
//         }
//         maxdep = max(maxdep, currdep);
//     }
//     int maxDepth(Node* root) {
//         if (!root) return 0;
//         traversal(root, 1);
//         return maxdep;
//     }
// };

// 迭代法：层序遍历
class Solution {
   public:
    int maxDepth(Node* root) {
        if (!root) return 0;        
        queue<Node*> cursor;
        cursor.push(root);
        int maxdep = 0;
        while (!cursor.empty()) {
            int size = cursor.size();
            for (int i = 0; i < size; ++i) {
                Node* curr = cursor.front();
                cursor.pop();
                for (int i = 0; i < curr->children.size(); ++i) {
                    cursor.push(curr->children[i]);
                }
            }
            // 最后一层没有children也会++，所以return的maxdep不用再加1
            ++maxdep;
        }
        return maxdep;
    }
};
// @lc code=end
