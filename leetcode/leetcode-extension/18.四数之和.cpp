/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

// @lc code=start
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());

        for (int first = 0; first < nums.size(); ++first) {

            /* 跳过相同的first */
            if (first > 0 && nums[first] == nums[first - 1]) continue;

            for (int second = first + 1; second < nums.size(); ++second) {

                /* 跳过相同的second */
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;

                int fourth = nums.size()-1;

                for (int third = second + 1; third < nums.size(); ++third) {

                    /* 跳过相同的third */
                    if (third > second+1 && nums[third] == nums[third - 1])
                        continue;

                    /* 移动fourth指针 */
                    while (third < fourth && nums[first] + nums[second] +
                                                     nums[third] +
                                                     nums[fourth] >
                                                 target) {
                        --fourth;
                    }

                    if (third == fourth) break;
                    if (nums[first] + nums[second] + nums[third] +
                            nums[fourth] ==
                        target) {
                        result.push_back({nums[first], nums[second],
                                          nums[third], nums[fourth]});
                    }
                }
            }
        }

        return result;
    }
};
// @lc code=end
