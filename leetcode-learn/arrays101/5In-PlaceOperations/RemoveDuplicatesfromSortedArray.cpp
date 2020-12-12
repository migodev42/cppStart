#include <vector>

using std::vector;

class Solution {
public:
    
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int i=0;
        int idx = 1;
        int curr=nums[0]; 
        
        while(i<nums.size()){
            if(nums[i]!=curr){
                curr = nums[i];
                nums[idx]= nums[i];
                ++idx;
            }
            ++i;
        }
        nums.resize(idx);
        return nums.size();
    }
};