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
    unordered_map<char, vector<char>> numberMaps = {
        // {'a', 2}, {'b', 2}, {'c', 2}, {'d', 3}, {'e', 3}, {'f', 3},
        // {'g', 4}, {'h', 4}, {'i', 4}, {'j', 5}, {'k', 5}, {'l', 5},
        // {'m', 6}, {'n', 6}, {'o', 6}, {'p', 7}, {'q', 7}, {'rs', 7},
        // {'t', 8}, {'u', 8}, {'v', 8}, {'w', 9}, {'x', 9}, {'yz', 9},
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
    };
    vector<vector<char>> targetMap;
    vector<string> result;
    int size = 0;

   public:
    void backtrack(string curr) {
        if (curr.size() == size) {
            result.push_back(curr);
            return;
        }

        for (int i = curr.size(); i <= size; ++i) {
            backtrack(curr + targetMap[i][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        size = digits.size();

        for (char digit : digits) {
            targetMap.push_back(numberMaps[digit]);
        }
        backtrack();

        /* 打印selectTarget */
        // int cnt = 0;
        // for(auto item : targetMap){
        //   cout << digits[cnt++] << " : 当前数字";
        //   for(auto i : item){
        //     cout <<  i << " ";
        //   }
        //   cout << endl;
        // }

        return result;
    }
};
// @lc code=end
