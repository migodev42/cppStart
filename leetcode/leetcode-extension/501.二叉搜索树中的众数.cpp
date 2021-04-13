/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */
#include <vector>

using std::vector;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// @lc code=start
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
class Solution {
public:
  vector<int> result;
  TreeNode* prev = nullptr;
  int cnt = 1;
  int maxcnt = 0;
  void traversal(TreeNode* curr) {
    if (!curr) return;
    traversal(curr->left);

    if (!prev) {
      cnt = 1;
    }
    else if (prev->val == curr->val) {
      cnt++;
    }
    else {
      cnt = 1;
    }
    prev = curr;
    if (cnt > maxcnt) {
      result.clear();
      result.push_back(curr->val);
      maxcnt = cnt;
    }
    else if (cnt == maxcnt) {
      result.push_back(curr->val);
    }
    
    traversal(curr->right);

  }
  vector<int> findMode(TreeNode* root) {
    traversal(root);
    return result;
  }
};
// @lc code=end

// 叶子节点

// 非叶子节点

// 当前与前一个值不同
// 比较当前cnt和maxcnt 
  //  大 清空result result推入前一个
  //  相等 result推入前一个
  //  小
//  cnt归零


// 当前与前一个值相同
// 1

// 2

// 2

// null 1
// 1  2
// 2  2

