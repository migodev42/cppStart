/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include <string>
#include <vector>

using std::vector;
using std::string;
// @lc code=start
/* 暴力穷举法:超过时间限制 */
// class Solution {
//    public:
//     int strStr(string haystack, string needle) {
//         if (!needle.size()) return 0;
//         int cursor = 0;
//         while (cursor < haystack.size()) {
//             int cursor_h = cursor;
//             int cursor_n = 0;
//             while (cursor_n < needle.size() && cursor_h < haystack.size()) {
//                 if (haystack[cursor_h] != needle[cursor_n])
//                     break;
//                 else {
//                     ++cursor_h;
//                     ++cursor_n;
//                 }
//             }
//             if (cursor_n == needle.size()) return cursor;
//             ++cursor;
//         }
//         return -1;
//     }
// };


/* KMP算法 */
class Solution {
   public:
    void getNext(vector<int> &next, const string &s){

    }
    int strStr(string haystack, string needle) {
        if (!needle.size()) return 0;
        int cursor = 0;

        vector<int> next(needle.size());
        return -1;
    }
};
// @lc code=end
