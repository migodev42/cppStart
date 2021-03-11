/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include <algorithm>
#include <string>

using std::string;
using std::swap;

// @lc code=start
class Solution {
   public:
    string reverseWords(string s) {
        /* 去首尾空格 */
        int left = 0;
        int right = s.size() - 1;
        while (left < s.size() && s[left] == ' ') {
            ++left;
        }
        while (right >= 0 && s[right] == ' ') {
            --right;
        }
        int result = 0;
        int cursor = left;
        /* 去除中间空格并swap */
        while (cursor <= right) {
            if (s[cursor] == ' ' && s[cursor + 1] == ' ') {
                ++cursor;
            } else {
                swap(s[result++], s[cursor++]);
            }
        }
        // 由于result在最后一次swap时候进行了++，所以resize的是result而不是result+1
        s.resize(result);

        /* 反转整个字符串 */
        left = 0;
        right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }

        /* 反转单词 */
        cursor = 0;
        while (cursor < s.size()) {
            int wordleft = cursor;
            int wordright = cursor;
            while (s[wordright] != ' ' && wordright < s.size()) {
                ++wordright;
            }
            cursor = wordright + 1;
            wordright = wordright - 1;
            // cout << wordleft << " " << wordright;
            while (wordleft < wordright) {
                swap(s[wordleft++], s[wordright--]);
            }
        }
        return s;
    }
};
// @lc code=end
