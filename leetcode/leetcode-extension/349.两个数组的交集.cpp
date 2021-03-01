/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include <unordered_map>

using std::unordered_map;
// @lc code=start
class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> same;
        vector<int> result;
        for (auto& i : nums1) {
            same[i]++;
        }
        for (auto& i : nums2) {
            same[i]++;
        }
        for (auto& i : same) {
            if (i.second > 1) {
                result.push_back(i.first);
            }
        }
        return result;
    }
};
// @lc code=end
