/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3) return nums.size();
        int result = 1; 
        int cnt = 1;
        for(int i =1; i<nums.size(); ++i ){
            if(nums[i]!=nums[i-1]){
                nums[result++] = nums[i];
                cnt=1;
            }else{
                ++cnt;
                if(cnt<3){
                    nums[result++] = nums[i];
                }
            }
        }
        // 注意result++后，最后一次已经加1
        nums.resize(result);
        return nums.size();
    }
};
// @lc code=end

