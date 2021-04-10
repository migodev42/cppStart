/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */
#include <vector>
#include <climits>
#include <algorithm>
#include <utility>


using std::max;
using std::vector;
using std::pair;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

    pair<int,int> findmax(vector<int>& nums){
      int maxval = INT8_MIN;
      int idx=0;
      for(int i=0; i<nums.size();++i){
        if(nums[i]>maxval){
          maxval = nums[i];
          idx = i;
        }        
      }
      return {idx, maxval};
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      if(nums.empty()) return nullptr;
      
      pair<int,int> curr = findmax(nums);
      TreeNode* root = new TreeNode(curr.second);
      if(nums.size()==1) return root;

      vector<int> l_nums(nums.begin(),nums.begin()+curr.first);
      vector<int> r_nums(nums.begin()+curr.first+1,nums.end());
      root->left = constructMaximumBinaryTree(l_nums);
      root->right= constructMaximumBinaryTree(r_nums);
      return root;
    }
};
// @lc code=end

