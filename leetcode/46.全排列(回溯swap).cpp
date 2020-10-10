class Solution {
public:
    void backtrack(vector<int> &nums,vector<vector<int>> &rsvec, int curidx){
        if(curidx==nums.size()-1){
            rsvec.push_back(nums);
            return;
        }
        for(auto i=curidx; i<nums.size(); ++i){            
            swap(nums[i], nums[curidx]);
            backtrack(nums, rsvec, curidx+1);
            swap(nums[i], nums[curidx]);
        } 
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rsvec;        
        backtrack(nums, rsvec, 0);
        return rsvec;
    }
};