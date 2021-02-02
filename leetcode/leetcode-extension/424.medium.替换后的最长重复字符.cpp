/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>

using std::max;
using std::vector;
using std::string;

// 双指针
// 时间复杂度 O(n)
// 空间复杂度 O(|E|)
/* 
我们可以枚举字符串中的每一个位置作为右端点，然后找到其最远的左端点的位置，满足该区间内除了出现次数最多的那一类字符之外，剩余的字符（即非最长重复字符）数量不超过 k 个。
这样我们可以想到使用双指针维护这些区间，每次右指针右移，如果区间仍然满足条件，那么左指针不移动，否则左指针至多右移一格，保证区间长度不减小。
虽然这样的操作会导致部分区间不符合条件，即该区间内非最长重复字符超过了 kk 个。但是这样的区间也同样不可能对答案产生贡献。当我们右指针移动到尽头，左右指针对应的区间的长度必然对应一个长度最大的符合条件的区间。
实际代码中，由于字符串中仅包含大写字母，我们可以使用一个长度为 2626 的数组维护每一个字符的出现次数。每次区间右移，我们更新右移位置的字符出现的次数，然后尝试用它更新重复字符出现次数的历史最大值，最后我们使用该最大值计算出区间内非最长重复字符的数量，以此判断左指针是否需要右移即可。
 */
class Solution {
public:
    int characterReplacement(string s, int k) {
      vector<int> num(26);
      int n = s.size();
      int maxn = 0; // 最大长度
      int left = 0, right = 0;  // 两个指针
      while(right<n){
        num[s[right]-'A']++;
        maxn = max(maxn, num[s[right]-'A']);
        if(right - left +1 - maxn>k){
          num[s[left]-'A']--;
          left++;
        }
        right++;
      }
      return right - left;
    }    
};
// @lc code=end

