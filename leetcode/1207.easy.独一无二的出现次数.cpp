#include <map>
#include <vector>

using std::map;
using std::vector;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> cnt;
        for(int i=0;i<arr.size();++i){
            ++cnt[arr[i]];
        }
        map<int,int>  cnt_cnt;
        for(auto beg=cnt.begin(); beg!=cnt.end();++beg){
            int accured =beg->second;
            ++cnt_cnt[accured];        
            if(cnt_cnt[accured]>1) return false;
        }
        return true;
    }
};