#include <vector>

using std::vector;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 两边遍历
        // 第一遍按abs(下标)标记为负数
        // 第二遍判断不为负数的数字即为消失的数字
        for(int i=0;i<nums.size();++i){
            int curr = abs(nums[i])-1;
            if(nums[curr]>0) nums[curr] = -nums[curr];
        }
        
        vector<int> result;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0) result.push_back(i+1);
        }
        return result;
    }
};