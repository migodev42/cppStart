/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

#include <cmath>
#include <unordered_set>
#include <vector>

using std::pow;
using std::unordered_set;
// @lc code=start
class Solution {
   public:
    int getResult(int number) {
        int result = 0;
        while (number > 0) {
            result += pow(number % 10, 2);
            number = number / 10;
        }
        return result;
    }
    bool isHappy(int n) {
        unordered_set<int> repeat_once;
        while (1) {
            n = getResult(n);
            if (n == 1) {
                return true;
            } else if (repeat_once.find(n) != repeat_once.end()) {
                return false;
            } else {
                repeat_once.insert(n);
            }
        }
    }
};
// @lc code=end
