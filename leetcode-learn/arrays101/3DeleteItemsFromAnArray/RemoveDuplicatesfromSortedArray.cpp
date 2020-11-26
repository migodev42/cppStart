class Solution {
public:
    void remove(vector<int>& nums, int pos){
        for(int i= pos+1; i<nums.size();++i){
            nums[i-1] = nums[i];
        }
        nums.resize(nums.size()-1);
    }
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int i=1;
        int curr=nums[0]; 
        while(i<nums.size()){
            if(nums[i]==curr){
                remove(nums,i);
            }else{
                curr = nums[i];
                ++i;
            }
        }
        return nums.size();
    }
};