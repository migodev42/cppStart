/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;
// @lc code=start
class Solution {
   public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                     vector<int>& D) {
        unordered_map<int, int> ab_add_map;
        int result = 0;
        for (auto& a : A) {
            for (auto& b : B) {
                ++ab_add_map[a + b];
            }
        }
        for (auto& c : C) {
            for (auto& d : D) {
                result += ab_add_map[-(c + d)];
            }
        }
        return result;
    }
};
// @lc code=end
