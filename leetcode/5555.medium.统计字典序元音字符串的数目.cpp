class Solution {
public:        
    int countVowelStrings(int n) {
        vector<int> rs = {1,1,1,1,1};
        for(int i = 0; i<n-1 ;++i){
            
            for(int idx=0; idx<5; ++idx){
                int tmp = 0;
                for(int cur=idx; cur<5; ++cur){
                    tmp += rs[cur];
                }
                rs[idx] = tmp;
                
            }
        }
        int result=0;
        for(auto item: rs){
            // cout << item << endl;
            result+=item;
        }
        return result;
    }
};