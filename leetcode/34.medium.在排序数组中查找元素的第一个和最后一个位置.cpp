#include <vector>

using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // if (!nums.size()) return { -1, -1 };
        vector<int> rs = { -1 ,-1 };

        int begin = 0;
        while (begin < nums.size()) {
            if (target == nums[begin]) {
                rs[0] = begin;
                break;
            }
            ++begin;
        }
        if (begin == nums.size() - 1) {
            rs[1] = rs[0];
            return rs;
        }

        int end = rs[0];
        while (end < nums.size()) {
            if (target != nums[i]) {
                rs[1] = i - 1;
                break;
            }
            ++end;
        }
        if (end == nums.size() - 1) {
            rs[1] = nums.size() - 1;
        }
        return rs;
    }
};