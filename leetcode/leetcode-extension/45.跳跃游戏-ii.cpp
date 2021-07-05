/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
   public:
    int jump(vector<int>& nums) {
        int step = 0;
        int jump = 0;
        int nextStep = 0;
        for(int i =0 ; i<nums.size()-1; ++i){
          nextStep = max(nums[i] + i, nextStep);
          if(i==step){
            step = nextStep;
            ++jump;
          }
        }
        return jump;
    }
};
// @lc code=end
