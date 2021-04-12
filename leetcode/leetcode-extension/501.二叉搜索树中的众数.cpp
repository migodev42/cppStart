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
  void compareCnt(int cnt, int val) {
    if (cnt > maxcnt) {
      result.clear();
      result.push_back(val);
    }
    else if (cnt == maxcnt) {
      result.push_back(val);
    }
  }
  TreeNode* prev = nullptr;
  int cnt = 0;
  int maxcnt = 0;
  void traversal(TreeNode* curr) {
    if (!curr) return;
    traversal(curr->left);
    if (prev) {
      // bool isLeaf = !curr->left && !curr->right;
      int prevval = prev->val;
      int currval = curr->val;

      // if(isLeaf){
      //   compareCnt(cnt,)
      // } 

      if (prevval != currval) {
        if (cnt > maxcnt) {
          maxcnt = cnt;
          result.clear();
          result.push_back(currval);
          cnt = 0;
        }
        else if (cnt == maxcnt) {
          result.push_back(currval);
        }

      }
      else {

      }
    }else{
      cnt = 1;
    }


    if (prev) {
      cout << prev->val;
    }
    else {
      cout << "x";
    }
    prev = curr;
    cout << " " << curr->val << endl;
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

