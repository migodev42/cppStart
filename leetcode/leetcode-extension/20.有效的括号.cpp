/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <stack>
#include <string>
#include <unordered_map>

using std::stack;
using std::string;
using std::unordered_map;

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        unordered_map<char, char> dict = {
            {'[', ']'},
            {'(', ')'},
            {'{', '}'},
        };
        stack<char> process;
        for (int i = 0; i < s.size(); ++i) {
            char curr = s[i];
            auto currpair = dict[curr];
            if (currpair) {
                process.push(currpair);
            } else if (process.empty() || process.top() != curr) {
                return false;
            } else {
                process.pop();
            }
        }

        return process.empty();
    }
};
// @lc code=end
