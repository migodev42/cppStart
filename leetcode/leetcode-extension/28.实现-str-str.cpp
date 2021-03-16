/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include <string>
#include <vector>

using std::string;
using std::vector;
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
    void getNext(vector<int> &next, const string &s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < next.size(); ++i) {
            while (j >= 0 && s[i] != s[j + 1]) {  // 前后缀不同了
                j = next[j];                      // 向前回溯
            }
            if (s[i] == s[j + 1]) {  // 找到相同后缀
                j++;
            }
            next[i] = j;  // 将j（前缀的长度）赋值给next[i]
        }
    }
    int strStr(string haystack, string needle) {
        if (!needle.size()) return 0;

        vector<int> next(needle.size());
        getNext(next, needle);

        /* 比较 */
        int j = -1;                                   // next数组起始为-1
        for (auto i = 0; i < haystack.size(); ++i) {  // 注意i从0开始
            while (j >= 0 && haystack[i] != needle[j + 1]) {  // 不匹配
                j = next[j];  // 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) {  // 匹配，j和i同时向后移动
                ++j;                             // i的增加在for循环里
            }
            if (j == (needle.size() - 1)) {  // 文本串出现了模式串
                return i - needle.size() + 1;
            }
        }

        return -1;
    }
};
// @lc code=end

int main(){
  Solution s;
  s.strStr("mississippi","issip");   // ""mississippi" \n"issip""
}