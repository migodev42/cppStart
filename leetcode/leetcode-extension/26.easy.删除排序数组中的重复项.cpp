/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

 // @lc code=start
#include <vector>

using std::vector;

/* 
  每遇到重复的就删除并移动
  时间复杂度O(n^2) 空间复杂度O(1)
*/
// class Solution {
// public:
//   void move(vector<int>& nums,int target){
//     for(int i=target;i<nums.size()-1;++i){
//       nums[i] = nums[i+1];
//     }    
//   }
//   int removeDuplicates(vector<int>& nums) {    
//     if(!nums.size()) return nums.size();

//     int prev = nums[0];
//     int i = 1;
//     int remove = 0;
//     while (i < nums.size()-remove) {
//       if(nums[i]!=prev){
//         prev = nums[i];
//         ++i;
//       }else{
//         move(nums,i);
//         ++remove;
//       }
//     }
//     nums.resize(nums.size()-remove);
//     return nums.size();

//   }
// };


/* 
  双指针法，快慢两个指针，快指针负责读取重复项，慢指针存放唯一值
  时间复杂度O(n) 空间复杂度O(1)
*/
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {    
    if(!nums.size()) return nums.size();
        
    int slow = 0;
    for(int fast=1; fast<nums.size(); ++fast){
      if(nums[slow]!=nums[fast]){        
        ++slow;
        nums[slow] = nums[fast];
      }
    }
    nums.resize(slow+1);
    return nums.size();

  }
};
// @lc code=end

