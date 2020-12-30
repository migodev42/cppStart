#include <vector>

using std::vector;

class Solution {
public:
    void deletion(vector<int>& target, int frompos) {
        for (int i = frompos + 1; i < target.size(); ++i) {
            target[i - 1] = target[i];
        }
    }
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int arrsize = nums.size();
        while (i < arrsize) {
            if (nums[i] == val) {
                deletion(nums, i);
                --arrsize;
            }else{
                ++i;                
            }            
        }
        nums.resize(arrsize);
        return nums.size();
    }
};