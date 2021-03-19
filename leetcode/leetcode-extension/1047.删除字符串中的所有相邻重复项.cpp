/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <algorithm>
#include <stack>
#include <string>

using std::reverse;
using std::stack;
using std::string;

// @lc code=start
class Solution {
   public:
    string removeDuplicates(string S) {
        stack<char> cStack;
        for (auto s : S) {
            if (cStack.empty() || cStack.top() != s) {
                cStack.push(s);
            } else {
                cStack.pop();
            }
        }
        string result = "";
        while (!cStack.empty()) {
            result += cStack.top();
            cStack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
