/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
   public:
    int mySqrt(int x) {
        int min = 0;
        int max = x;
        int ans = -1;
        
        // 处理0的情况
        while (min <= max) {
            int mid = min + (max - min) / 2;

            // 处理数字溢出的边界情况
            if ((long long)mid * mid <= x) {
                ans = mid; // 注意ans的更新时机
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
