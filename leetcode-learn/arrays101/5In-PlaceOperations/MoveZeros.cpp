#include <vector>
using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <=1) return ;
        int i =0;
        int move = 1;
        while(i<nums.size() && move <nums.size()){
            if(nums[i]==0){
                int tmp = nums[i];
                int j = i+1;
                if(nums[j]==0){
                    --i;
                }
                while(j<nums.size()){
                    nums[j-1] = nums[j];
                    ++j;
                }
                nums[nums.size()-1] = tmp;                
            }    
            cout << i << move;
            ++i;
            ++move;
        }
    }
};