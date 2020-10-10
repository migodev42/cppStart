class Solution {
public:
    int specialArray(vector<int>& nums) {
        int rs=-1;
        int cnt=0;
        for(auto x=0;x<=nums.size();++x){
            for(auto &i:nums){
                if(i>=x){
                    ++cnt;
                }
            }
            if(x==cnt){
                    rs=x;
            }
            cnt=0;
        }
        return rs;
    }
};