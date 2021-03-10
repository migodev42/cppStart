/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <algorithm>
#include <string>

using std::string;
using std::swap;
// @lc code=start
class Solution {
   public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (i < s.size()) {
            int left = i;
            int right = i + k - 1;  // 左闭右闭
            if (right >= s.size() - 1) {
                right = s.size() - 1;
            }
            while (left < right) {
                swap(s[left], s[right]);
                ++left;
                --right;
            }
            i += 2 * k;
        }
        return s;
    }
};
// @lc code=end
