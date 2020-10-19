#include <deque>
#include <algorithm>
#include <vector>

using std::vector;
using std::deque;
using std::sort;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        deque<int> sorted(arr.begin(),arr.end());
        auto delsize = arr.size()*0.05;
        
        while(delsize--){
            sorted.pop_front();
            sorted.pop_back();
        }
        double sum = 0.0;
        for(auto &item : sorted){
            sum+= item;
        }
        return sum/sorted.size();
    }
};