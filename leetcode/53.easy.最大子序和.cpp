#include <vector>

using std::vector;

/* 动态规划 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int maxAns = nums[0];
        for(int i=0; i< nums.size(); ++i){
            pre = max(nums[i], pre+nums[i]);
            maxAns= max(maxAns, pre);
        }
        return maxAns;
    }
};

/* 贪心算法 */
