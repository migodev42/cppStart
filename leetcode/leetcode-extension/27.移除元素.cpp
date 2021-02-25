/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

 // @lc code=start
class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    if (!nums.size()) return 0;
    int slow = -1;
    for (int fast = 0;fast < nums.size(); ++fast) {
      if (nums[fast] != val) {
        ++slow;
        nums[slow] = nums[fast];
      }
    }
    nums.resize(slow + 1);
    return nums.size();

  }
};
// @lc code=end

