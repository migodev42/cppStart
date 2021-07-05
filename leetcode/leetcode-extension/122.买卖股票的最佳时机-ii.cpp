/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include <limits.h>
#include <algorithm>
#include <vector>

using std::vector;
using std::max;

// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); ++i) {
            result += max(prices[i]-prices[i-1],0);
        }
        return result;
    }
};
// @lc code=end
