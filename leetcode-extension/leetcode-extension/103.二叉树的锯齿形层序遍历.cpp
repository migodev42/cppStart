/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */
#include <algorithm>
#include <deque>
#include <vector>

using std::deque;
using std::reverse;
using std::vector;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root)
      return result;
    deque<TreeNode*> cursor;
    cursor.push_back(root);
    int direction = true;

    while (!cursor.empty()) {
      int size = cursor.size();  // 使用size固定当前层的节点
      int sum = 0;
      vector<int> levelResult;

      for (int i = 0; i < size; ++i) {
        TreeNode* current = cursor.front();
        levelResult.push_back(current->val);
        if (current->left)
          cursor.push_back(current->left);
        if (current->right)
          cursor.push_back(current->right);
        cursor.pop_front();
      }

      if (!direction) {
        reverse(levelResult.begin(), levelResult.end()); // 正反交替推入结果数组
      }
      result.push_back(levelResult);
      direction = !direction;  // 每层完了后改变方向
    }
    return result;
  }
};
// @lc code=end
