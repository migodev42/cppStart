/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <climits>

/* 双指针滑动窗口法 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {      
      if(!nums.size()) return 0;
      int slow = 0;
      int fast = 0;
      int result = INT_MAX;
      int sum = nums[0];
      
      while(fast<nums.size() && slow<nums.size()){        
        
        if(sum >= target){
          result = min(result, fast - slow + 1);
          sum = sum - nums[slow];
          ++slow;
        }else{
          ++fast;
          if(fast>=nums.size()) break;
          sum = sum+nums[fast];
        }
        if(fast < slow) fast = slow;
      }
      return result==INT_MAX?0:result;
    }
};
// @lc code=end

