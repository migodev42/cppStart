class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        for(int i = 0; i < pieces.size(); ++i){
                auto target = find(arr.begin(), arr.end(), pieces[i][0]);                
                // cout << "pieces[i]" << pieces[i][0] << endl;
                if(pieces[i].size() == 1 && target != arr.end()) continue;
                if( target == arr.end()) return false;
                
                int idx = 0;
                while(target != arr.end() && idx < pieces[i].size()){
                    if(*target != pieces[i][idx]) return false;
                    ++target;
                    ++idx;
                }
                if(idx < pieces[i].size() && target == arr.end()) return false;
        }
        return true;
    }
};