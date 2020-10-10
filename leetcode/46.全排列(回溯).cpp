class Solution {
public:
    void backtrack(vector<int> nums,vector<vector<int>> &rsvec, vector<int> &onevec){
        if(nums.size()==onevec.size()){
            rsvec.push_back(onevec);
        }

        for(int i : nums){
            if(find(onevec.begin(),onevec.end(),i) != onevec.end()) continue;
            onevec.push_back(i);
            backtrack(nums,rsvec,onevec);
            onevec.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rsvec;        
        vector<int> onevec;
        backtrack(nums, rsvec, onevec);
        return rsvec;
    }
};