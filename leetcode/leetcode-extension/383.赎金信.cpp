/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

// @lc code=start
// class Solution {
//    public:
//     bool canConstruct(string ransomNote, string magazine) {
//         unordered_map<char, int> r_char_map;
//         for (auto &r : ransomNote) {
//             ++r_char_map[r];
//         }
//         for (auto &m : magazine) {
//             --r_char_map[m];
//         }
//         for (auto i = r_char_map.begin(); i != r_char_map.end(); ++i) {
//             if ((*i).second > 0) return false;
//         }
//         return true;
//     }
// };

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m_char_map;
        for (auto &m : magazine) {
            ++m_char_map[m];
        }
        for (auto &r : ransomNote) {
            --m_char_map[r];
            if (m_char_map[r] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
