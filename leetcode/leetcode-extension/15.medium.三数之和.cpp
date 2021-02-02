/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

 // @lc code=start
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
// 排序+双指针
// 时间复杂度O(N^2)+O(nlgn),即O(N^2)
// 空间复杂度：O(logN)。我们忽略存储答案的空间，额外的排序的空间复杂度为 O(logN)。
// 然而我们修改了输入的数组 nums，在实际情况下不一定允许，
// 因此也可以看成使用了一个额外的数组存储了 nums 的副本并进行排序
// 空间复杂度为O(N)

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int one = 0; one < n; ++one) {
      // 需要和上一次枚举的数不相同
      if (one > 0 && nums[one] == nums[one - 1]) {
        continue;
      }
      int three = n - 1;
      int target = -nums[one];
      for (int two = one + 1; two < n; ++two) {
        // 需要和上一次枚举的数不相同
        if (two > one + 1 && nums[two] == nums[two - 1]) {
          continue;
        }

        // 需要保证2的指针在3的指针的左侧
        while (two < three && nums[two] + nums[three] > target) {
          --three;
        }
        // 如果指针重合，随着 b 后续的增加
        // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
        if (two == three) {
            break;
        }
        if (nums[two] + nums[three] == target) {
            ans.push_back({nums[one], nums[two], nums[three]});
        }
      }
    }
    return ans;
  }
};
// @lc code=end

