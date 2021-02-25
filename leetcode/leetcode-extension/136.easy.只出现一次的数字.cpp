/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

 // @lc code=start

/* 
  异或运算，相异为真，相同为假，所以 a^a = 0 ;0^a = a 
  将每一项拼起来进行异或运算，结果即为只出现一次的数字
  时间复杂度O(n) 空间复杂度O（1）
*/
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int result = 0;
    for (auto i : nums) {
      result = result ^ i;
    }
    return result;
  }
};

/* 
  hash表存储出现次数,返回为1的数字
  时间复杂度O(n) 空间复杂度O（n）
*/

// @lc code=end

