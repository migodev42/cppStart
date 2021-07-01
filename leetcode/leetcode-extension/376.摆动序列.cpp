/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include <vector>
#include <algorithm>

using std::max;
using std::vector;

// @lc code=start
class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    int currDiff = 0; 
    int prevDiff = 0;
    int result = 1;    
    for (int i = 0; i < nums.size()-1; ++i) {
      currDiff = nums[i + 1] - nums[i];
      if((currDiff > 0 && prevDiff <= 0) || (currDiff < 0 && prevDiff >= 0)){
        result++;
        prevDiff = currDiff;
      }
    }

    return result;
  }
};
// @lc code=end
