/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::vector;

// @lc code=start
// class Solution {
//    public:
//     bool canJump(vector<int>& nums) {
//         int left = nums[0];
//         int step = 0;
//         while (left) {
//             if (step >= nums.size() - 1) return true;
//             step++;
//             if (nums[step] >= left) {
//                 left = nums[step];
//             } else {
//                 left--;
//             }

//         }
//         return step >= nums.size() - 1;
//     }
// };

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true; // 只有一个元素，就是能达到
        int cover = 0;
        for (int i = 0; i <= cover; ++i) { // 注意这里是小于等于cover
            cover = max(nums[i] + i, cover);
            if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
        }
        return false;
    }
};
// @lc code=end
