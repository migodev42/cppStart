#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (!nums.size()) return 0;
        if (nums.size() == 1) return nums[0] == 1 ? 1 : 0;
        int maxrs = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                cnt = 0;
            }
            else {
                ++cnt;
            }
            maxrs = max(maxrs, cnt);
        }
        return maxrs;
    }
};