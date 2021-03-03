/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;
// @lc code=start
/*
  unordered_set 底层实现hash 查询时间复杂度O(1)
 */
// class Solution {
//    public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> set1;
//         unordered_set<int> set2;
//         vector<int> result;
//         for (auto& i : nums1) {
//             set1.insert(i);
//         }
//         for (auto& i : nums2) {
//             set2.insert(i);
//         }
//         for (auto i = set1.begin(); i != set1.end(); ++i) {
//             if (set2.find(*i) != set2.end()) {
//                 result.push_back(*i);
//             }
//         }
//         return result;
//     }
// };

/* 更简洁的代码实现 */
class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> tmpset(nums1.begin(), nums1.end());
        for (auto i = 0; i < nums2.size(); ++i) {
            if (tmpset.find(nums2[i]) != tmpset.end()) {
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
// @lc code=end
