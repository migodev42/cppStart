/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
   private:
    vector<string> letterMap = {
        "",
        ""
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    vector<string> result;
    string path;

   public:
    void backtrack(const string& digits, int index) {
        if (path.size() == digits.size()) {
            result.push_back(path);
            return;
        }

        int digit = digits[index] - '0';        // string 转 int
        string letters = letterMap[digit - 1];  // 取当前数字对应字符集
        for (int i = 0; i < letters.size(); ++i) {
            path.push_back(letters[i]);  // 处理
            backtrack(
                digits,
                index + 1);  // 递归，注意index+1，一下层要处理下一个数字了
            path.pop_back();  // 回溯
        }
    }
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return result;
        backtrack(digits, 0);
        return result;
    }
};
// @lc code=end
