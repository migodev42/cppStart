#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        char last = s[0];
        int lastidx = 0;
        int cnt = 1;        
        for(int i = 1; i < s.size(); ++i){
            if(s[i]==last){
                ++cnt;
            }else{
                if(cnt>=3){
                    result.push_back({lastidx, i-1});
                }
                last = s[i];
                lastidx = i;
                cnt = 1;
            }
        }
        if(cnt>=3){
            int idx = s.size()-1;
            result.push_back({lastidx, idx});
        }
        return result;
    }
};