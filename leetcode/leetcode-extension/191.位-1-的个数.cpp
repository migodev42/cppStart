/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include <cstdint>

using std::uint32_t;

// @lc code=start
class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        // 循环检查给定整数 n 的二进制位的每一位是否为 1
        for (int i = 0; i < 32; ++i) {
            if (n & (1 << i)) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
