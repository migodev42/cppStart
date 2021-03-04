/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include <algorithm>
#include <vector>

using std::swap;
using std::vector;

// @lc code=start
class Solution {
   public:
    void reverseString(vector<char>& s) {
        if (s.size() < 2) return;
        int slow = 0;
        int fast = s.size() - 1;
        while (slow < fast) {
            // int tmp = s[slow];
            // s[slow] = s[fast];
            // s[fast] = tmp;
            swap(s[slow], s[fast]);
            ++slow;
            --fast;
        }
    }
};
// @lc code=end
