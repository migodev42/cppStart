/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
/*
  排序后比较字符串
  时间：O(nlogn) 空间：O(1)
 */
// class Solution {
//    public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) return false;
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s == t;
//     }
// };

/*
  哈希表法
  时间O(n) 空间O(n)
*/
class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> record(26, 0);
        for (auto i : s) {
            ++record[i - 'a'];
        }
        for (auto i : t) {
            --record[i - 'a'];
            if (record[i - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
