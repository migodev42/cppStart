/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;

        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size(); ++first) {
            /* 跳过不符合的值 */
            if (nums[first] > 0) continue;

            /* 跳过相同的first */
            if (first != 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int third = nums.size() - 1;
            int target = -nums[first];
            // https://leetcode-cn.com/problems/3sum/solution/san-shu-zhi-he-by-leetcode-solution/
            // 也就是说，我们可以从小到大枚举b，同时从大到小枚举c,即第二重循环和第三重循环实际上是并列的关系。
            // 有了这样的发现，我们就可以保持第二重循环不变，而将第三重循环变成一个从数组最右端开始向左移动的指针

            // 这个方法就是我们常说的「双指针」，当我们需要枚举数组中的两个元素时，如果我们发现随着第一个元素的递增，第二个元素是递减的，那么就可以使用双指针的方法，将枚举的时间复杂度从
            // O(N^2) 减少至 O(N)。为什么是 O(N)
            // 呢？这是因为在枚举的过程每一步中，「左指针」会向右移动一个位置（也就是题目中的
            // bb），而「右指针」会向左移动若干个位置，这个与数组的元素有关，但我们知道它一共会移动的位置数为
            // O(N)，均摊下来，每次也向左移动一个位置，因此时间复杂度为 O(N)。

            for (int second = first + 1; second < nums.size(); ++second) {
                /* 跳过相同的second */
                if (second != first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                /* 调整第二个数的同时，调整第三个数 */
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    result.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return result;
    }
};
// @lc code=end
